#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../line_type.hpp"
#include "../node.hpp"

class CFG
{
private:
static int id_count;
    
public:
    Node* cdg;
    CFG(Node* head);
    std::vector<Node*> CFG_gen(Node* current);
    static int idIncrement();
    static void idReset();
    friend std::ostream& operator<< (std::ostream& out, const Node& node);
};

