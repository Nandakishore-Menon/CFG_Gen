#pragma once
#include<string>
#include "line_type.hpp"

class Node
{
private:
    bool haslabel;
    std::string label; 
public:
    int ID;
    Node * next;
    Node * prev;
    Node * child;
    Node * parent;
    std::string code;
    int line_type;
    bool multiline;
    bool elseused;
    Node(int ID, std::string code, int line_type, bool multiline=false, 
            bool haslabel=false, std::string label = "");
    ~Node(){}

    friend std::ostream& operator<< (std::ostream& out, const Node& node);
};

