#include "../node.hpp"

class CDG
{
private:
    Node* lines;
    Node* generate(Node* prev, Node* current);
public:
    CDG(Node* lines);
    ~CDG(){}
};
