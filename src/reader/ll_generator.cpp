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

int linkToken(int ntoken, Node **root, Node **current, int ID, string *s, int *brace_count);
// Node *root = new Node();

Node* generate_linked_list(void){
    
    Node *root = NULL;
    Node *current = NULL;
    string *s = new string();
    *s = "";
    int *brace_count = new int();
    *brace_count = 0;

    vector<Node**> function_roots;

    int ntoken, eof, ID=0;
    ntoken = yylex();

    while(ntoken != p_ENDOFFILE){
        // printf("Got the token %d\n",ntoken);
        // cout<<"Got the token "<<ntoken<<endl;
        // cout<<endl;

        if (ntoken == p_FUNCTION){
            Node **new_root = &root;
            function_roots.push_back(new_root);

            root = NULL;
            current = NULL;
        }

        eof = linkToken(ntoken, &root, &current, ID, s, brace_count);
        ID++;

        if(eof == 1){
            break;
        }

        // printListRec(current);

        // next token
        ntoken = yylex();
    }

    // printListRec(root);
    return root;
}

int linkToken(int ntoken, Node **root, Node **current, int ID, string *s, int *brace_count){
    Node* new_node;
    int len;
    string const &whitespaces = " \r\n\t\v\f";

    switch (ntoken)
        {
        case 0:

            // if ((*current)->line_type == EXPRESSION){
            //     s = (*current)->code;
                len = (*s).length();

                // if (len != 0 && (*s)[len-1] != ';'){
                //     if((*s)[len-1] != ' ' || (*s)[len-1] != '\t' || (*s)[len-1] != '\n'){
                        *s = *s + " ";
                //         cout<<"added whitespace, tabspace, newline\n";
                //     }
                // }
                // else{
                //     new_node = new Node(ID, yytext, EXPRESSION, false);
                //     *current = new_node;
                //     append(root, new_node);
                // }
            // }

            // else{
            //     new_node = new Node(ID, yytext, EXPRESSION, false);
            //     *current = new_node;
            //     append(root, new_node);
            // }

            break;

        case 1:
            cout<<"got semicolon\n";

            // if ((*current)->line_type == EXPRESSION){
            //     s = (*current)->code;
            //     len = s.length();

            //     if (s[len-1] != ';')
            //         (*current)->code = s + ";";
            //     else{
            //         new_node = new Node(ID, yytext, EXPRESSION, false);
            //         *current = new_node;
            //         append(root, new_node);
            //     }
            // }

            *s = *s + ";";

            // while((*s)[0] == ' ' || (*s)[0] == '\t' || (*s)[0] == '\n'){
                (*s).erase(0, (*s).find_first_not_of(whitespaces));
            // }
            
            new_node = new Node(ID, *s, EXPRESSION, false);
            *current = new_node;
            append(root, new_node);
            
            cout << *s << "\t statement added\n";

            *s = "";

            break;

        case p_PREPROCESSOR:
            cout<<"got preprocessor directive\n";
            cout<<"text :"<<yytext<<endl;
            break;

        case p_SINGLE_LINE_COMMENT:
            cout<<"got single line comment\n";
            cout<<"text :"<<yytext<<endl;
            break;

        case p_MULTILINE_COMMENT:
            cout<<"got multiline comment\n";
            cout<<"text :"<<yytext<<endl;
            break;

        case p_OPENING_BRACE:
            cout<<"got opening brace\n";
            cout<<"text :"<<yytext<<endl;

            if (*brace_count == 0 && (*s).length() > 0){
                
                *s = *s + "{";

                (*s).erase(0, (*s).find_first_not_of(whitespaces));
                
                new_node = new Node(ID, *s, FUNCTION, true);
                *current = new_node;
                append(root, new_node);

                cout << *s << "\tFunction added\n";

                *s = "";
            }

            else{
                new_node = new Node(ID, yytext, OPENBRACE, true);
                *current = new_node;
                append(root, new_node);
            }

            *brace_count = *brace_count + 1;

            break;

        case p_CLOSING_BRACE:
            cout<<"got closing brace\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, CLOSEBRACE, false);
            *current = new_node;
            append(root, new_node);

            *brace_count = *brace_count - 1;

            break;

        case p_FOR_MULTILINE:
            cout<<"got multiline for\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, FOR, true);
            *current = new_node;
            append(root, new_node);

            *brace_count = *brace_count + 1;

            break;

        case p_WHILE_MULTILINE:
            cout<<"got multiline while\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, WHILE, true);
            *current = new_node;
            append(root, new_node);

            *brace_count = *brace_count + 1;

            break;

        case p_IF_MULTILINE:
            cout<<"got multiline if\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, IF, true);
            *current = new_node;
            append(root, new_node);

            *brace_count = *brace_count + 1;

            break;

        case p_ELSE_IF_MULTILINE:
            cout<<"got multiline else if\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, ELSEIF, true);
            *current = new_node;
            append(root, new_node);

            *brace_count = *brace_count + 1;

            break;

        case p_ELSE_MULTILINE:
            cout<<"got multiline else\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, ELSE, true);
            *current = new_node;
            append(root, new_node);

            *brace_count = *brace_count + 1;

            break;

        case p_FOR:
            cout<<"got for\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, FOR, false);
            *current = new_node;
            append(root, new_node);

            break;

        case p_WHILE:
            cout<<"got while\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, WHILE, false);
            *current = new_node;
            append(root, new_node);

            break;

        case p_IF:
            cout<<"got if\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, IF, false);
            *current = new_node;
            append(root, new_node);

            break;

        case p_ELSE_IF:
            cout<<"got else if\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, ELSEIF, false);
            *current = new_node;
            append(root, new_node);

            break;

        case p_ELSE:
            cout<<"got else\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, ELSE, false);
            *current = new_node;
            append(root, new_node);

            break;

        case p_ENDOFFILE:
            cout<<"got EOF \n";
            cout<<"text :"<<yytext<<endl;
            return 1;

        case p_STATEMENT:
            cout<<"got statement\n";
            cout<<"text :"<<yytext<<endl;
            
            *s = *s + yytext;

            break;


        case p_SWITCH:
            cout<<"got a switch statement\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, SWITCH, false);
            *current = new_node;
            append(root, new_node);

            break;

        case p_SWITCH_MULTILINE:
            cout<<"got a multiline switch\n";
            cout<<"text :"<<yytext<<endl;

            new_node = new Node(ID, yytext, SWITCH, true);
            *current = new_node;
            append(root, new_node);

            *brace_count = *brace_count + 1;

            break;

        case p_CASE:
            cout<<"got a case statement\n";
            cout<<"text :"<<yytext<<endl;

            new_node = new Node(ID, yytext, CASE, false);
            *current = new_node;
            append(root, new_node);

            break;

        case p_CASE_MULTILINE:
            cout<<"got a multiline case statement\n";
            cout<<"text :"<<yytext<<endl;

            new_node = new Node(ID, yytext, CASE, true);
            *current = new_node;
            append(root, new_node);

            *brace_count = *brace_count + 1;

            break;

        case p_BREAK:
            cout<<"got a break statement\n";
            cout<<"text :"<<yytext<<endl;

            new_node = new Node(ID, yytext, BREAK, false);
            *current = new_node;
            append(root, new_node);

            break;

        case p_CONTINUE:
            cout<<"got a continue statement\n";
            cout<<"text :"<<yytext<<endl;

            new_node = new Node(ID, yytext, CONTINUE, false);
            *current = new_node;
            append(root, new_node);

            break;

        case p_RETURN:
            cout<<"got a return statement\n";
            cout<<"text :"<<yytext<<endl;

            new_node = new Node(ID, yytext, RETURN, false);
            *current = new_node;
            append(root, new_node);

            break;
        
        case p_FUNCTION:
            cout<<"got a function definition\n";
            cout<<"text :"<<yytext<<endl;
            
            new_node = new Node(ID, yytext, FUNCTION, true);
            *current = new_node;
            append(root, new_node);

            *brace_count = *brace_count + 1;

            break;
        
        default:
            break;
    }
    return 0;
}
