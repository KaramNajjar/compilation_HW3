#ifndef __PARSER_HPP
#define __PARSER_HPP

#include <string>
#include <list> 

using namespace std;

enum EType
{
	E_INT, E_BOOL, E_BYTE ,E_UNDEFINED
};

struct Node 
{
	
};

struct RetTypeNode : Node
{
	
};

struct TypeNode : RetTypeNode
{
	EType etype;
	
	TypeNode(EType etype)
	{
		this->etype = etype;
	}
};

struct VoidTypeNode : RetTypeNode
{
	
};

struct IdNode : Node
{
	string id;
	
	IdNode(string id)
	{
		this->id = id;
	}
};	

struct StringNode : Node{
	
	string str;
	
	StringNode(string str){
		this->str = str;
	}
		
}; 

struct NumNode : Node{
	
	int num;
	
	NumNode(int num){
		this->num = num;
	}
		
}; 

//////////////////////////////////////////// ExpNode Regions ////////////////////////////////////////////

//enum R{
//	B_AND,B_OR,B_EQ,B_NEQ,B_BG,B_SM,B_BGE,B_SME
//};

 enum EXPTYPE{
	 
	EX_INTEGER , EX_BOOLEAN , EX_BYTE , EX_VOID ,EX_STRING, EX_FUNC , EX_UNDEFINED
};

enum BinOp{
	B_PLUS,B_MINUS,B_MUL,B_DIV
};

struct BinOpNode : Node
{
	BinOp binop;
	
	BinOpNode(BinOp binop){
		this->binop = binop;
	}
};

struct ExpNode : Node
{
	EXPTYPE type ;
	
	ExpNode(EXPTYPE type){
		 this->type = type;
	}
};

struct IdExpNode : ExpNode
{
	IdNode* id;
	
	IdExpNode(IdNode* id) : ExpNode(EX_UNDEFINED){
		this->id = id;
	}
};

struct NumExpNode : ExpNode{
	
	int num;
	
	NumExpNode(int num) : ExpNode(EX_INTEGER){
		this->num = num;
	}
	
};

struct NumBExpNode : NumExpNode{
	
	NumBExpNode(int num): NumExpNode(num){

	}
	
};

struct StringExpNode:ExpNode{
	
	string str;
	
	StringExpNode(string str) : ExpNode(EX_STRING){
		this->str = str;
	}
		
};

struct BoolExpNode: ExpNode{
	
	bool b;
	
	BoolExpNode(bool b): ExpNode(EX_BOOLEAN){
		this->b = b;
	}
};

struct NotExpNode : ExpNode{
	
	ExpNode* exp;
	
	NotExpNode(ExpNode* exp): ExpNode(EX_UNDEFINED){
		this->exp = exp;
	}
};

struct BinExpNode : ExpNode
{
	ExpNode* exp1;
	BinOpNode* op;
	ExpNode* exp2;
	
	BinExpNode(ExpNode* exp1,BinOpNode* op ,ExpNode* exp2) : ExpNode(EX_UNDEFINED){
		this->exp1 = exp1;
		this->op = op;
		this->exp2 = exp2;
	}
	
};

struct Call : Node
{
	
	IdNode* id;
	list<ExpNode*>* expList;
	
	Call(IdNode* id){
		this->id = id;
		expList = new list<ExpNode*>();
	}
};

struct CallExpNode : ExpNode{
	
	Call* call;
	
	CallExpNode(Call* call) : ExpNode(EX_UNDEFINED){
		this->call = call;
	}
	
};

#define YYSTYPE Node*

#endif