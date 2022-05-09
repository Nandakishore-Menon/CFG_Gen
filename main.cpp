#include <iostream>
#include <fstream>
#include "./include/node.hpp"
#include "./include/linked_list/list_ops.hpp"
#include "./include/reader/ll_generator.hpp"

int main(void) {
    
    Node* root = generate_linked_list();
    printListRec(root);
}