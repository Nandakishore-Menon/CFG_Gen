#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include "../line_type.hpp"
#include "../node.hpp"

class CFG
{
public:
    Node* cdg;
    CFG(Node* head);
    std::vector<Node*> CFG_gen(Node* current);
    void createDot(std::string file_name);
    void createDotRec(Node* current, std::set<int>& st, std::set<int>& file_stack, std::fstream& fio);
};

