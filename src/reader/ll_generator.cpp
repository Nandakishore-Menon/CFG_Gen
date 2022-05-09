#include <iostream>
#include <vector>
#include "./../../include/reader/ll_generator.hpp"
#include "./../../include/parser/parser_headers.h"
#include "./../../include/node.hpp"
#include "./../../include/linked_list/list_ops.hpp"

extern int yylex();
extern int yylineno;
extern char * yytext;

using namespace std;

// int linkToken(int ntoken, Node *root, Node *current, int ID);
// Node *root = new Node();

Node* generate_linked_list(void){
    
    Node *root = NULL;
    Node *current = NULL;

    // vector<Node*> function_roots;

    int ntoken, eof, ID=0;
    ntoken = yylex();

    while(ntoken != p_ENDOFFILE){
        // printf("Got the token %d\n",ntoken);
        // cout<<"Got the token "<<ntoken<<endl;
        // cout<<endl;

        // if (ntoken == p_FUNCTION){
        //     Node *new_root = root;
        //     function_roots.push_back(new_root);

        //     root = NULL;
        //     current = NULL;
        // }

        eof = linkToken(ntoken, root, current, ID);
        ID++;

        if(eof == 1){
            break;
        }

        // next token
        ntoken = yylex();
    }
    return root;
}

int linkToken(int ntoken, Node *root, Node *current, int ID){
    Node* new_node;
    switch (ntoken)
        {
        case 0:
            // cout<<"got whitespace and tabspace\n";
            break;
        case 1:
            cout<<"got semicolon\n";
            
            if (root == NULL){
                // root = new Node(ID, yytext, EXPRESSION, false);
                // current = root;
                new_node = new Node(ID, yytext, EXPRESSION, false);
                append(&root, new_node);
            }

            else if (current->line_type == EXPRESSION){
                current->code = current->code + ';';
            }

            else{
                // Node *node = new Node(ID, yytext, EXPRESSION, false);

                // current->next = node;
                // node->prev = current;
                // current = current->next;
                new_node = new Node(ID, yytext, EXPRESSION, false);
                append(&root, new_node);
            }

            break;

        case 2:
            cout<<"got preprocessor directive\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 3:
            cout<<"got single line comment\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 4:
            cout<<"got multiline comment\n";
            cout<<"text :"<<yytext<<endl;
            break;

        case 5:
            cout<<"got opening brace\n";
            cout<<"text :"<<yytext<<endl;

            // if (root == nullptr){
            //     root = new Node(ID, yytext, OPENBRACE, true);
            //     current = root;
            // }

            // else{
            //     Node *node = new Node(ID, yytext, OPENBRACE, true);

            //     current->next = node;
            //     node->prev = current;
            //     current = current->next;
            // }

            new_node = new Node(ID, yytext, OPENBRACE, true);
            append(&root, new_node);

            break;

        case 6:
            cout<<"got closing brace\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, CLOSEBRACE, true);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, CLOSEBRACE, true);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 7:
            cout<<"got multiline for\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, FOR, true);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, FOR, true);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 8:
            cout<<"got multiline while\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, WHILE, true);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, WHILE, true);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 9:
            cout<<"got multiline if\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, IF, true);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, IF, true);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 10:
            cout<<"got multiline else if\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, ELSEIF, true);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, ELSEIF, true);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 11:
            cout<<"got multiline else\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, ELSE, true);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, ELSE, true);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 12:
            cout<<"got for\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, FOR, false);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, FOR, false);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 13:
            cout<<"got while\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, WHILE, false);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, WHILE, false);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 14:
            cout<<"got if\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, IF, false);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, IF, false);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 15:
            cout<<"got else if\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, ELSEIF, false);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, ELSEIF, false);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 16:
            cout<<"got else\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, ELSE, false);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, ELSE, false);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 17:
            cout<<"got EOF \n";
            cout<<"text :"<<yytext<<endl;
            return 1;
        case 18:
            cout<<"got statement\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, EXPRESSION, false);
                current = root;
            }

            else if (current->line_type == p_STATEMENT){
                current->code = current->code + ';';
            }

            else{
                Node *node = new Node(ID, yytext, EXPRESSION, false);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 19:
            cout<<"got a switch statement\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, SWITCH, false);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, SWITCH, false);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 20:
            cout<<"got a multiline switch\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, SWITCH, true);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, SWITCH, true);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 21:
            cout<<"got a case statement\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, CASE, false);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, CASE, false);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 22:
            cout<<"got a multiline case statement\n";
            cout<<"text :"<<yytext<<endl;

            if (root == nullptr){
                root = new Node(ID, yytext, CASE, true);
                current = root;
            }

            else{
                Node *node = new Node(ID, yytext, CASE, true);

                current->next = node;
                node->prev = current;
                current = current->next;
            }

            break;

        case 23:
            cout<<"got a break statement\n";
            cout<<"text :"<<yytext<<endl;

            new_node = new Node(ID, yytext, BREAK, false);
            append(&root, new_node);
            // printListRec(root);
            break;

        case 24:
            cout<<"got a continue statement\n";
            cout<<"text :"<<yytext<<endl;

            new_node = new Node(ID, yytext, CONTINUE, false);
            append(&root, new_node);
            // printListRec(root);
            break;

        case 25:
            cout<<"got a return statement\n";
            cout<<"text :"<<yytext<<endl;

            new_node = new Node(ID, yytext, RETURN, false);
            append(&root, new_node);
            // printListRec(root);
            break;
        
        case 26:
            cout<<"got a function definition\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, FUNCTION, true);
            append(&root, new_node);
            // printListRec(root);

            break;
        
        default:
            break;
    }
    return 0;
}
