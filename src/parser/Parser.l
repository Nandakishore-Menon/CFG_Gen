%{
#include "./../../include/parser/parser_headers.h"
%}

%option noyywrap

%%

;                                       return P_SEMICOLON;

[#][^\n]*                               return PREPROCESSOR;

"//"([^\n])*                            return SINGLE_LINE_COMMENT;

"/*"([^*]|(\*+[^*/]))*\*+\/             return MULTILINE_COMMENT;

"{"                                     return OPENING_BRACE;

"}"                                     return CLOSING_BRACE;

"for("([^\(]*)\)([" "]*)"{"             return FOR_MULTILINE;

"while("([^\(]*)\)([" "]*)"{"           return WHILE_MULTILINE;

"if("([^\(]*)\)([" "]*)"{"              return IF_MULTILINE;

"else if("([^\(]*)\)([" "]*)"{"         return ELSE_IF_MULTILINE;

"else"([" "]*)"{"                       return ELSE_MULTILINE;

"for("([^\(]*)\)                        return FOR;

"while("([^\(]*)\)                      return WHILE;

"if("([^\(]*)\)                         return IF;

"else if("([^\(]*)\)                    return ELSE_IF;

"else"                                  return ELSE;

[\t\n]                                  return WHITE_TAB_SPACE;

<<EOF>>                                 return ENDOFFILE;

.                                       return STATEMENT;

%%