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

struct Type : Node
{
	EType etype;
	
	Type(EType etype)
	{
		this->etype = etype;
	}
};

struct RetType : Node
{
	bool isVoid;
	Type type;

	RetType(Type type)
	{
		this->type = type;
		if(type == null)
			isVoid = false;
	}
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

struct Expr : Node
{
	Expr expr;
	Id id;
	
	Expr(Expr expr, Id id)
	{
		this->expr = expr;
		this->id = id;
	}
}

struct Statment : Node
{
	
}

struct DeclStatment : Node
{
	Type type;
	Id id;
	
	DeclStatment(Type type, Id id)
	{
		this->type = type;
		this->id = id;
	}
}

struct AssignStatment : Node
{
	Expr expr;
	Id id;
	
	AssignStatment(Expr expr, Id id)
	{
		this->expr = expr;
		this->id = id;
	}
}

struct Statments : Node
{
	list<Statment> statments;
	
	Statments()
	{
		this->statments = new list<Statment>();
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