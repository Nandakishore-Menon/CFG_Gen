%{
#include "./../../include/parser/parser_headers.h"
%}

%option noyywrap
MCOMMENT "/*"([^*]|(\*+[^*/]))*\*+\/
NSC [^\);]*
%%

;                                       return p_SEMICOLON;

[#][^\n]*                               return p_PREPROCESSOR;

"//"([^\n])*                            return p_SINGLE_LINE_COMMENT;

MCOMMENT            return p_MULTILINE_COMMENT;

"{"                                     return p_OPENING_BRACE;

"}"                                     return p_CLOSING_BRACE;

"for"([" "\t\n{MCOMMENT}]*)"("([" "\t\n{MCOMMENT}]*)([^;]*)";"([" "\t\n{MCOMMENT}]*)([^;]*)";"([" "\t\n{MCOMMENT}]*)([^\)]*)")"([" "\t\n{MCOMMENT}]*)"{" return p_FOR_MULTILINE;

"while"([" "\t\n{MCOMMENT}]*)"("([" "\t\n{MCOMMENT}{NSC}]*)")"([" "\t\n{MCOMMENT}]*)"{" return p_WHILE_MULTILINE;
"while"([" "\t\n{MCOMMENT}]*)"("([" "\t\n{MCOMMENT}{NSC}]*)")" return p_WHILE;



"while("([^\(]*)\)([" "]*)"{"           return p_WHILE_MULTILINE;

"if("([^\(]*)\)([" "]*)"{"              return p_IF_MULTILINE;

"else if("([^\(]*)\)([" "]*)"{"         return p_ELSE_IF_MULTILINE;

"else"([" "]*)"{"                       return p_ELSE_MULTILINE;

"for"([" "\t\n{MCOMMENT}]*)"("([" "\t\n{MCOMMENT}]*)([^;]*)";"([" "\t\n{MCOMMENT}]*)([^;]*)";"([" "\t\n{MCOMMENT}]*)([^\)]*)")" return p_FOR;
"for("([^\(]*)\)                        return p_FOR;

"while("([^\(]*)")"                      return p_WHILE;

"if("([^\(]*)\)                         return p_IF;

"else if("([^\(]*)\)                    return p_ELSE_IF;

"else"                                  return p_ELSE;

"switch("([^\(]*)\)([" "]*)"{"          return p_SWITCH_MULTILINE;

"switch("([^\(]*)\)                     return p_SWITCH;

"case"([" "]*)([^:]*)":"([" "]*)"{"     return p_CASE_MULTILINE;

"case"([" "]*)([^:]*)":"                return p_CASE;

(([^" "\n\t]+)([" "]))+([" "]*)([^" "]+)([" "]*)"("([^\)])*"){"        return p_FUNCTION;

(([^" "\n\t]+)([" "]*))+";"              return p_STATEMENT;

"continue;"                             return p_CONTINUE;

"break;"                                return p_BREAK;

"return"(([" "]*)([^";"]*))?";"         return p_RETURN;

[\t\n" "]                               return p_WHITE_TAB_SPACE;

<<EOF>>                                 return p_ENDOFFILE;



%%