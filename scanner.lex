%{

	#include "parser.tab.hpp"

	int handleToken(int t);


%}
%option noyywrap

%%

"void"								handleToken(VOID);
"int"								handleToken(INT);
"byte"								handleToken(BYTE);
"b"									handleToken(B);
"bool" 								handleToken(BOOL);
"and"								handleToken(AND);
"or"								handleToken(OR);
"not"								handleToken(NOT);
"true"								handleToken(TRUE);
"false"								handleToken(FALSE);
"return"							handleToken(RETURN);
"if"								handleToken(IF);
"else"								handleToken(ELSE);
"while"								handleToken(WHILE);
"switch"							handleToken(SWITCH);
"case"								handleToken(CASE);
"break"								handleToken(BREAK);
"default"							handleToken(DEFAULT);
":"									handleToken(COLON);
";"									handleToken(SC);
","									handleToken(COMMA);
"("									handleToken(LPAREN);
")"									handleToken(RPAREN);
"{"									handleToken(LBRACE);
"}"									handleToken(RBRACE);
"="									handleToken(ASSIGN);
"=="|"!="|"<"|">"|"<="|">=" 		handleToken(RELOP);
"+"|"-"|"*"|"/"						handleToken(BINOP);
[a-zA-Z][a-zA-Z0-9]*				handleToken(ID);
0|[1-9][0-9]*						handleToken(NUM);
\"([^\n\r\"\\]|\\[rnt"\\])+\"		handleToken(STRING);
[\t| ]*								; // IGNORE SPACES
[\r|\n|\r\n]*						; //IGNORE NEW LINES
\/\/[^\r\n]*[\r|\n|\r\n]?			; //COMMENT

%%
/*
static const char* TOKENS_STRING[] = {
	"VOID"
	,"INT"
	,"BYTE"
	,"B"
	,"BOOL"
	,"AND"
	,"OR"
	,"NOT"
	,"TRUE"
	,"FALSE"
	,"RETURN"
	,"IF"
	,"ELSE"
	,"WHILE"
	,"SWITCH"
	,"CASE"
	,"BREAK"
	,"DEFAULT"
	,"COLON"
	,"SC"
	,"COMMA"
	,"LPAREN"
	,"RPAREN"
	,"LBRACE"
	,"RBRACE"
	,"ASSIGN"
	,"RELOP"
	,"BINOP"
	,"ID"
	,"NUM"
	,"STRING"
};

*/
int handleToken(int t){
	

	//printf(">%s<",TOKENS_STRING[t]);
	return t;
	
}