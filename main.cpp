#include <iostream>
#include <fstream>
#include "./include/node.hpp"
#include "./include/linked_list/list_ops.hpp"
#include "./include/reader/ll_generator.hpp"
#include "./include/cdg/cdg.hpp"
#include "./include/cfg/cfg.hpp"

void generate_CFG(Node* root, std::string func_name);

int main(void) {
    
    std::vector<Node*> roots = generate_linked_list();
    std::cout << "Generated linked list-----------\n";
    for(auto& root: roots) {
        std::cout << "\n-------------------------------------------------------------------------\n";
        printListRec(root);
        if (root != NULL)
            generate_CFG(root->next, root->code);
    }
    

    
}


void generate_CFG(Node* root, std::string func_name) {
    CDG* cdg = new CDG(root);
    CFG* cfg = new CFG(cdg->lines);
    cfg->createDot(func_name+".dot");
}
