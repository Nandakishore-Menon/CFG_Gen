#include "../../include/node.hpp"
#include "../../include/linked_list/list_ops.hpp"

int main() {
    Node* head = NULL;
    append(&head, 1, "Line 1", 1);
    // printList(head);
    append(&head, 2, "Line 2", 1);
    printList(head);
    return 0;
}