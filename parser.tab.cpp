/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.ypp" /* yacc.c:339  */


	#include "output.hpp"
	#include "parser.hpp"
	#include <typeinfo>
	#include <string.h>
	#include <stdbool.h>
	#include <stack> 
	#include <iostream>
	
	//Namespaces
	using namespace std;
	using namespace output;

	typedef struct {
		string id;
		EType type;
		int offset;
		list<FormalDeclNode*>* params;  // only used for functions
		EType retType; 		// only used for functions
	}elementData;
	
	//Functions Declerations
	int yyerror(string message);
	extern int yylineno;
	extern int yylex();
	void AddScope();
	void RemoveScope();
	bool isLegalAssignment(EType type1,EType type2);
	bool checkFuncArgs(list<FormalDeclNode*>* decleration,list<ExpNode*>* callparams);
	bool checkFuncArgs2(list<EType> decleration,list<ExpNode*>* callparams);
	std::vector<string>* ListToVector(const list<FormalDeclNode*>* list);
	bool isExist(string elementName);
	elementData get_exists_element(string elementName);
	int insertElement(elementData& element);
	
	//Variables Defenitions
	list<list<elementData> > vartable;
	stack<int> offsets;
	static bool expListExist = false;
	static bool statementStarted = false;
	static bool insideSwitch = false;
	static bool insideWhile = false;
	static int mainFuncsCounter = 0;
	static int nextParamOffset =0;
	static EType currentRetType = E_UNDEFINED;

	

#line 116 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND = 258,
    OR = 259,
    RELOP = 260,
    BINOP = 261,
    VOID = 262,
    INT = 263,
    BYTE = 264,
    B = 265,
    BOOL = 266,
    NOT = 267,
    TRUE = 268,
    FALSE = 269,
    RETURN = 270,
    IF = 271,
    WHILE = 272,
    SWITCH = 273,
    CASE = 274,
    DEFAULT = 275,
    BREAK = 276,
    COLON = 277,
    SC = 278,
    COMMA = 279,
    LPAREN = 280,
    RPAREN = 281,
    LBRACE = 282,
    RBRACE = 283,
    ASSIGN = 284,
    NUM = 285,
    ID = 286,
    STRING = 287,
    ELSE = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,   104,   105,   112,   135,   136,   111,   164,
     165,   167,   168,   170,   170,   191,   192,   194,   199,   200,
     202,   202,   204,   220,   239,   251,   252,   260,   270,   278,
     278,   269,   280,   290,   279,   296,   305,   313,   313,   304,
     315,   316,   316,   318,   319,   321,   322,   324,   354,   368,
     387,   392,   398,   399,   400,   402,   404,   427,   438,   447,
     457,   472,   480,   481,   482,   490,   498,   506
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "OR", "RELOP", "BINOP", "VOID",
  "INT", "BYTE", "B", "BOOL", "NOT", "TRUE", "FALSE", "RETURN", "IF",
  "WHILE", "SWITCH", "CASE", "DEFAULT", "BREAK", "COLON", "SC", "COMMA",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "ASSIGN", "NUM", "ID", "STRING",
  "ELSE", "$accept", "Prog", "Funcs", "FuncDecl", "$@1", "@2", "@3",
  "RetType", "Formals", "FormalsList", "$@4", "FormalsTail", "FormalDecl",
  "Statements", "Statement", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "$@11", "$@12", "$@13", "IfContinue", "$@14", "CaseList", "CaseDec",
  "Call", "CheckFunc", "ExpList", "Type", "Exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -13

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      96,   -35,   -35,   -35,   -35,    17,   -35,    96,   -29,   -35,
     -35,   -35,   -35,    -2,   -35,     3,    10,   -35,    11,   -35,
      27,    26,    31,   -35,   -35,   -35,   102,   -35,   112,    35,
      39,    42,    49,   -35,    19,    38,   -35,    54,    50,   134,
     -35,   -35,   -35,   134,    72,    59,   -35,   -35,    29,   134,
     134,   134,   -35,   102,   -35,   134,   -35,   -35,   -35,    -8,
     -35,     2,   -35,   134,   134,   134,   134,   -35,   164,   164,
     164,    81,   126,    70,   -35,   134,   -35,   110,    37,    79,
     -35,    68,    69,    74,   -35,   -35,    75,     7,   -35,   157,
     -35,   -35,    60,   -35,   134,   -35,   102,   102,   -35,   -35,
     -35,   -35,    87,    88,    92,    99,    87,   -35,   -35,    -6,
     -35,   -35,   102,   106,   102,   107,   -35,   102,   111,   -35,
     113,   108,   118,   -35,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    10,    52,    53,    54,     0,     2,     3,     0,     9,
       1,     4,     5,     0,     6,    13,     0,    11,     0,     7,
      16,     0,     0,    13,    14,    17,     0,    15,     0,     0,
       0,     0,     0,    20,     0,     0,    19,     0,     0,     0,
      62,    63,    26,     0,    59,    57,    61,    58,     0,     0,
       0,     0,    35,     0,    49,     0,     8,    18,    25,     0,
      64,     0,    60,     0,     0,     0,     0,    27,    28,    32,
      36,     0,     0,     0,    22,     0,    55,    66,    65,    67,
      56,     0,     0,     0,    21,    48,     0,    51,    24,     0,
      29,    33,     0,    47,     0,    23,     0,     0,    37,    50,
      30,    34,     0,    40,     0,     0,    44,    41,    31,     0,
      38,    43,     0,     0,     0,     0,    42,     0,     0,    39,
       0,     0,     0,    45,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -35,   -35,   129,   -35,   -35,   -35,   -35,   -35,   -35,   122,
     -35,   -35,   -35,    97,   -34,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,    43,   -35,   -26,   -35,
      77,    61,   -25
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    13,    15,    22,     8,    16,    17,
      18,    24,    20,    35,    36,    53,    81,    96,   103,    82,
      97,    83,   102,   115,   108,   112,   105,   106,    47,    72,
      86,    38,    87
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    57,    12,    48,   113,    63,    64,    65,    66,    37,
      63,    64,    65,    66,    60,    74,   114,    10,    61,     2,
       3,    75,     4,    14,    68,    69,    70,    37,    76,   -12,
      73,    94,    63,    64,    65,    66,    19,    57,    77,    78,
      79,    80,    65,    66,    54,    37,     2,     3,    55,     4,
      89,    23,    67,    28,    29,    30,    31,    25,    26,    32,
      49,     9,   100,   101,    50,    33,    56,    51,     9,    34,
      37,    37,    52,    63,    64,    65,    66,    58,   116,    21,
     118,    59,    62,   120,    54,    66,    37,    98,    37,     2,
       3,    37,     4,    88,    90,    91,    28,    29,    30,    31,
      92,    93,    32,     1,     2,     3,   104,     4,    33,    84,
       2,     3,    34,     4,    64,    65,    66,    28,    29,    30,
      31,   107,   109,    32,    39,    40,    41,   110,   117,    33,
     119,   123,   121,    34,   122,    42,    11,    43,    39,    40,
      41,   124,    44,    45,    46,    27,    39,    40,    41,   111,
      71,    43,    85,     0,     0,     0,    44,    45,    46,    43,
      63,    64,    65,    66,    44,    45,    46,    63,    64,    65,
      66,    99,     0,     0,     0,     0,     0,     0,     0,     0,
      95
};

static const yytype_int8 yycheck[] =
{
      26,    35,    31,    28,    10,     3,     4,     5,     6,    35,
       3,     4,     5,     6,    39,    23,    22,     0,    43,     8,
       9,    29,    11,    25,    49,    50,    51,    53,    26,    26,
      55,    24,     3,     4,     5,     6,    26,    71,    63,    64,
      65,    66,     5,     6,    25,    71,     8,     9,    29,    11,
      75,    24,    23,    15,    16,    17,    18,    31,    27,    21,
      25,     0,    96,    97,    25,    27,    28,    25,     7,    31,
      96,    97,    23,     3,     4,     5,     6,    23,   112,    18,
     114,    31,    10,   117,    25,     6,   112,    27,   114,     8,
       9,   117,    11,    23,    26,    26,    15,    16,    17,    18,
      26,    26,    21,     7,     8,     9,    19,    11,    27,    28,
       8,     9,    31,    11,     4,     5,     6,    15,    16,    17,
      18,    33,    30,    21,    12,    13,    14,    28,    22,    27,
      23,    23,    21,    31,    21,    23,     7,    25,    12,    13,
      14,    23,    30,    31,    32,    23,    12,    13,    14,   106,
      53,    25,    26,    -1,    -1,    -1,    30,    31,    32,    25,
       3,     4,     5,     6,    30,    31,    32,     3,     4,     5,
       6,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    11,    35,    36,    37,    41,    65,
       0,    36,    31,    38,    25,    39,    42,    43,    44,    26,
      46,    65,    40,    24,    45,    31,    27,    43,    15,    16,
      17,    18,    21,    27,    31,    47,    48,    62,    65,    12,
      13,    14,    23,    25,    30,    31,    32,    62,    66,    25,
      25,    25,    23,    49,    25,    29,    28,    48,    23,    31,
      66,    66,    10,     3,     4,     5,     6,    23,    66,    66,
      66,    47,    63,    66,    23,    29,    26,    66,    66,    66,
      66,    50,    53,    55,    28,    26,    64,    66,    23,    66,
      26,    26,    26,    26,    24,    23,    51,    54,    27,    64,
      48,    48,    56,    52,    19,    60,    61,    33,    58,    30,
      28,    60,    59,    10,    22,    57,    48,    22,    48,    23,
      48,    21,    21,    23,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    38,    39,    40,    37,    41,
      41,    42,    42,    44,    43,    45,    45,    46,    47,    47,
      49,    48,    48,    48,    48,    48,    48,    48,    50,    51,
      52,    48,    53,    54,    48,    48,    55,    56,    57,    48,
      58,    59,    58,    60,    60,    61,    61,    62,    62,    63,
      64,    64,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     0,     0,    11,     1,
       1,     1,     0,     0,     3,     2,     0,     2,     2,     1,
       0,     4,     3,     5,     4,     2,     2,     3,     0,     0,
       0,     9,     0,     0,     7,     2,     0,     0,     0,    11,
       0,     0,     3,     2,     1,     6,     7,     5,     4,     0,
       3,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     1,     1,     1,     2,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 95 "parser.ypp" /* yacc.c:1646  */
    {
		if(mainFuncsCounter != 1)
		{
			errorMainMissing();
			exit(1);
		}
	}
#line 1381 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 104 "parser.ypp" /* yacc.c:1646  */
    { (yyval) = new FuncsListNode(); }
#line 1387 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 106 "parser.ypp" /* yacc.c:1646  */
    {
		(yyval) = ((FuncsListNode*)(yyvsp[0]));
		((FuncsListNode*)(yyval))->funcsList->push_front((FuncNode*)(yyvsp[-1]));
	}
#line 1396 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 112 "parser.ypp" /* yacc.c:1646  */
    {
			string idVal = ((IdNode*)(yyvsp[0]))->id;

			if(isExist(idVal))
			{
				errorDef(yylineno,idVal);
				exit(1);
			}
			elementData data = 
			{
				idVal,
				E_FUNC,
				0,
				new list<FormalDeclNode*>(),
				E_UNDEFINED
			};
			if(insertElement(data) != 0){
				errorDef(yylineno,idVal);
				exit(1);
			}
			currentRetType = ((TypeNode*)(yyvsp[-1]))->type;
			nextParamOffset = 0;
		}
#line 1424 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 135 "parser.ypp" /* yacc.c:1646  */
    { AddScope(); }
#line 1430 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 136 "parser.ypp" /* yacc.c:1646  */
    {
			string idVal = ((IdNode*)(yyvsp[-5]))->id;
			elementData data = 
			{
				idVal,
				E_FUNC,
				0,
				((FormalsNode*)(yyvsp[-2]))->formalsListNode->formalDecls,
				((TypeNode*)(yyvsp[-6]))->type
			};
			
			if( idVal == "main" && ((TypeNode*)(yyvsp[-6]))->type == E_VOID && ((FormalsNode*)(yyvsp[-2]))->formalsListNode->formalDecls->empty())
			{
				mainFuncsCounter++;
			}
			
			// TODO: if(updateFuncParams(data) == false)
			// {
				// std::cout << "error in FuncDel " << std::endl;
				// exit(1);
			// }
		}
#line 1457 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 158 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval) = new FuncNode((TypeNode*)(yyvsp[-10]), (IdNode*)(yyvsp[-9]), (FormalsNode*)(yyvsp[-6]), (StatementNodes*)(yyvsp[-3]));
			currentRetType = E_UNDEFINED;
			RemoveScope();
		}
#line 1467 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 164 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = (TypeNode*)(yyvsp[0]);}
#line 1473 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 165 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new TypeNode(E_VOID);}
#line 1479 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 167 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new FormalsNode((FormalsListNode*)(yyvsp[0]));}
#line 1485 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 168 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new FormalsNode(new FormalsListNode());}
#line 1491 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 170 "parser.ypp" /* yacc.c:1646  */
    {nextParamOffset--;}
#line 1497 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 171 "parser.ypp" /* yacc.c:1646  */
    { 	
				elementData data = 
				{
					((FormalDeclNode*)(yyvsp[-1]))->id,
					((FormalDeclNode*)(yyvsp[-1]))->type,
					nextParamOffset,
					new list<FormalDeclNode*>(),
					E_UNDEFINED
				};  
				if((insertElement(data) != 0)){
					errorDef(yylineno,((FormalDeclNode*)(yyvsp[-1]))->id);
					exit(1);
				}
				offsets.top()--;
				nextParamOffset++;
								
				(yyval) = ((FormalsListNode*)(yyvsp[0]));
				((FormalsListNode*)(yyval))->formalDecls->push_front((FormalDeclNode*)(yyvsp[-1]));
			}
#line 1521 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 191 "parser.ypp" /* yacc.c:1646  */
    { (yyval) = ((FormalsListNode*)(yyvsp[0])); }
#line 1527 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 192 "parser.ypp" /* yacc.c:1646  */
    { (yyval) = new FormalsListNode(); }
#line 1533 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 195 "parser.ypp" /* yacc.c:1646  */
    { 
				(yyval) = new FormalDeclNode(((TypeNode*)(yyvsp[-1]))->type,((IdNode*)(yyvsp[0]))->id);
			}
#line 1541 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 202 "parser.ypp" /* yacc.c:1646  */
    { AddScope(); }
#line 1547 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 202 "parser.ypp" /* yacc.c:1646  */
    { RemoveScope(); }
#line 1553 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 205 "parser.ypp" /* yacc.c:1646  */
    { 	
				elementData data = 
				{
					((IdNode*)(yyvsp[-1]))->id,
					((TypeNode*)(yyvsp[-2]))->type,
					offsets.top(),
					new list<FormalDeclNode*>(),
					E_UNDEFINED
				};  
				if((insertElement(data) != 0)){
					errorDef(yylineno,((IdNode*)(yyvsp[-1]))->id);
					exit(1);
				}
			}
#line 1572 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 221 "parser.ypp" /* yacc.c:1646  */
    { 
				elementData data = 
				{
					((IdNode*)(yyvsp[-3]))->id,
					((TypeNode*)(yyvsp[-4]))->type,
					offsets.top(),
					new list<FormalDeclNode*>(),
					E_UNDEFINED
				};  
				if((insertElement(data) != 0)){
					errorDef(yylineno,((IdNode*)(yyvsp[-3]))->id);
					exit(1);
				}
				if(isLegalAssignment(((ExpNode*)(yyvsp[-1]))->expType,((TypeNode*)(yyvsp[-4]))->type) == false){
					errorMismatch(yylineno);
					exit(1);
				}
			}
#line 1595 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 240 "parser.ypp" /* yacc.c:1646  */
    {
				if(isExist(((IdNode*)(yyvsp[-3]))->id) == false || get_exists_element(((IdNode*)(yyvsp[-3]))->id).type == E_FUNC){
					errorUndef(yylineno,((IdNode*)(yyvsp[-3]))->id);
					exit(1);	
				}
				if(isLegalAssignment(((ExpNode*)(yyvsp[-1]))->expType,get_exists_element(((IdNode*)(yyvsp[-3]))->id).type) == false){
					errorMismatch(yylineno);
					exit(1);
				}
			
			}
#line 1611 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 253 "parser.ypp" /* yacc.c:1646  */
    {
				if(currentRetType != E_VOID)
				{
					errorMismatch(yylineno);
					exit(1);
				}
			}
#line 1623 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 261 "parser.ypp" /* yacc.c:1646  */
    {
				if(((ExpNode*)(yyvsp[0]))->expType != currentRetType)
				{
					errorMismatch(yylineno);
					exit(1);
				
				}
			}
#line 1636 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 270 "parser.ypp" /* yacc.c:1646  */
    { 
				statementStarted = true;
				if(((ExpNode*)(yyvsp[0]))->expType != E_BOOLEAN)
				{
					errorMismatch(yylineno);
					exit(1);
				}

			}
#line 1650 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 278 "parser.ypp" /* yacc.c:1646  */
    { AddScope(); }
#line 1656 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 278 "parser.ypp" /* yacc.c:1646  */
    { RemoveScope(); }
#line 1662 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 280 "parser.ypp" /* yacc.c:1646  */
    {
				statementStarted = true;
				insideWhile = true;
				if(((ExpNode*)(yyvsp[0]))->expType != E_BOOLEAN)
				{
					errorMismatch(yylineno);
					exit(1);
				}
				
			}
#line 1677 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 290 "parser.ypp" /* yacc.c:1646  */
    { AddScope(); }
#line 1683 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 291 "parser.ypp" /* yacc.c:1646  */
    { 
				RemoveScope(); 
				statementStarted = false;
				insideWhile = false;
			}
#line 1693 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 297 "parser.ypp" /* yacc.c:1646  */
    {
				if(insideSwitch == false && insideWhile == false)
				{
					errorUnexpectedBreak(yylineno);
					exit(1);
				}
			}
#line 1705 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 305 "parser.ypp" /* yacc.c:1646  */
    {
				EType expType = ((ExpNode*)(yyvsp[0]))->expType;
				if(expType != E_INTEGER && expType != E_BYTE)
				{
					errorMismatch(yylineno);
					exit(1);
				}
			}
#line 1718 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 313 "parser.ypp" /* yacc.c:1646  */
    {AddScope(); insideSwitch = true;}
#line 1724 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 313 "parser.ypp" /* yacc.c:1646  */
    {RemoveScope();insideSwitch = false;}
#line 1730 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 315 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1736 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 316 "parser.ypp" /* yacc.c:1646  */
    { AddScope(); }
#line 1742 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 316 "parser.ypp" /* yacc.c:1646  */
    { RemoveScope(); }
#line 1748 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 325 "parser.ypp" /* yacc.c:1646  */
    {
			string idVal = ((IdNode*)(yyvsp[-4]))->id;
			elementData data = get_exists_element(idVal);
			if(idVal == "print" || idVal == "printi")
			{
					list<EType> decleration = list<EType>();
					idVal == "print" ? decleration.push_back(E_STRING) : decleration.push_back(E_INTEGER);
	
					if(checkFuncArgs2(decleration,((ExpListNode*)(yyvsp[-4]))->params) == false)
					{
						vector<string> v = vector<string>();
						idVal == "print" ? v.push_back("STRING") : v.push_back("INT");;
						errorPrototypeMismatch(yylineno,idVal,v);
						exit(1);
					}
				(yyval) = new CallNode((IdNode*)(yyvsp[-4]),E_VOID);
			}
			else{
				if(checkFuncArgs(data.params,((ExpListNode*)(yyvsp[-4]))->params) == false )
				{
						errorPrototypeMismatch(yylineno,idVal,*(ListToVector(data.params)));
						exit(1);
						
				}
				(yyval) = new CallNode((IdNode*)(yyvsp[-4]),data.retType);
			}
	
	
		}
#line 1782 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 355 "parser.ypp" /* yacc.c:1646  */
    {
			string idVal = ((IdNode*)(yyvsp[-3]))->id;
			elementData data = get_exists_element(idVal);
	
			if(data.params->size() != 0)
			{
				errorPrototypeMismatch(yylineno,idVal,*(ListToVector(data.params)));
				exit(1);
			}
			(yyval) = new CallNode((IdNode*)(yyvsp[-3]),data.retType);
		}
#line 1798 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 368 "parser.ypp" /* yacc.c:1646  */
    {
		
		string idVal = ((IdNode*)(yyvsp[(-1) - (0)]))->id;
		if(idVal != "print" && idVal != "printi"){
			if(isExist(idVal) == false)
			{
				errorUndefFunc(yylineno,idVal);
				exit(1);
			}
			elementData data = get_exists_element(idVal);
			if(data.type != E_FUNC)
			{
				errorUndefFunc(yylineno,idVal);
				exit(1);
			}
		}

	}
#line 1821 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 388 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval) = (yyvsp[-1]);
			(((ExpListNode*)(yyval))->params)->push_front((ExpNode*)(yyvsp[-2]));
		}
#line 1830 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 393 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval) = new ExpListNode();
			(((ExpListNode*)(yyval))->params)->push_front((ExpNode*)(yyvsp[0]));
		}
#line 1839 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 398 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new TypeNode(E_INTEGER);}
#line 1845 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 399 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new TypeNode(E_BYTE);}
#line 1851 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 400 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new TypeNode(E_BOOLEAN);}
#line 1857 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 402 "parser.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1863 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 405 "parser.ypp" /* yacc.c:1646  */
    { 
			cout << "Binop exp started " << endl;
			
			
			if((((ExpNode*)(yyvsp[-2])))->expType != E_INTEGER && (((ExpNode*)(yyvsp[-2])))->expType != E_BYTE)
			{
				errorMismatch(yylineno);
				exit(1);
			}
			if((((ExpNode*)(yyvsp[-2])))->expType != (((ExpNode*)(yyvsp[0])))->expType)
			{
				errorMismatch(yylineno);
				exit(1);
			}
			
			(yyval) = new BinExpNode(((ExpNode*)(yyvsp[-2])),(BinOpNode*)(yyvsp[-1]),((ExpNode*)(yyvsp[0]))); 
			((ExpNode*)(yyval))->expType = (((ExpNode*)(yyvsp[-2])))->expType;
			
			cout << "Binop exp finished" << endl;

		}
#line 1889 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 428 "parser.ypp" /* yacc.c:1646  */
    {
			cout << "ID exp started" << endl;
			if(isExist(((IdNode*)(yyvsp[0]))->id) == false || get_exists_element(((IdNode*)(yyvsp[0]))->id).type == E_FUNC){
						errorUndef(yylineno,((IdNode*)(yyvsp[0]))->id);
						exit(1);
			}
				
			(yyval) = new IdExpNode((IdNode*)(yyvsp[0]),get_exists_element(((IdNode*)(yyvsp[0]))->id).type); 
			cout << "ID exp finished" << endl;
		}
#line 1904 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 439 "parser.ypp" /* yacc.c:1646  */
    {
			if(((CallNode*)(yyvsp[0]))->callType == E_VOID){
				errorMismatch(yylineno);
				exit(1);
			}
			// Get funcDecl by Id and Check RetType of FuncDecl
			((ExpNode*)(yyval))->expType = ((CallNode*)(yyvsp[0]))->callType;
		}
#line 1917 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 448 "parser.ypp" /* yacc.c:1646  */
    { 
			cout << "NUM exp started" << endl;
			
			(yyval) = new NumExpNode((NumNode*)(yyvsp[0])); 
			
			cout << "NUM exp finished" << endl;

		}
#line 1930 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 458 "parser.ypp" /* yacc.c:1646  */
    {
			cout << "NUM B exp started" << endl;

			if(((NumNode*)(yyvsp[-1]))->num > 255){
				string str = "" + ((NumNode*)(yyvsp[-1]))->num;
				errorByteTooLarge(yylineno,str);
				exit(1);
			}
			(yyval) = new NumBExpNode((NumNode*)(yyvsp[-1])); 
			
			cout << "NUM B exp finished" << endl;

		}
#line 1948 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 473 "parser.ypp" /* yacc.c:1646  */
    {
			cout << "String exp started" << endl;
			(yyval) = new StringExpNode((StringNode*)(yyvsp[0])); 
			cout << "String exp finished" << endl;
		}
#line 1958 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 480 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new BoolExpNode((BoolNode*)(yyvsp[0]));}
#line 1964 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 481 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new BoolExpNode((BoolNode*)(yyvsp[0]));}
#line 1970 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 483 "parser.ypp" /* yacc.c:1646  */
    {
			if((((ExpNode*)(yyvsp[0])))->expType != E_BOOLEAN){
				errorMismatch(yylineno);
				exit(1);
			 }
			(yyval) = new NotExpNode(((ExpNode*)(yyvsp[0])));
		}
#line 1982 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 491 "parser.ypp" /* yacc.c:1646  */
    {
			if(((ExpNode*)(yyvsp[-2]))->expType != E_BOOLEAN || ((ExpNode*)(yyvsp[0]))->expType != E_BOOLEAN ){
				errorMismatch(yylineno);
				exit(1);
			 }
			 (yyval) = new ExpNode(E_BOOLEAN);
		}
#line 1994 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 499 "parser.ypp" /* yacc.c:1646  */
    {
			if(((ExpNode*)(yyvsp[-2]))->expType != E_BOOLEAN || ((ExpNode*)(yyvsp[0]))->expType != E_BOOLEAN ){
				errorMismatch(yylineno);
				exit(1);
			 }
			 (yyval) = new ExpNode(E_BOOLEAN);
		}
#line 2006 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 507 "parser.ypp" /* yacc.c:1646  */
    {
			if(((ExpNode*)(yyvsp[-2]))->expType != E_INTEGER || ((ExpNode*)(yyvsp[0]))->expType != E_INTEGER ){
				errorMismatch(yylineno);
				exit(1);
			 }
			 (yyval) = new ExpNode(E_BOOLEAN);
		}
#line 2018 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2022 "parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 514 "parser.ypp" /* yacc.c:1906  */


int main()
{
	cout << "Main: " << endl;
	int result = yyparse();
	return result ; 
}

int yyerror(string message)
{
	cout << "Error: " << endl;
	errorSyn(yylineno);
	exit(1);
}

bool isLegalAssignment(EType fromType , EType toType)
{
	if((fromType == E_UNDEFINED) || (toType == E_UNDEFINED) ) {
		std::cout << "error in isLegalAssignment " << std::endl;
		exit(1);
	}
	if(fromType == toType)
		return true;
	if((fromType == E_BYTE) && (toType == E_INTEGER))
		return true;
	
	return false;
}

std::vector<string>* ListToVector(const list<FormalDeclNode*>*  list )
{
	std::vector<string>* vec = new vector<string>();
	for(std::list<FormalDeclNode*>::const_iterator it= list->begin(); it!= list->end();++it){
		string var_type;
		switch((*it)->type){
			case E_INTEGER : var_type = "INT";
							break;
			case E_BOOLEAN : var_type = "BOOL";
							break;
			case E_BYTE :	 var_type = "BYTE";
							break;
			case E_STRING : var_type = "STRING";
							break;
			default : 
					std::cout << "error in ListToVector undefined variable"<<std::endl;
					exit(1);
		}
		vec->push_back(var_type);
	}
	return vec;
}

bool isExist(string elementId)
{
	list<list<elementData> >::const_iterator end = vartable.end();
	for(list<list<elementData> >::const_iterator element = vartable.begin()  ; element!=end ;  element++ )
	{
		list<elementData>::const_iterator lend = (*element).end();
		for(list<elementData>::const_iterator lentry = (*element).begin()  ; lentry != lend ; lentry++)
		{
			if((*lentry).id == elementId ) 
				return true ;
		}
	}
	return false ; 
}
elementData get_exists_element(string elementId){
	
	list<list<elementData> >::const_iterator end = vartable.end();
	for(list<list<elementData> >::const_iterator element = vartable.begin()  ; element!=end ;  element++ )
	{
		 list<elementData>::const_iterator lend = (*element).end();
		for(list<elementData>::const_iterator elementData = (*element).begin()  ; elementData != lend ; elementData++)
		{
			if((*elementData).id == elementId ) 
				return (*elementData) ;
		}
	}
}

bool checkFuncArgs(list<FormalDeclNode*>* decleration,list<ExpNode*>* callparams){

	if(decleration->size() != callparams->size()) return false;
	list<ExpNode*>::const_iterator element2 = callparams->begin();
	for(list<FormalDeclNode*>::const_iterator element = decleration->begin()  ; element!=decleration->end() ;  ++element ,++element2)
	{	
		if(!isLegalAssignment((*element2)->expType,(*element)->type)) return false;
	}
	return true;
}

bool checkFuncArgs2(list<EType> decleration,list<ExpNode*>* callparams){

	if(decleration.size() != callparams->size()) return false;
	list<ExpNode*>::const_iterator element2 = callparams->begin();
	for(list<EType>::const_iterator element = decleration.begin()  ; element!=decleration.end() ;  ++element ,++element2)
	{	
		if(!isLegalAssignment((*element2)->expType,*element)) return false;
	}
	return true;
}

void AddScope(){

	vartable.push_front(list<elementData>());
	offsets.push(offsets.size()==0 ? 0 :offsets.top());
}
void RemoveScope(){
	endScope();
	list<elementData> current_scope = vartable.front();

	vartable.pop_front();
	offsets.pop(); 

    list<elementData>::reverse_iterator lend = current_scope.rend();
	for(list<elementData>::reverse_iterator lentry = current_scope.rbegin()  ; lentry != lend ; lentry++){
	
	elementData var = *lentry;
		string retType;
		
		if(var.type == E_FUNC){
			
			switch(var.retType){
				case E_INTEGER :		retType = "INT";   break;
				case E_BOOLEAN :		retType = "BOOL";  break;
				case E_BYTE    : 		retType = "BYTE";  break;
				case E_VOID    :		retType = "VOID";  break;
				default : 				std::cout << "error in RemoveScope1 undefined variable"<<std::endl; exit(1); break;
			}
		}
		string var_type;
		switch(var.type){
			case E_INTEGER :			var_type = "INT";  break;
			case E_BOOLEAN :			var_type = "BOOL"; break;
			case E_BYTE    : 			var_type = "BYTE"; break;
			case E_FUNC    :			var_type = makeFunctionType(retType.c_str(),*(ListToVector(var.params))); break;
			default : 					std::cout << "error in RemoveScope2 undefined variable"<<std::endl; exit(1);
		}
		printID(var.id.c_str(),var.offset,var_type.c_str());
	}
}

int insertElement(elementData& element){
	if(isExist(element.id)){
		return -1;
	}
	if(element.id == "print" || element.id == "printi"){
		return -1;
	}
	vartable.front().push_front(element);
	
	offsets.top()++;

	return 0;
}

//bool checkExpBinOpTypes(ExpNode e1, ExpNode e2)
//{
//	if(typeid(e1).hash_code() == typeid(NumExpNode*).hash_code() || typeid(e1).hash_code() == typeid(NumBExpNode*).hash_code())
//		if(typeid(e1).hash_code() == typeid(e2).hash_code())
//			return true;
//	
//	return false;
//}

