#ifndef __ATTRIBUTES_H
#define __ATTRIBUTES_H

#include <string>
#include <list> 
using namespace std;

 enum TYPE{
	 
	A_INTEGER , A_BOOLEAN , A_BYTE , A_VOID ,A_STRING, A_FUNC , A_UNDEFINED
};

struct attribute
{
	string name;
	TYPE type; // for typr
	//Type in; // for variable
	int size;
	int breakflag;
	int value ;   // fixme : may need to change to int in order to do bounus 2 

	list<TYPE> params;
	
	// we want constructor
	attribute()
	{
		name = string("");
		type = A_UNDEFINED;
		size = -1;
		breakflag = 0;
		value = -1;
		params = list<TYPE>();
	}
	
};
typedef struct attribute STYPE; 


#define YYSTYPE STYPE	// Tell Bison to use STYPE as the stack type

#endif
