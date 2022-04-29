#pragma once
#include<string>
#include "line_type.hpp"

class Node
{
private:
    bool multiline;
    bool elseused;

public:
    int ID;
    Node * next;
    Node * prev;
    Node * child;
    Node * parent;
    std::string code;
    int line_type;
    Node(int ID, std::string code, int line_type, bool multiline);
    ~Node(){}

    friend std::ostream& operator<< (std::ostream& out, const Node& node);
};

