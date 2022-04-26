#pragma once
#include<string>
#include "line_type.hpp"

class Node
{
private:
    
public:
    int ID;
    Node * next;
    Node * prev;
    Node * child;
    Node * parent;
    std::string code;
    int line_type;
    Node(/* args */){}
    ~Node(){}
};