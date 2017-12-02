#ifndef __PARSER_HPP
#define __PARSER_HPP

#include <string>
#include <list> 

using namespace std;

struct Node 
{
	
};

enum EType
{
	E_INT, E_BOOL, E_BYTE 
};

enum BinOp{
	PLUS,MINUS,MUL,DIV,AND,OR,EQ,NEQ,BG,SM,BGE,SME
};

struct RetType : Node
{
	
};

struct Type : RetType
{
	EType etype;
	
	Type(EType etype)
	{
		this->etype = etype;
	}
};

struct VoidType : RetType
{
	
};
	
struct Id : Node
{
	string name;
	
	Id(string name)
	{
		this->name = name;
	}
};	
	
struct FormalDecl : Node
{
	Type type;
	Id id;
	
	FormalDecl(Type type, Id id)
	{
		this->type = type;
		this->id = id;
	}
};

struct FormalsList : Node
{
	list<FormalDecl> formalDecls;
	
	FormalsList()
	{
		formalDecls = new list<FormalDecl>();
	}
};

struct Formals : Node
{
	FormalsList formalsList;
	
	Formals(FormalsList formalsList)
	{
		this->formalsList = formalsList;
	}
};

struct Exp : Node
{

};
struct IdExp : Exp
{
	Id id;
	
	IdExp(Id id){
		this->id = id;
	}
};
struct NumExp : Exp{
	
	int num;
	
	NumExp(int num){
		this->num = num;
	}
	
};
struct NumBExp : NumExp{
	
	NumBExp(int num): num(num){
		
	}
	
};

struct StringExp:Exp{
	
	string str;
	
	StringExp(string str){
		this->str = str;
	}
		
};

struct BoolExp: Exp{
	
	bool b;
	
	BoolExp(Bool b){
		this->b = b;
	}
};

struct NotExp : Exp{
	
	Exp exp;
	
	NotExp(Exp exp){
		this->exp = exp;
	}
};

struct BinExp : Exp
{
	Exp exp1;
	BinOp op;
	Exp exp2;
	
	BinExp(Exp exp1,BinOp op ,Exp exp2){
		this->exp1 = exp1;
		this->op = op;
		this->exp2 = exp2;
	}
	
};

struct CallExp : Exp{
	
	Call call;
	
	CallExp(Call call){
		this->call = call;
	}
	
};

struct Call : Node
{
	
	Id id;
	list<Exp> expList;
	
	Call(Id id){
		this->id = id;
		expList = new list<Exp>();
	}
};

struct Statement : Node
{
	
};

struct DeclStatement : Statement
{
	Type type;
	Id id;
	
	DeclStatement(Type type, Id id)
	{
		this->type = type;
		this->id = id;
	}
};

struct AssignStatement : Statement
{
	Exp exp;
	Id id;
	
	AssignStatement(Exp exp, Id id)
	{
		this->exp = exp;
		this->id = id;
	}
};

struct Statements : Node
{
	list<Statement> Statements;
	
	Statements()
	{
		this->Statements = new list<Statement>();
	}
};

struct CallStatement : Statement{
	
	Call call;
	
	CallStatement(Call call){
		this->call = call;
	}	
	
};

struct ReturnStatement : Statement{
	
	Exp exp;
	
	ReturnStatement(){
		this->exp = NULL;
	}
	ReturnStatement(Exp exp){
		this->exp = exp;
	}
};

struct IfStatement:Statement{
	
	Exp exp;
	Statement statement;
	
	IfStatement(Exp exp,Statement statement){
		this->exp = exp;
		this->statement = statement;
	}
	
};

struct IfElseStatement:IfStatement{
	
	Statement statement2;
	
	IfElseStatement(Exp exp,Statement statement1,Statement statement2):exp(exp),statement(statement1){
		
		this->statement2 = statement2;
	}
	
	
};

struct WhileStatement : Statement{
	
	Exp exp;
	Statement statement;
	
	
	WhileStatement(Exp exp,Statement statement){
		this->exp = exp;
		this->statement = statement;
	}
	
};

struct BreakStatement:Statement{
	
	
};

struct CaseDec:Node{
	
	int num;
	bool isByte;	
	public CaseDec(int num,bool isByte){
		this->num = num;
		this->isByte = isByte;
	}
	
	
};
struct DefaultCaseDec:CaseDec{
	
	
};

struct CaseStatement:Statement{
	
	CaseDec caseDec;
	list<Statement> statements;
	public CaseStatement(CaseDec caseDec){
		
		this->caseDec = caseDec;
		this->statements = new list<Statement>();
	}
};

struct SwitchStatement:Statement{
	
	Exp exp;
	list<CaseStatement> caseStatements;
	
	SwitchStatement(Exp exp){
		this->exp =exp;
		caseStatements = new List<CaseStatement>();
		
	}
};


struct Func : Node
{
	RetType retType;
	
	Func(RetType retType, ID id, Formals formals, )
	{
		
	}
	
};
		
	

	

#define YYSTYPE Node*	

#endif