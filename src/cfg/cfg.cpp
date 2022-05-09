#include "../../include/cfg/cfg.hpp"

int CFG::idIncrement() {
    return id_count++;
}

void CFG::idReset() {
    id_count = 1;
}

CFG::CFG(Node* head) {
    idReset();
    cdg = head;
}

std::vector<Node*> CFG::CFG_gen(Node* current) {
    // returns all loopback nodes that might be needed by higher blocks
    Node* current_line = current;
    switch (current_line->line_type)
    {
        case EXPRESSION: {
            if(current_line->next == NULL || current_line->next->line_type == CLOSEBRACE) {
                std::vector<Node*> loopbacks;
                loopbacks.push_back(current_line);
                return loopbacks;
            }
            return CFG_gen(current_line->next);

        }
        case IF: {
            Node* line_child = current_line->child;
            std::vector<Node*> loopbacks = CFG_gen(line_child);
            Node* line_next = current_line->next;
            while(line_next->line_type == ELSEIF || line_next->line_type == ELSE) {
                if(line_next->child != NULL) {
                    std::vector<Node*> next_loopbacks = CFG_gen(line_next->child);
                    loopbacks.insert(loopbacks.end(), next_loopbacks.begin(), next_loopbacks.end());
                }
                line_next = line_next->next;
            }
            if(line_next == NULL || line_next->line_type == CLOSEBRACE) {
                return loopbacks;
            }
            else {
                for(auto& l: loopbacks) {
                    l->next = line_next;
                }
                return CFG_gen(line_next);
            }
            break;
        }
        case CONTINUE:
        case BREAK: {
            std::vector<Node*> loopback;
            loopback.push_back(current_line);
            return loopback;
            break;
        }
        case FOR:
        case WHILE: {
            Node* line_child = current_line->child;
            std::vector<Node*> loopbacks = CFG_gen(line_child);
            for(auto& l: loopbacks) {
                if(l->line_type == BREAK) {
                    l->next = current_line->next;
                }
                else
                    l->next = current_line;
            }
            if(current_line->next != NULL && current_line->next->line_type != CLOSEBRACE) {
                return CFG_gen(current_line->next); 
            }
            std::vector<Node*> next_loopbacks;
            next_loopbacks.push_back(current_line);
            return next_loopbacks;
            break;
        }
        case DEFAULT:
        case CASE: {
            Node* line_child = current_line->child;
            std::vector<Node*> loopbacks = CFG_gen(line_child);
            for(int i = 0; i < loopbacks.size(); i++) {
                Node* l = loopbacks[i];
                if(l->line_type != BREAK) {
                    if(current_line->next != NULL && current_line->next->line_type != CLOSEBRACE) {
                        l->next = current_line->next;
                        loopbacks.erase(i + loopbacks.begin());
                    }

                }
            }
            if(current_line->next != NULL && current_line->next->line_type != CLOSEBRACE) {
                std::vector<Node*> next_loopbacks = CFG_gen(current_line->next);
                loopbacks.insert(loopbacks.end(), next_loopbacks.begin(), next_loopbacks.end());
            }
            return loopbacks;
            break;

        }
        case SWITCH: {
            Node* line_child = current_line->child;
            std::vector<Node*> loopbacks = CFG_gen(line_child);
            if(current_line->next == NULL || current_line->next->line_type == CLOSEBRACE) {
                return loopbacks;
            }
            for(auto& l: loopbacks) {
                l->next = current_line->next;
            }
            std::vector<Node*> next_loopbacks;
            return next_loopbacks;
        }
        case CLOSEBRACE: 
        default: {
            std::vector<Node*> loopback;
            return loopback;
            break;
        }

    }
}