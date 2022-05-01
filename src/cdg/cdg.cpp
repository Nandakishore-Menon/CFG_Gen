#include<iostream>
#include "../../include/cdg/cdg.hpp"
#include "../../include/line_type.hpp"
#include "../../include/linked_list/list_ops.hpp"

CDG::CDG(Node* lines) {
    this->lines = lines;
    generate(NULL, this->lines, true);
    printListRec(this->lines);
    /*
    Node* current_line = this->lines;
    while(current_line != NULL) {
        switch (current_line->line_type)
        {
        case BLOCK:
            // Next will be the next line itself
            break;
        
        case IF:
        case ELSEIF:
        case ELSE:
        case FOR:
        case WHILE:
            Node* line_child = current_line->child;
            line_child = current_line->next;
            line_child->parent = current_line;
            if (!current_line->multiline) {
                current_line->next = line_child->next;
                line_child->next = NULL;
            }
            break;
        case CLOSEBRACE:

        default:
            break;
        }
    }
    */
}
Node* CDG::generate(Node* prev, Node* current, bool multiline_block) {
/*bool multiline_block indicates if the current line is part of a multiline block.
Returns the next line after the block that satrts with the current line
*/
    Node* current_line = current;
    // std::cout << "Current line: " << *current_line;
    if (current_line->next == NULL) {
        return NULL;
    }
    switch (current_line->line_type)
    {
    case EXPRESSION:
        // return current_line->next;
        if (multiline_block)
            return generate(current, current_line->next, multiline_block);
        else
            return current_line->next;
        break;
    
    case IF:
    case ELSEIF:
    case ELSE:
    case FOR:
    case WHILE:
    {
        // std::cout<< "--------------Going into conditionals\n";
        Node* line_child = current_line->next;
        current_line->child = line_child;
        line_child->parent = current_line;
        Node* line_next = generate(current, line_child, current_line->multiline);
        if (!current_line->multiline)
            return line_next;
        current_line->next = line_next;
        line_next->prev = current_line;
        return generate(current, line_next, multiline_block);
        break;
    }
    case CLOSEBRACE:
    {
        Node* line_next = current_line->next;
        current_line->next = NULL;
        return line_next;
        break;
    }
    default:
        break;
    }
}