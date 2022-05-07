#include<iostream>
#include "../../include/cdg/cdg.hpp"
#include "../../include/line_type.hpp"
#include "../../include/linked_list/list_ops.hpp"

CDG::CDG(Node* lines) {
    this->lines = lines;
    generate(NULL, this->lines, true);
    printListRec(this->lines);
}

Node* CDG::generate(Node* prev, Node* current, bool multiline_block) {
/*bool multiline_block indicates if the current line is part of a multiline block.
Returns the next line after the block that satrts with the current line
*/
    Node* current_line = current;
    // std::cout << "\nCurrent line: " << *current_line;
    if (current_line->next == NULL) {
        return NULL;
    }
    switch (current_line->line_type)
    {
    case EXPRESSION:
    case BREAK:
    case CONTINUE:
    case RETURN:
    {
        // return current_line->next;
        if (multiline_block) {
            // std::cout << "test1\n";getchar();
            return generate(current, current_line->next, multiline_block);
        }
        else {
            // std::cout << "test2\n";getchar();
            Node* line_next = current_line->next;
            current_line->next = NULL;
            return line_next;
        }
        break;
    }
    case IF:
    case ELSEIF:
    {
        // std::cout<< "--------------Going into conditionals\n";
        Node* line_child = current_line->next;
        current_line->child = line_child;
        line_child->parent = current_line;
        Node* line_next = generate(current, line_child, current_line->multiline);
        if (line_next == NULL) {
            current_line->next = NULL;
            return NULL;
        }
        // std::cout << "Current line: ..." << *current_line;
        // std::cout << "Possible next line: ..." << *line_next << std::endl; 
        if (multiline_block || line_next->line_type == ELSEIF || line_next->line_type == ELSE) {
            // Then this block is not the last in the current block
            // Next block will belong to the current block itself
            current_line->next = line_next;
            line_next->prev = current_line;
            return generate(current, line_next, multiline_block);
        }
        else {
            // Then this block is the last in the current block
            // Next block will belong to the outer blocks
            current_line->next = NULL;
            return line_next;
        }
        break;
    }
    case ELSE:
    case FOR:
    case WHILE:
    case SWITCH: //multiline always true
    {
        // std::cout<< "--------------Going into conditionals\n";
        Node* line_child = current_line->next;
        current_line->child = line_child;
        line_child->parent = current_line;
        Node* line_next = generate(current, line_child, current_line->multiline);
        if (line_next == NULL) {
            current_line->next = NULL;
            return NULL;
        }
        // std::cout << "Current line: ..." << *current_line;
        // std::cout << "Possible next line: ..." << *line_next << std::endl; 
        if (multiline_block) {
            // Then this block is not the last in the current block
            // Next block will belong to the current block itself
            current_line->next = line_next;
            line_next->prev = current_line;
            return generate(current, line_next, multiline_block);
        }
        else {
            // Then this block is the last in the current block
            // Next block will belong to the outer blocks
            current_line->next = NULL;
            return line_next;
        }
        break;
    }
    case CASE:
    case DEFAULT:
    {
        Node* line_child = current_line->next;

        // For combined case statements
        if (line_child->line_type == CASE || line_child->line_type == DEFAULT || line_child->line_type == CLOSEBRACE)
            return generate(prev, line_child, multiline_block);
        
        current_line->child = line_child;
        line_child->parent = current_line;
        Node* line_next = generate(current, line_child, current_line->multiline);
        // line_next cannot be NULL here, because switch is always multiline, i.e. line_next has to be '}' atleast
        
        // Everything until the next case/default statement is child of current case/default
        while (line_next->line_type != CASE && line_next->line_type != DEFAULT && line_next->line_type != CLOSEBRACE) {
            line_child->next = line_next;
            line_next->prev = line_child;
            line_child = line_next;
            line_next = generate(current, line_child, current_line->multiline);
            // line_next cannot be NULL here, because switch is always multiline, i.e. line_next has to be '}' atleast
        }
        
        current_line->next = line_next;
        line_next->prev = current_line;
        return generate(prev, line_next, multiline_block);
    }
    case OPENBRACE:
    {
        Node* line_next = current_line->next;
        return generate(prev, line_next, true);
    }
    case CLOSEBRACE:
    {
        Node* line_next = current_line->next;
        current_line->next = NULL;
        // std::cout<<"-----"<< *(current_line->prev) <<"---closing returning..." << *line_next;
        return line_next;
        break;
    }
    default:
        return NULL;
        break;
    }
}