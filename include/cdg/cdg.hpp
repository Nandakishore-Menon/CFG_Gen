#include "../node.hpp"

class CDG
{
private:
    Node* generate(Node* prev, Node* current, bool multiline_block);
public:
    Node* lines;
    CDG(Node* lines);
    ~CDG(){}
};
