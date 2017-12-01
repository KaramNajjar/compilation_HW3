%{
	#include "attributes.h"
	#include "parser.tab.hpp"
	#include "output.hpp"
	#include <iostream>
	using namespace output;
	
%}

%option yylineno
%option noyywrap
whitespace ([\t\n\r ])
BINOP			("*"|"-"|"+"|"/")
ID				([a-zA-Z][a-zA-Z0-9]*)
NUM				(0|[1-9][0-9]*)
STRING			(\"([^\n\r\"\\]|\\[rnt"\\])+\")
COMMENT			(\/\/[^\r\n]*[ \r|\n|\r\n]?)
RELOP 			(<=|>=|>|<|==|!=)

%%

"void" 		{yylval.breakflag = 0 ;yylval.type = A_VOID;return VOID;} 
"int"        {yylval.breakflag = 0 ; yylval.type = A_INTEGER ; yylval.size = 1;return INT;} ///WE SHOULD CHANGE SIZES
"byte"         {yylval.breakflag = 0 ;yylval.type = A_BYTE  ; yylval.size = 1;return BYTE;}
"b" {yylval.breakflag = 0 ;return B;}
"bool"        {yylval.breakflag = 0 ; yylval.type = A_BOOLEAN ; yylval.size = 1;return BOOL;}
"and" {yylval.breakflag = 0 ;return AND;}
"or"        {yylval.breakflag = 0 ;return OR;}
"not" {yylval.breakflag = 0 ;return NOT;}
"true"        {yylval.breakflag = 0 ;return TRUE;}
"false" {yylval.breakflag = 0 ;return FALSE;}
"return" {yylval.breakflag = 0 ;return RETURN;}
"if"       {yylval.breakflag = 0 ;return IF;}
"else" {yylval.breakflag = 0 ;return ELSE;}
"while"    { yylval.breakflag = 0 ; return WHILE;}
"switch"    { yylval.breakflag = 0 ; return SWITCH;}
"case"    { yylval.breakflag = 0 ; return CASE;}
"break" {yylval.breakflag = 1 ; return BREAK;}
":"      {yylval.breakflag = 0 ;return COLON;}
";"      {yylval.breakflag = 0 ;return SC;}
","      {yylval.breakflag = 0 ;return COMMA;}
"("      {yylval.breakflag = 0 ;return LPAREN;}
")"      {yylval.breakflag = 0 ;return RPAREN;}
"{"      {yylval.breakflag = 0 ;return LBRACE;}
"}"      {yylval.breakflag = 0 ;return RBRACE;}
"="      {yylval.breakflag = 0 ;return ASSIGN;}

{RELOP} 		{yylval.breakflag = 0 ;return RELOP; }
{BINOP}			 {yylval.breakflag = 0 ;return BINOP; }
{ID}			 {yylval.name = yytext ; return ID ;}
{NUM}			 {yylval.value = atoi(yytext);return NUM;}
{STRING}			{yylval.name = yytext;yylval.type = A_STRING;return STRING;}
{COMMENT}			;
{whitespace}    ;
.			{errorLex(yylineno); exit(1);}


%%
 /*

 
 ("+"|"-"|"*"|"\/")  {yylval.breakflag = 0 ;return BINOP; }

[1-9][0-9]*|0                {yylval.value = atoi(yytext);return NUM;}
[a-zA-Z_][a-zA-Z0-9]* {yylval.name = yytext ; return ID ;}
"//"[^\n]*\n    ;
"([^\n\r\"\\]|\\[rnt"\\])+"  {yylval.value = atoi(yytext);return STRING;}

\/\/[^\r\n]*[\r|\n|\r\n]?   ;
 */
