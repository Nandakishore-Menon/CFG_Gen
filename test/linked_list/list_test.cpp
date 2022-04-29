#include <iostream>
#include "../../include/node.hpp"
#include "../../include/linked_list/list_ops.hpp"

int main() {
    Node* head = NULL;
    Node* new_node = new Node(1, "Line 1", 1, false);
    append(&head, new_node);
    // printList(head);
    new_node = new Node(2, "Line 2", 1, false);
    append(&head, new_node);
    printList(head);
    return 0;
}