#include "include/cfg/cfgNode.hpp"

CfgNode::CfgNode(int id, Node* cdg) {
    ID = id;
    next = NULL;
    loopback = NULL;
    line_type = cdg->line_type;
    code = cdg->code;
}

std::ostream& operator<< (std::ostream& out, const CfgNode& node) {
    out << "{ID: " << node.ID << ", Code: " << node.code << "}" << std::endl;
    return out;
}