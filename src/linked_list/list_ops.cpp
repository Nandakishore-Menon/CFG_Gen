#include <iostream>
#include "../../include/node.hpp"
#include "../../include/linked_list/list_ops.hpp"

void append(Node** head_ref, Node* new_node) {
/*  Input: Node** head_ref -> Reference to the head of the list
            Node* new_node -> Node with the following values initialized: ID, code, line_type, multiline
                (using constructor of Node)
    Output: Adds the node to the end of the doubly linked list. 
*/
    Node* last = *head_ref;
   
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;
    
    last->next = new_node;
    new_node->prev = last;

    return;
}

/*
void printNode(Node* node) {
//  prints the ID and code of a given node

    if (node == NULL) {
        std::cout << "NULL\n";
        return;
    }
    std::cout << "(ID: " << node->ID << ", " << node->code << ")\n";
}
*/

void printList(Node* head) {
/*  prints the (doubly) linked list
    -> Contents of current node and child node.*/

    Node* temp = head;
    while (temp->next != NULL) {
        // std::cout << "Current: ";
        // printNode(temp);
        std::cout << *temp << "->";
        if (temp->child != NULL) {
            std::cout << "\nChild: ";
            printList(temp->child);
        }
        // 
        // printNode(temp->child);
        // std::cout << std::endl;
        temp = temp->next;
    }
    std::cout << *temp << std::endl;
}
