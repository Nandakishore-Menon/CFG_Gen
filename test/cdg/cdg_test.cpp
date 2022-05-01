#include <iostream>
#include "../../include/cdg/cdg.hpp"
#include "../../include/linked_list/list_ops.hpp"

Node* generate_sample_code();

int main() {
    Node* lines = generate_sample_code();
    CDG* cdg = new CDG(lines);

}

Node* generate_sample_code() {
/*Sample code:
    int x = 0 ;
    int y = 2 ;
    if ( x < 5 ) {
        x = y ;
        y += 1 ;
    }
    x++;
    */
    // Linked list after parsing for the above sample code:
    Node* lines = NULL;
    Node* new_node = new Node(1, "int x = 0;", EXPRESSION, false);
    append(&lines, new_node);
    new_node = new Node(2, "int y = 2;", EXPRESSION, false);
    append(&lines, new_node);
    new_node = new Node(3, "if (x < 5) {", IF, true);
    append(&lines, new_node);
    new_node = new Node(4, "x=y;", EXPRESSION, false);
    append(&lines, new_node);
    new_node = new Node(5, "y+=1;", EXPRESSION, false);
    append(&lines, new_node);
    new_node = new Node(6, "}", CLOSEBRACE, false);
    append(&lines, new_node);
    new_node = new Node(7, "x++;", EXPRESSION, false);
    append(&lines, new_node);
    return lines;
}
