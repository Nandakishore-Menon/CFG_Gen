#include<iostream>

#include "./../../include/parser/parser_headers.h"
#include "./../node.hpp"

extern int yylex();
extern int yylineno;
extern char * yytext;

using namespace std;

// Node *root = new Node();

int main(void){
    int ntoken;
    ntoken = yylex();
    while(ntoken != ENDOFFILE){
        // printf("Got the token %d\n",ntoken);
        // cout<<"Got the token "<<ntoken<<endl;
        // cout<<endl;
        switch (ntoken)
        {
        case 0:
            // cout<<"got whitespace and tabspace\n";
            break;
        case 1:
            // cout<<"got semicolon\n";
            break;
        case 2:
            // cout<<"got preprocessor directive\n";
            // cout<<"text :"<<yytext<<endl;
            break;
        case 3:
            // cout<<"got single line comment\n";
            // cout<<"text :"<<yytext<<endl;
            break;
        case 4:
            // cout<<"got multiline comment\n";
            // cout<<"text :"<<yytext<<endl;
            break;
        case 5:
            cout<<"got opening brace\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 6:
            cout<<"got closing brace\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 7:
            cout<<"got multiline for\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 8:
            cout<<"got multiline while\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 9:
            cout<<"got multiline if\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 10:
            cout<<"got multiline else if\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 11:
            cout<<"got multiline else\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 12:
            cout<<"got for\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 13:
            cout<<"got while\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 14:
            cout<<"got if\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 15:
            cout<<"got else if\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 16:
            cout<<"got else\n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 17:
            cout<<"got EOF \n";
            cout<<"text :"<<yytext<<endl;
            break;
        case 18:
            // cout<<"got statement\n";
            // cout<<"text :"<<yytext<<endl;
            break;
        default:
            break;
        }
        ntoken = yylex();
    }
    return 0;
}