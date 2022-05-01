#include "../node.hpp"

class CDG
{
private:
    Node* lines;
    Node* generate(Node* prev, Node* current, bool multiline_block);
public:
    CDG(Node* lines);
    ~CDG(){}
};
