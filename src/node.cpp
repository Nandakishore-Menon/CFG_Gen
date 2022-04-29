#include <iostream>
#include "../include/node.hpp"

Node::Node(int ID, std::string code, int line_type, bool multiline) {
    this->ID = ID;
    this->code = code;
    this->line_type = line_type;
    this->multiline = multiline;
    this->elseused = false;
    this->next = NULL;
    this->prev = NULL;
    this->child = NULL;
    this->parent = NULL;
}

std::ostream& operator<< (std::ostream& out, const Node& node) {
    out << "{ID: " << node.ID << ", Code: " << node.code << ", Line type: " << node.line_type 
        << ", Multiline: " << node.multiline  << "}" << std::endl;
    return out;
}