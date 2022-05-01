#include "../../include/cdg/cdg.hpp"
#include "../../include/line_type.hpp"

CDG::CDG(Node* lines) {
    this->lines = lines;
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
}
