#ifndef __PARSER_HPP
#define __PARSER_HPP

#include <string>
#include <list> 

using namespace std;




enum EType
{
	E_INTEGER , E_BOOLEAN , E_BYTE , E_VOID ,E_STRING, E_FUNC , E_UNDEFINED
};

struct Node 
{
	EType type;
	
	Node(EType type){
		this->type = type;
	}
	Node(){
		this->type = E_UNDEFINED;
	}
	
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

struct BoolNode : Node {
	
	bool b;
	
	BoolNode(bool b){
		this->b = b;
	}
	
	
};


//enum R{
//	B_AND,B_OR,B_EQ,B_NEQ,B_BG,B_SM,B_BGE,B_SME
//};


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
	
	ExpNode(EType type):Node(type){
	}
};

struct IdExpNode : ExpNode
{
	IdNode* idNode;
	
	IdExpNode(IdNode* idNode) : ExpNode(E_STRING){
		this->idNode = idNode;
	}
};

struct NumExpNode : ExpNode{
	
	NumNode* numNode;
	
	NumExpNode(NumNode* numNode) : ExpNode(E_INTEGER){
		this->numNode = numNode;
	}
	
};

struct NumBExpNode : ExpNode{
	
	NumNode* numNode;
	NumBExpNode(NumNode* numNode): ExpNode(E_BYTE){
		this->numNode = numNode;
	}
	
};

struct StringExpNode:ExpNode{
	
	StringNode* str;
	
	StringExpNode(StringNode* str) : ExpNode(E_STRING){
		this->str = str;
	}
		
};

struct BoolExpNode: ExpNode{
	
	BoolNode* b;
	
	BoolExpNode(BoolNode* b): ExpNode(E_BOOLEAN){
		this->b = b;
	}
};

struct NotExpNode : ExpNode{
	
	ExpNode* exp;
	
	NotExpNode(ExpNode* exp): ExpNode(E_BOOLEAN){
		this->exp = exp;
	}
};

struct BinExpNode : ExpNode
{
	ExpNode* exp1;
	BinOpNode* op;
	ExpNode* exp2;
	
	BinExpNode(ExpNode* exp1,BinOpNode* op ,ExpNode* exp2) : ExpNode(E_UNDEFINED){
		this->exp1 = exp1;
		this->op = op;
		this->exp2 = exp2;
	}
	
};
struct ExpListNode : Node{
	list<ExpNode*>* params;
	
	ExpListNode(){
		params = new list<ExpNode*>();
	}
};
struct CallNode : Node
{
	
	IdNode* id;
	list<ExpNode*>* expList;
	
	CallNode(IdNode* id){
		this->id = id;
		expList = new list<ExpNode*>();
	}
};

struct CallExpNode : ExpNode{
	
	CallNode* callNode;
	
	CallExpNode(CallNode* callNode) : ExpNode(E_UNDEFINED){
		this->callNode = callNode;
	}
	
};

#define YYSTYPE Node*

#endif