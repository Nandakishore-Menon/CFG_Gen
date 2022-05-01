#pragma once
#include<string>
#include<iostream>
#include "line_type.hpp"
#include "../node.hpp"

class CfgNode
{
private:
public:
    int ID;
    int line_type;
    CfgNode* next;
    CfgNode* loopback;
    std::string code;
    CfgNode(int id, Node* cdg);
    ~CfgNode(){}
    friend std::ostream& operator<< (std::ostream& out, const CfgNode& node);
};

