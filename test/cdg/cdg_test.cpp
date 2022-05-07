#include <iostream>
#include "../../include/cdg/cdg.hpp"
#include "../../include/linked_list/list_ops.hpp"

Node* generate_sample_code1();
Node* generate_sample_code2();
Node* generate_sample_code3();

int main() {
    
    std::cout << "Test case 1:--------------------\n";
    Node* lines1 = generate_sample_code1();
    CDG* cdg1 = new CDG(lines1);
    std::cout << "--------------------------------\n";
    
    std::cout << "Test case 2:--------------------\n";
    Node* lines2 = generate_sample_code2();
    CDG* cdg2 = new CDG(lines2);
    std::cout << "--------------------------------\n";
    
    std::cout << "Test case 3:--------------------\n";
    Node* lines3 = generate_sample_code3();
    CDG* cdg3 = new CDG(lines3);
    std::cout << "--------------------------------\n";
}

Node* generate_sample_code1() {
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

Node* generate_sample_code2() {
/*Sample code:
    int x = 0 ;
    int y = 2 ;
    for (int i = 0; i < 10; i++)
        if (x < 5) {
            x = y ;
            y += 1 ;
        }
        else
            x = 5 ;
    x++;
    */
    // Linked list after parsing for the above sample code:
    Node* lines = NULL;
    Node* new_node = new Node(1, "int x = 0;", EXPRESSION, false);
    append(&lines, new_node);
    new_node = new Node(2, "int y = 2;", EXPRESSION, false);
    append(&lines, new_node);
    new_node = new Node(3, "for (int i = 0; i < 10; i++)", FOR, false);
    append(&lines, new_node);
    new_node = new Node(4, "if (x < 5) {", IF, true);
    append(&lines, new_node);
    new_node = new Node(5, "x=y;", EXPRESSION, false);
    append(&lines, new_node);
    new_node = new Node(6, "y+=1;", EXPRESSION, false);
    append(&lines, new_node);
    new_node = new Node(7, "}", CLOSEBRACE, false);
    append(&lines, new_node);
    new_node = new Node(8, "else", ELSE, false);
    append(&lines, new_node);
    new_node = new Node(9, "x = 5;", EXPRESSION, false);
    append(&lines, new_node);
    new_node = new Node(10, "x++;", EXPRESSION, false);
    append(&lines, new_node);
    return lines;
}

Node* generate_sample_code3() {
/*Sample code:
    int x = 0, y=0 ;
    if (x<1) 
        if (x<3) {
            if (x<7)
                if (x<10)
                    while (x<10) {
                        x++;
                    }
            y++;
        }
    x = y;
    */
    // Linked list after parsing for the above sample code:
    Node* lines = NULL;
    Node* new_node = new Node(1, "int x = 0, y=0", EXPRESSION, false);
    append(&lines, new_node);
    new_node = new Node(2, "if (x<1)", IF, false);
    append(&lines, new_node);
    new_node = new Node(3, "if (x<3) {", IF, true);
    append(&lines, new_node);
    new_node = new Node(4, "if (x<7)", IF, false);
    append(&lines, new_node);
    new_node = new Node(5, "if (x<10)", IF, false);
    append(&lines, new_node);
    new_node = new Node(6, "while (x<10) {", WHILE, true);
    append(&lines, new_node);
    new_node = new Node(7, "x++", EXPRESSION, false);
    append(&lines, new_node);
    new_node = new Node(8, "}", CLOSEBRACE, false);
    append(&lines, new_node);
    new_node = new Node(9, "y++;", EXPRESSION, false);
    append(&lines, new_node);
    new_node = new Node(10, "}", CLOSEBRACE, false);
    append(&lines, new_node);
    new_node = new Node(11, "x=y;", EXPRESSION, false);
    append(&lines, new_node);
    return lines;
}