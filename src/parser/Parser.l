%{
#include "./../../include/parser/parser_headers.h"
%}

%option noyywrap
MCOMMENT "/*"([^*]|(\*+[^*/]))*\*+\/
TSC [" "\t\n{MCOMMENT}]*
FOR "for"([" "\t\n]*)"("([" "\t\n]*)([^;]*)";"([" "\t\n]*)([^;]*)";"([" "\t\n]*)([^\)]*)")"([" "\t\n]*)"{"
MWHILE "while"([^\(]*)"("([^\)]*)")"([^\)]*)"{"
WHILE "while"([" "\t\n{MCOMMENT}]*)"("([" "\t\n{MCOMMENT}]*[^\);]*)*")"
MIF "if"([" "\t\n{MCOMMENT}]*)"("(([" "\t\n{MCOMMENT}]*[^\);]*)*)")"([" "\t\n{MCOMMENT}]*)"{"
IF "if"([" "\t\n{MCOMMENT}]*)"("(([" "\t\n{MCOMMENT}]*[^\);]*)*)")" 
MELSE "else"([" "\t\n{MCOMMENT}]*)"if"([" "\t\n{MCOMMENT}]*)"("(([" "\t\n{MCOMMENT}]*[^\);]*)*)")"([" "\t\n{MCOMMENT}]*)"{"
ELSE "else"([" "\t\n{MCOMMENT}]*)"{"
SWITCH "switch"{TSC}"("([^\)]*)\){TSC}"{"
CASE "case"{TSC}([^:]*)":"
DEFAULT "default"{TSC}":"
BREAK "break"{TSC}";"
CONTINUE "continue"{TSC}";"
RETURN "return"({TSC}([^";"]*))?";" 
%%

;                                                                                                                       return p_SEMICOLON;

[#][^\n]*                                                                                                               return p_PREPROCESSOR;

"//"([^\n])*                                                                                                            return p_SINGLE_LINE_COMMENT;

MCOMMENT                                                                                                                return p_MULTILINE_COMMENT;

([0-9a-zA-Z_])([" "]*)([0-9A-Za-z_" "]*)"("([^\);])")"([" "\t\n])"{"                                                    return p_FUNCTION;

"{"                                                                                                                     return p_OPENING_BRACE;

"}"                                                                                                                     return p_CLOSING_BRACE;

"for"([" "\t\n]*)"("([" "\t\n]*)([^;]*)";"([" "\t\n]*)([^;]*)";"([" "\t\n]*)([^\)]*)")"([" "\t\n]*)"{"                  return p_FOR_MULTILINE;

"while"([^\(]*)"("([^\)]*)")"([^\)]*)"{"                                                                                return p_WHILE_MULTILINE;

"while"([" "\t\n{MCOMMENT}]*)"("([" "\t\n{MCOMMENT}]*[^\);]*)*")"                                                       return p_WHILE;

"if"([" "\t\n{MCOMMENT}]*)"("(([" "\t\n{MCOMMENT}]*[^\);]*)*)")"([" "\t\n{MCOMMENT}]*)"{"                               return p_IF_MULTILINE;

"else"([" "\t\n{MCOMMENT}]*)"if"([" "\t\n{MCOMMENT}]*)"("(([" "\t\n{MCOMMENT}]*[^\);]*)*)")"([" "\t\n{MCOMMENT}]*)"{"   return p_ELSE_IF_MULTILINE;

"else"([" "\t\n{MCOMMENT}]*)"{"                                                                                         return p_ELSE_MULTILINE;

"for"([" "\t\n{MCOMMENT}]*)"("([" "\t\n{MCOMMENT}]*)([^;]*)";"([" "\t\n{MCOMMENT}]*)([^;]*)";"([" "\t\n{MCOMMENT}]*)([^\)]*)")" return p_FOR;

"if"([" "\t\n{MCOMMENT}]*)"("(([" "\t\n{MCOMMENT}]*[^\);]*)*)")"                                                        return p_IF;

"else"([" "\t\n{MCOMMENT}]*)"if"([" "\t\n{MCOMMENT}]*)"("(([" "\t\n{MCOMMENT}]*[^\);]*)*)")"                            return p_ELSE_IF;

"else"                                                                                                                  return p_ELSE;

"switch"{TSC}"("([^\)]*)\){TSC}"{"                                                                                      return p_SWITCH_MULTILINE;

"switch"{TSC}"("([^\)]*)\)                                                                                              return p_SWITCH;

"case"{TSC}([^:]*)":"{TSC}"{"                                                                                           return p_CASE_MULTILINE;

"case"{TSC}([^:]*)":"                                                                                                   return p_CASE;


"continue"{TSC}";"                                                                                                      return p_CONTINUE;

"break"{TSC}";"                                                                                                         return p_BREAK;

"default"{TSC}":"                                                                                                       return p_DEFAULT;

"return"({TSC}([^";"]*))?";"                                                                                            return p_RETURN;

[\t\n" "]                                                                                                               return p_WHITE_TAB_SPACE;

<<EOF>>                                                                                                                 return p_ENDOFFILE;



%%