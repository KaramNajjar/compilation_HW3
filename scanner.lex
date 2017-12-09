%{
	
	#include "parser.hpp"
	#include "parser.tab.hpp"
	#include "output.hpp"
	#include <iostream>
	
	using namespace output;
	using namespace std;

%}
%option noyywrap
%option yylineno

%%

"void"								{ yylval = new VoidTypeNode(); return VOID;}
"int"								{ yylval = new TypeNode(E_INTEGER); return INT;}
"byte"								{ yylval = new TypeNode(E_BYTE); return BYTE;}
"b"									return B;
"bool" 								{ yylval = new TypeNode(E_BOOLEAN); return BOOL;}
"and"								return AND;
"or"								return OR; //{yylval = new BinOpNode(B_OR); return OR);}
"not"								return NOT;
"true"								{yylval = new BoolNode(true); return TRUE;}
"false"								{yylval = new BoolNode(false);return FALSE;}
"return"							return RETURN;
"if"								return IF;
"else"								return ELSE;
"while"								return WHILE;
"switch"							return SWITCH;
"case"								return CASE;
"break"								return BREAK;
"default"							return DEFAULT;
":"									return COLON;
";"									return SC;
","									return COMMA;
"("									return LPAREN;
")"									return RPAREN;
"{"									return LBRACE;
"}"									return RBRACE;
"="									return ASSIGN;
"=="|"!="|"<"|">"|"<="|">=" 		return RELOP;
"+"|"-"|"*"|"/"						return BINOP;
[a-zA-Z][a-zA-Z0-9]*				{ yylval = new IdNode(yytext); return ID;}
0|[1-9][0-9]*						{ yylval = new NumNode(atoi(yytext)); return NUM;}
\"([^\n\r\"\\]|\\[rnt"\\])+\"		{ yylval = new StringNode(yytext); return STRING;}
[\t| ]*								; // IGNORE SPACES
[\r|\n|\r\n]*						; //IGNORE NEW LINES
\/\/[^\r\n]*[\r|\n|\r\n]?			; //COMMENT

.									{errorLex(yylineno); exit(1);}


%%







