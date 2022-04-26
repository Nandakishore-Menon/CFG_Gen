#include <iostream>
#include "../../include/node.hpp"
#include "../../include/linked_list/list_ops.hpp"

void append(Node** head_ref, int ID, std::string code, int line_type) {
/*  Input: Node** head_ref -> Reference to the head of the list
            int ID -> ID of the code block being added
            std::string code -> Code (text) of code block
            int line_type -> Type of the code block
    Output: Adds the node to the end of the doubly linked list. Note that this function 
        sets the child and parent pointers to NULL
*/
    Node* new_node = new Node();
    Node* last = *head_ref;

    new_node->ID = ID;
    new_node->code = code;
    new_node->line_type = line_type;
    new_node->next = NULL;
    new_node->child = NULL;
    new_node->parent = NULL;

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

void printNode(Node* node) {
//  prints the ID and code of a given node

    if (node == NULL) {
        std::cout << "NULL\n";
        return;
    }
    std::cout << "(ID: " << node->ID << ", " << node->code << ")\n";
}

void printList(Node* head) {
/*  prints the (doubly) linked list
    -> Contents of current node and child node.*/

    Node* temp = head;
    while (temp != NULL) {
        std::cout << "Current: ";
        printNode(temp);
        std::cout << "Child: ";
        printNode(temp->child);
        std::cout << std::endl;
        temp = temp->next;
    }
}
