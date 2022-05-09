#include <iostream>
#include <fstream>
#include "./include/node.hpp"
#include "./include/linked_list/list_ops.hpp"
#include "./include/reader/ll_generator.hpp"
#include "./include/cdg/cdg.hpp"
#include "./include/cfg/cfg.hpp"

void generate_CFG(Node* root, std::string func_name);

int main(void) {
    
    Node* root = generate_linked_list();
    std::cout << "Generated linked list-----------\n";
    printListRec(root);

    generate_CFG(root->next, root->code);
}


void generate_CFG(Node* root, std::string func_name) {
    CDG* cdg = new CDG(root);
    CFG* cfg = new CFG(cdg->lines);
    cfg->createDot(func_name+".dot");
}
