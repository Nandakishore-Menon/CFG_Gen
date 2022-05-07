#pragma once
#include <iostream>
#include <string>
#include "../line_type.hpp"
#include "../node.hpp"
#include "cfgNode.hpp"

class CFG
{
private:
static int id_count;
    
public:
    Node* cdg;
    CFG(Node* head);
    CfgNode* CFG_gen(CfgNode* head, CfgNode* curr, Node* curr_cdg);
    static int idIncrement();
    static void idReset();
    friend std::ostream& operator<< (std::ostream& out, const Node& node);
};

