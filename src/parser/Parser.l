%{
#include "./../../include/parser/parser_headers.h"
%}

%option noyywrap

%%

;                                       return p_SEMICOLON;

[#][^\n]*                               return p_PREPROCESSOR;

"//"([^\n])*                            return p_SINGLE_LINE_COMMENT;

"/*"([^*]|(\*+[^*/]))*\*+\/             return p_MULTILINE_COMMENT;

"{"                                     return p_OPENING_BRACE;

"}"                                     return p_CLOSING_BRACE;

"for("([^\(]*)\)([" "]*)"{"             return p_FOR_MULTILINE;

"while("([^\(]*)\)([" "]*)"{"           return p_WHILE_MULTILINE;

"if("([^\(]*)\)([" "]*)"{"              return p_IF_MULTILINE;

"else if("([^\(]*)\)([" "]*)"{"         return p_ELSE_IF_MULTILINE;

"else"([" "]*)"{"                       return p_ELSE_MULTILINE;

"for("([^\(]*)\)                        return p_FOR;

"while("([^\(]*)\)                      return p_WHILE;

"if("([^\(]*)\)                         return p_IF;

"else if("([^\(]*)\)                    return p_ELSE_IF;

"else"                                  return p_ELSE;

"switch("([^\(]*)\)([" "]*)"{"          return p_SWITCH_MULTILINE;

"switch("([^\(]*)\)                     return p_SWITCH;

"case"([" "]*)([^:]*)":"([" "]*)"{"     return p_CASE_MULTILINE;

"case"([" "]*)([^:]*)":"                return p_CASE;

"continue;"                             return p_CONTINUE;

"break;"                                return p_BREAK;

"return"(([" "]*)([^";"]*))?";"         return p_RETURN;

[\t\n]                                  return p_WHITE_TAB_SPACE;

<<EOF>>                                 return p_ENDOFFILE;

.                                       return p_STATEMENT;

%%