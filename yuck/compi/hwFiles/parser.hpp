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
	
};

struct TypeNode : Node
{
	EType type;
	TypeNode(EType type)
	{
		this->type = type;
	}
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
	EType expType;
	ExpNode(EType expType){
		this->expType = expType;
	}
};

struct IdExpNode : ExpNode
{
	IdNode* idNode;
	
	IdExpNode(IdNode* idNode, EType type): ExpNode(type){
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

struct StringExpNode : ExpNode{
	
	StringNode* str;
	
	StringExpNode(StringNode* str) : ExpNode(E_STRING){
		this->str = str;
	}
		
};

struct BoolExpNode : ExpNode{
	
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
	
	BinExpNode(ExpNode* exp1,BinOpNode* op ,ExpNode* exp2) : ExpNode(E_INTEGER){
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
	EType callType;
	IdNode* id;
	list<ExpNode*>* expList;
	
	CallNode(IdNode* id, EType callType){
		this->id = id;
		this->callType = callType;
		expList = new list<ExpNode*>();
	}
};

struct CallExpNode : ExpNode{
	
	CallNode* callNode;
	
	CallExpNode(CallNode* callNode) : ExpNode(callNode->callType){
		this->callNode = callNode;
	}
};


struct StatementNode : Node
{
	
};

struct DeclStatementNode : StatementNode
{
	TypeNode* type;
	IdNode* id;
	
	DeclStatementNode(TypeNode* type, IdNode* id)
	{
		this->type = type;
		this->id = id;
	}
};

struct AssignStatementNode : StatementNode
{
	ExpNode* exp;
	IdNode* id;
	
	AssignStatementNode(ExpNode* exp, IdNode* id)
	{
		this->exp = exp;
		this->id = id;
	}
};

struct StatementNodes : Node
{
	list<StatementNode>* statementNodes;
	
	StatementNodes()
	{
		this->statementNodes = new list<StatementNode>();
	}
};

struct CallStatementNode : StatementNode{
	
	CallNode* call;
	
	CallStatementNode(CallNode* call){
		this->call = call;
	}	
	
};

struct ReturnStatementNode : StatementNode{
	
	ExpNode* exp;
	
	ReturnStatementNode(){
		this->exp = NULL;
	}
	ReturnStatementNode(ExpNode* exp){
		this->exp = exp;
	}
};

struct IfStatementNode : StatementNode{
	
	ExpNode* exp;
	StatementNode* statement;
	
	IfStatementNode(ExpNode* exp,StatementNode* statement){
		this->exp = exp;
		this->statement = statement;
	}
};

struct IfElseStatementNode : IfStatementNode{
	
	StatementNode* statement2;
	
	IfElseStatementNode(ExpNode* exp,StatementNode* statement1,StatementNode* statement2):IfStatementNode(exp,statement1){
		
		this->statement2 = statement2;
	}
};

struct WhileStatementNode : StatementNode{
	
	ExpNode* exp;
	StatementNode* statement;
		
	WhileStatementNode(ExpNode* exp,StatementNode* statement){
		this->exp = exp;
		this->statement = statement;
	}
	
};

struct BreakStatementNode : StatementNode{
	
	
};

struct CaseDecNode : Node{
	
	int num;
	bool isByte;	
	CaseDecNode(int num,bool isByte){
		this->num = num;
		this->isByte = isByte;
	}
	
	
};

struct DefaultCaseDecNode : CaseDecNode{
	
	
};

struct CaseStatementNode : StatementNode{
	
	CaseDecNode* caseDec;
	StatementNodes* statements;
	
	CaseStatementNode(CaseDecNode* caseDec){
		
		this->caseDec = caseDec;
		this->statements = new StatementNodes();
	}
};

struct SwitchStatementNode : StatementNode{
	
	ExpNode* exp;
	list<CaseStatementNode>* caseStatementNodes;
	
	SwitchStatementNode(ExpNode* exp){
		this->exp = exp;
		caseStatementNodes = new list<CaseStatementNode>();
	}
};

struct FormalDeclNode : Node
{
	EType type;
	string id;
	
	FormalDeclNode(EType type, string id)
	{
		this->type = type;
		this->id = id;
	}
};

struct FormalsListNode : Node
{
	list<FormalDeclNode*>* formalDecls;
	
	FormalsListNode()
	{
		formalDecls = new list<FormalDeclNode*>();
	}
};

struct FormalsNode : Node
{
	FormalsListNode* formalsListNode;
	
	FormalsNode(FormalsListNode* formalsListNode)
	{
		this->formalsListNode = formalsListNode;
	}
};


struct FuncNode : Node
{
	TypeNode* retType;
	IdNode* id;
	FormalsNode* formalsNode;
	StatementNodes* statements;
	
	FuncNode(TypeNode* retType, IdNode* id)
	{
		this->retType = retType;
		this->id = id;
		this->formalsNode = new FormalsNode(new FormalsListNode());
		this->statements = new StatementNodes();
	}
	
	FuncNode(TypeNode* retType, IdNode* id, FormalsNode* formalsNode, StatementNodes* statements)
	{
		this->id = id;
		this->retType = retType;
		this->formalsNode = formalsNode;
		this->statements = statements;
	}
};

struct FuncsListNode : Node
{
	list<FuncNode*>* funcsList;
	
	FuncsListNode()
	{
		funcsList = new list<FuncNode*>();
	}
};


#define YYSTYPE Node*

#endif