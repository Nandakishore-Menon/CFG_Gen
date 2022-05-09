#include "../../include/cfg/cfg.hpp"

CFG::CFG(Node* head) {
    cdg = head;
}

std::vector<Node*> CFG::CFG_gen(Node* current) {
    // returns all loopback nodes that might be needed by higher blocks
    Node* current_line = current;
    std::cout<<*current_line;
    switch (current_line->line_type)
    {
        case OPENBRACE:
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
            if(line_next == NULL || line_next->line_type == CLOSEBRACE) {
                loopbacks.push_back(current_line);      
            }
            while(line_next != NULL && (line_next->line_type == ELSEIF || line_next->line_type == ELSE)) {
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
                std::cout << "\n-------loopback" << *current_line << " start----------\n";
                std::cout << "\nnext: " << *line_next << " ----------\n";
                for(auto& l: loopbacks) {
                    std::cout << *l << "\n-----------------\n";
                    l->next = line_next;
                }
                std::cout << "\n-------loopback end----------\n";
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
            if (line_child == NULL) {
                // empty case statement
                std::cout << "empty case--------\n";
                Node* next_case = current_line->next;
                while (next_case->child == NULL) {
                    next_case = next_case->next;
                }
                current_line->child = next_case->child;
                return CFG_gen(current_line->next);
            }
            std::vector<Node*> loopbacks = CFG_gen(line_child);
            for(int i = 0; i < loopbacks.size(); i++) {
                Node* l = loopbacks[i];
                if(l->line_type != BREAK) {
                    if(current_line->next != NULL && current_line->next->line_type != CLOSEBRACE) {
                        l->next = current_line->next;
                        loopbacks.erase(i + loopbacks.begin());
                    }
                }
                else {
                    l->line_type = EXPRESSION;
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

void CFG::createDot(Node* current, std::set<int>& st, std::set<int>& file_stack, std::fstream& fio) {
    if(current == NULL) {
        return;
    }

    std::cout << *current ;
    if (current->next)
        std::cout << "Next:" << *(current->next);
    else
        std::cout << "Next: NULL";
    if (current->child)
        std::cout << "Child" << *(current->child);
    else
        std::cout << "Child: NULL\n";
    std::cout << "\n--------------------------------\n";
    if(file_stack.find(current->ID) == file_stack.end()) {
        fio << " " << current->ID << " [label=\"" << current->code << "\"];\n";
        file_stack.insert(current->ID);
    }
    if(current->child != NULL && file_stack.find(current->child->ID) == file_stack.end()) {
        fio << " " << current->child->ID << " [label=\"" << current->child->code << "\"];\n";
        file_stack.insert(current->child->ID);
    }
    if(current->next != NULL && file_stack.find(current->next->ID) == file_stack.end()) {
        fio << " " << current->next->ID << " [label=\"" << current->next->code << "\"];\n";
        file_stack.insert(current->next->ID);
    }
    if(current->child != NULL) {
        fio << " " << current->ID << " -> " << current->child->ID;
        if(current->line_type == IF || current->line_type == ELSEIF) {
            fio << " [label= \"true\" color=\"green\" fontcolor=\"green\"]";
        }
        fio << ";\n";
    }
    if(current->next != NULL) {
        fio << " " << current->ID << " -> " << current->next->ID;
        if(current->line_type == IF || current->line_type == ELSEIF) {
            fio << " [label= \"false\" color=\"red\" fontcolor=\"red\"]";
        }
        if(current->next->line_type == FOR || current->next->line_type == WHILE) {
            if(st.find(current->next->ID) != st.end())
                fio << " [label= \"end loop\"]";
        }
        fio << ";\n";
    }
    st.insert(current->ID);
    if(current->child != NULL && st.find(current->child->ID) == st.end()) {
        createDot(current->child, st, file_stack, fio);
    }
    if(current->next != NULL && st.find(current->next->ID) == st.end()) {
        createDot(current->next, st, file_stack, fio);
    }
}