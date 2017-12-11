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
		list<EType> params;  // only used for functions
		EType retType; 		// only used for functions
	}elementData;
	
	//Functions Declerations
	int yyerror(string message);
	extern int yylineno;
	extern int yylex();
	void CreateScope();
	void DestroyScope();
	bool isLegalAssignment(EType type1,EType type2);
	bool checkFuncArgs(list<EType> decleration,list<ExpNode*>* callparams);
	std::vector<string>* ListToVector(const list<EType> list);
	bool isExist(string elementName);
	elementData get_exists_element(string elementName);
	
	//Variables Defenitions
	list<list<elementData> > vartable;
	stack<int> offsets;
	static bool expListExist = false;
	static bool statementStarted = false;
	static bool insideSwitch = false;
	static bool insideWhile = false;
	static int mainFuncsCounter = 0;

	

#line 112 "parser.tab.cpp" /* yacc.c:339  */

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

#line 197 "parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  117

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
       0,    90,    90,    98,    99,   117,   123,   124,   126,   127,
     129,   130,   141,   143,   144,   146,   150,   154,   158,   170,
     171,   179,   188,   187,   198,   197,   213,   222,   230,   230,
     221,   232,   233,   233,   235,   236,   238,   238,   239,   239,
     241,   271,   285,   304,   309,   315,   316,   317,   319,   321,
     344,   355,   364,   374,   389,   397,   398,   399,   407,   415,
     423
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
  "ELSE", "$accept", "Prog", "Funcs", "FuncDecl", "RetType", "Formals",
  "FormalsList", "FormalDecl", "Statements", "Statement", "$@1", "$@2",
  "$@3", "$@4", "$@5", "IfContinue", "$@6", "CaseList", "CaseDec", "$@7",
  "$@8", "Call", "CheckFunc", "ExpList", "Type", "Exp", YY_NULLPTR
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

#define YYPACT_NINF -55

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-55)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     121,   121,   -55,   -55,   121,    -7,    -5,   -55,    29,   -55,
     158,   -55,     4,   -55,   -55,   -55,   121,   121,   121,   121,
     -55,   -55,   -55,   -55,   -55,    38,     5,   -55,   -55,    97,
      53,    58,    25,   -55,   -55,    30,   -55,    35,     9,    42,
     -55,   121,    50,   -55,    44,    47,   -55,    52,    42,   -55,
      87,   -55,   107,    60,    61,    63,    68,   -55,    12,    66,
     -55,    69,    70,   -55,    20,   121,   121,   121,   -55,   121,
     -55,   -55,   -55,    -1,   -55,   144,   144,   144,    67,   -55,
     121,    73,    74,    80,   -55,   137,    87,   -55,    87,    62,
     -55,    79,   -55,   -55,   -55,    88,    87,    83,    89,    88,
     -55,    17,   -55,   -55,    93,   -55,   101,   -55,    87,   -55,
      87,    95,   104,   103,   108,   -55,   -55
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    55,    56,     0,    52,    50,    54,     0,    51,
       3,    57,     0,    53,    42,     1,     0,     0,     0,     0,
       7,    45,    46,    47,     2,     3,     0,     6,    48,     0,
      59,    58,    60,    49,     4,     0,    41,     0,    44,     9,
      40,     0,     0,     8,    10,     0,    43,     0,     0,    12,
       0,    11,     0,     0,     0,     0,     0,    15,     0,     0,
      14,     0,     0,    20,     0,     0,     0,     0,    26,     0,
       5,    13,    19,     0,    21,    22,    24,    27,     0,    16,
       0,     0,     0,     0,    18,     0,     0,    23,     0,     0,
      17,    31,    25,    28,    32,     0,     0,     0,     0,    35,
      33,     0,    29,    34,     0,    36,     0,    38,     0,    30,
       0,     0,     0,     0,     0,    37,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,   111,   -55,   -55,   -55,    96,   -55,   -55,   -54,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,    46,   -55,   -55,
     -55,   -48,   -55,   113,    -4,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,    24,    25,    26,    42,    43,    44,    59,    60,
      81,    82,    83,    95,   106,    87,    96,    98,    99,   108,
     110,     9,    29,    37,    62,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      10,    11,    61,    13,    12,    71,    27,    16,    17,    18,
      19,    61,    16,    17,    18,    19,    30,    31,    32,    33,
      14,    27,    79,    16,    17,    18,    19,   104,    80,    15,
      28,    19,    91,    41,    92,    45,    35,    14,    61,   105,
      61,    69,   100,    74,    45,    20,    21,    22,    61,    23,
      21,    22,    64,    23,   111,    39,   112,    17,    18,    19,
      61,    40,    61,    18,    19,    75,    76,    77,    48,    78,
      16,    17,    18,    19,    21,    22,    47,    23,    49,    50,
      85,    52,    53,    54,    55,    65,    66,    56,    67,    93,
      84,    68,    72,    57,    70,    21,    22,    58,    23,    86,
      88,    73,    52,    53,    54,    55,    89,    97,    56,     1,
       2,     3,    94,   101,    57,   107,   113,   102,    58,     1,
       2,     3,     4,    36,   109,   114,   115,     5,     6,     7,
      63,   116,     4,     1,     2,     3,    34,     5,     6,     7,
      16,    17,    18,    19,    51,   103,     4,    16,    17,    18,
      19,     5,     6,     7,    46,     0,     0,     0,     0,     0,
      90,    16,    17,    18,    19,    20,    21,    22,     0,    23
};

static const yytype_int8 yycheck[] =
{
       0,     1,    50,    10,     4,    59,    10,     3,     4,     5,
       6,    59,     3,     4,     5,     6,    16,    17,    18,    19,
      25,    25,    23,     3,     4,     5,     6,    10,    29,     0,
      26,     6,    86,    24,    88,    39,    31,    25,    86,    22,
      88,    29,    96,    23,    48,     7,     8,     9,    96,    11,
       8,     9,    52,    11,   108,    25,   110,     4,     5,     6,
     108,    26,   110,     5,     6,    65,    66,    67,    24,    69,
       3,     4,     5,     6,     8,     9,    26,    11,    31,    27,
      80,    15,    16,    17,    18,    25,    25,    21,    25,    27,
      23,    23,    23,    27,    28,     8,     9,    31,    11,    26,
      26,    31,    15,    16,    17,    18,    26,    19,    21,    12,
      13,    14,    33,    30,    27,    22,    21,    28,    31,    12,
      13,    14,    25,    26,    23,    21,    23,    30,    31,    32,
      23,    23,    25,    12,    13,    14,    25,    30,    31,    32,
       3,     4,     5,     6,    48,    99,    25,     3,     4,     5,
       6,    30,    31,    32,    41,    -1,    -1,    -1,    -1,    -1,
      23,     3,     4,     5,     6,     7,     8,     9,    -1,    11
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    14,    25,    30,    31,    32,    35,    55,
      59,    59,    59,    10,    25,     0,     3,     4,     5,     6,
       7,     8,     9,    11,    36,    37,    38,    58,    26,    56,
      59,    59,    59,    59,    36,    31,    26,    57,    59,    25,
      26,    24,    39,    40,    41,    58,    57,    26,    24,    31,
      27,    40,    15,    16,    17,    18,    21,    27,    31,    42,
      43,    55,    58,    23,    59,    25,    25,    25,    23,    29,
      28,    43,    23,    31,    23,    59,    59,    59,    59,    23,
      29,    44,    45,    46,    23,    59,    26,    49,    26,    26,
      23,    43,    43,    27,    33,    47,    50,    19,    51,    52,
      43,    30,    28,    51,    10,    22,    48,    22,    53,    23,
      54,    43,    43,    21,    21,    23,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    38,    38,    39,    39,
      40,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      43,    43,    44,    43,    45,    43,    43,    46,    47,    48,
      43,    49,    50,    49,    51,    51,    53,    52,    54,    52,
      55,    55,    56,    57,    57,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     8,     1,     1,     1,     0,
       1,     3,     2,     2,     1,     1,     3,     5,     4,     2,
       2,     3,     0,     5,     0,     6,     2,     0,     0,     0,
      11,     2,     0,     5,     2,     1,     0,     7,     0,     8,
       5,     4,     0,     3,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     2,     1,     1,     1,     2,     3,     3,
       3
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
#line 91 "parser.ypp" /* yacc.c:1646  */
    {
		//IDK what to write here...
		if(mainFuncsCounter < 1)
			errorMainMissing();
	}
#line 1365 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 98 "parser.ypp" /* yacc.c:1646  */
    {/*$$ = new FuncsListNode();*/}
#line 1371 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 100 "parser.ypp" /* yacc.c:1646  */
    {
		FuncNode* currFunc = (FuncNode*)(yyvsp[-1]);
		FormalsListNode* currFormalsList = currFunc->formalsNode->formalsListNode;
		if(((IdNode*)currFunc->id)->id == "main" && currFunc->retType->retType == E_VOID && currFormalsList->formalDecls->empty())
		{
			mainFuncsCounter++;
			if(mainFuncsCounter > 1)
				errorMainMissing();// Delete this and Threw an appropirate error...
		}
		
		if((yyvsp[0]) == NULL)
			(yyvsp[0]) = new FuncsListNode();
		
		(yyval) = (FuncsListNode*)(yyvsp[0]);
		((FuncsListNode*)(yyval))->funcsList->push_back(*currFunc);
	}
#line 1392 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 118 "parser.ypp" /* yacc.c:1646  */
    {
			// Check if return Statements return the appropirate type
			// Check Formals IDs conflict
		}
#line 1401 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 123 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = (RetTypeNode*)(yyvsp[0]);}
#line 1407 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 124 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new VoidTypeNode();}
#line 1413 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new FormalsNode((FormalsListNode*)(yyvsp[0]));}
#line 1419 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 127 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1425 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 129 "parser.ypp" /* yacc.c:1646  */
    {  }
#line 1431 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 131 "parser.ypp" /* yacc.c:1646  */
    {
				FormalDeclNode* currFormalDecl = (FormalDeclNode*)(yyvsp[-2]);
				
				if((yyvsp[0]) == NULL)
					(yyvsp[0]) = new FormalsListNode();
		
				(yyval) = (FormalsListNode*)(yyvsp[-1]);
				((FormalsListNode*)(yyval))->formalDecls->push_back(*currFormalDecl);
			}
#line 1445 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 141 "parser.ypp" /* yacc.c:1646  */
    { (yyval) = new FormalDeclNode((TypeNode*)(yyvsp[-1]),(IdNode*)(yyvsp[0]));}
#line 1451 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 147 "parser.ypp" /* yacc.c:1646  */
    {
	
			}
#line 1459 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 151 "parser.ypp" /* yacc.c:1646  */
    { 	

			}
#line 1467 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 155 "parser.ypp" /* yacc.c:1646  */
    { 

			}
#line 1475 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 159 "parser.ypp" /* yacc.c:1646  */
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
#line 1491 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 172 "parser.ypp" /* yacc.c:1646  */
    {
				//TODO : need to check if last functionDecl returns void
				/*
					errorMismatch(yylineno);
					exit(1);
				*/
			}
#line 1503 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 180 "parser.ypp" /* yacc.c:1646  */
    {
				//TODO : need to check if last functionDecl returns a type same as expType
				/*
					errorMismatch(yylineno);
					exit(1);
				*/
			}
#line 1515 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 188 "parser.ypp" /* yacc.c:1646  */
    { 
				statementStarted = true;
				if(((ExpNode*)(yyvsp[0]))->expType != E_BOOLEAN)
				{
					errorMismatch(yylineno);
					exit(1);
				}

			}
#line 1529 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 198 "parser.ypp" /* yacc.c:1646  */
    {
				statementStarted = true;
				insideWhile = true;
				if(((ExpNode*)(yyvsp[0]))->expType != E_BOOLEAN)
				{
					errorMismatch(yylineno);
					exit(1);
				}
				
			}
#line 1544 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 209 "parser.ypp" /* yacc.c:1646  */
    {
				statementStarted = false;
				insideWhile = false;
			}
#line 1553 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 214 "parser.ypp" /* yacc.c:1646  */
    {
				if(insideSwitch == false && insideWhile == false)
				{
					errorUnexpectedBreak(yylineno);
					exit(1);
				}
			}
#line 1565 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 222 "parser.ypp" /* yacc.c:1646  */
    {
				EType expType = ((ExpNode*)(yyvsp[0]))->expType;
				if(expType != E_INTEGER && expType != E_BYTE)
				{
					errorMismatch(yylineno);
					exit(1);
				}
			}
#line 1578 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 230 "parser.ypp" /* yacc.c:1646  */
    {CreateScope(); insideSwitch = true;}
#line 1584 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 230 "parser.ypp" /* yacc.c:1646  */
    {DestroyScope();insideSwitch = false;}
#line 1590 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 232 "parser.ypp" /* yacc.c:1646  */
    {statementStarted = false;}
#line 1596 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 233 "parser.ypp" /* yacc.c:1646  */
    {statementStarted = true;}
#line 1602 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 233 "parser.ypp" /* yacc.c:1646  */
    {statementStarted = false;}
#line 1608 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 238 "parser.ypp" /* yacc.c:1646  */
    {statementStarted = true;}
#line 1614 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 238 "parser.ypp" /* yacc.c:1646  */
    {statementStarted = false;}
#line 1620 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 239 "parser.ypp" /* yacc.c:1646  */
    {statementStarted = true;}
#line 1626 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 239 "parser.ypp" /* yacc.c:1646  */
    {statementStarted = false;}
#line 1632 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 242 "parser.ypp" /* yacc.c:1646  */
    {
			string idVal = ((IdNode*)(yyvsp[-4]))->id;
			elementData data = get_exists_element(idVal);
			if(idVal == "print" || idVal == "printi")
			{
					list<EType> decleration = list<EType>();
					idVal == "print" ? decleration.push_back(E_STRING) : decleration.push_back(E_INTEGER);
	
					if(checkFuncArgs(decleration,((ExpListNode*)(yyvsp[-4]))->params) == false)
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
#line 1666 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 272 "parser.ypp" /* yacc.c:1646  */
    {
			string idVal = ((IdNode*)(yyvsp[-3]))->id;
			elementData data = get_exists_element(idVal);
	
			if(data.params.size() != 0)
			{
				errorPrototypeMismatch(yylineno,idVal,*(ListToVector(data.params)));
				exit(1);
			}
			(yyval) = new CallNode((IdNode*)(yyvsp[-3]),data.retType);
		}
#line 1682 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 285 "parser.ypp" /* yacc.c:1646  */
    {
		
		string idVal = ((IdNode*)(yyvsp[0]))->id;
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
#line 1705 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 305 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval) = (yyvsp[-1]);
			(((ExpListNode*)(yyval))->params)->push_front((ExpNode*)(yyvsp[-2]));
		}
#line 1714 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 310 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval) = new ExpListNode();
			(((ExpListNode*)(yyval))->params)->push_front((ExpNode*)(yyvsp[0]));
		}
#line 1723 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 315 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new TypeNode(E_INTEGER);}
#line 1729 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 316 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new TypeNode(E_BYTE);}
#line 1735 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 317 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new TypeNode(E_BOOLEAN);}
#line 1741 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 319 "parser.ypp" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1747 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 322 "parser.ypp" /* yacc.c:1646  */
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
#line 1773 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 345 "parser.ypp" /* yacc.c:1646  */
    {
			cout << "ID exp started" << endl;
			if(isExist(((IdNode*)(yyvsp[0]))->id) == false || get_exists_element(((IdNode*)(yyvsp[0]))->id).type == E_FUNC){
						errorUndef(yylineno,((IdNode*)(yyvsp[0]))->id);
						exit(1);
			}
				
			(yyval) = new IdExpNode((IdNode*)(yyvsp[0]),get_exists_element(((IdNode*)(yyvsp[0]))->id).type); 
			cout << "ID exp finished" << endl;
		}
#line 1788 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 356 "parser.ypp" /* yacc.c:1646  */
    {
			if(((CallNode*)(yyvsp[0]))->callType == E_VOID){
				errorMismatch(yylineno);
				exit(1);
			}
			// Get funcDecl by Id and Check RetType of FuncDecl
			((ExpNode*)(yyval))->expType = ((CallNode*)(yyvsp[0]))->callType;
		}
#line 1801 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 365 "parser.ypp" /* yacc.c:1646  */
    { 
			cout << "NUM exp started" << endl;
			
			(yyval) = new NumExpNode((NumNode*)(yyvsp[0])); 
			
			cout << "NUM exp finished" << endl;

		}
#line 1814 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 375 "parser.ypp" /* yacc.c:1646  */
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
#line 1832 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 390 "parser.ypp" /* yacc.c:1646  */
    {
			cout << "String exp started" << endl;
			(yyval) = new StringExpNode((StringNode*)(yyvsp[0])); 
			cout << "String exp finished" << endl;
		}
#line 1842 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 397 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new BoolExpNode((BoolNode*)(yyvsp[0]));}
#line 1848 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 398 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = new BoolExpNode((BoolNode*)(yyvsp[0]));}
#line 1854 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 400 "parser.ypp" /* yacc.c:1646  */
    {
			if((((ExpNode*)(yyvsp[0])))->expType != E_BOOLEAN){
				errorMismatch(yylineno);
				exit(1);
			 }
			(yyval) = new NotExpNode(((ExpNode*)(yyvsp[0])));
		}
#line 1866 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 408 "parser.ypp" /* yacc.c:1646  */
    {
			if(((ExpNode*)(yyvsp[-2]))->expType != E_BOOLEAN || ((ExpNode*)(yyvsp[0]))->expType != E_BOOLEAN ){
				errorMismatch(yylineno);
				exit(1);
			 }
			 (yyval) = new ExpNode(E_BOOLEAN);
		}
#line 1878 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 416 "parser.ypp" /* yacc.c:1646  */
    {
			if(((ExpNode*)(yyvsp[-2]))->expType != E_BOOLEAN || ((ExpNode*)(yyvsp[0]))->expType != E_BOOLEAN ){
				errorMismatch(yylineno);
				exit(1);
			 }
			 (yyval) = new ExpNode(E_BOOLEAN);
		}
#line 1890 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 424 "parser.ypp" /* yacc.c:1646  */
    {
			if(((ExpNode*)(yyvsp[-2]))->expType != E_INTEGER || ((ExpNode*)(yyvsp[0]))->expType != E_INTEGER ){
				errorMismatch(yylineno);
				exit(1);
			 }
			 (yyval) = new ExpNode(E_BOOLEAN);
		}
#line 1902 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 1906 "parser.tab.cpp" /* yacc.c:1646  */
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
#line 431 "parser.ypp" /* yacc.c:1906  */


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
	if(fromType == toType) return true;
	if((fromType == E_BYTE) && (toType == E_INTEGER) ) return true;
	return false;
}

std::vector<string>* ListToVector(const list<EType>  list )
{
	std::vector<string>* vec = new vector<string>();
	for(std::list<EType>::const_iterator it= list.begin(); it!= list.end();++it){
		string var_type;
		switch(*it){
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

bool checkFuncArgs(list<EType> decleration,list<ExpNode*>* callparams){

	if(decleration.size() != callparams->size()) return false;
	list<ExpNode*>::const_iterator element2 = callparams->begin();
	for(list<EType>::const_iterator element = decleration.begin()  ; element!=decleration.end() ;  ++element ,++element2)
	{	
		if(!isLegalAssignment((*element2)->expType,*element)) return false;
	}
	return true;
}
void CreateScope(){

	vartable.push_front(list<elementData>());
	offsets.push(offsets.size()==0 ? 0 :offsets.top());
}
void DestroyScope(){
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
				default : 				std::cout << "error in DestroyScope1 undefined variable"<<std::endl; exit(1); break;
			}
		}
		string var_type;
		switch(var.type){
			case E_INTEGER :			var_type = "INT";  break;
			case E_BOOLEAN :			var_type = "BOOL"; break;
			case E_BYTE    : 			var_type = "BYTE"; break;
			case E_FUNC    :			var_type = makeFunctionType(retType.c_str(),*(ListToVector(var.params))); break;
			default : 					std::cout << "error in DestroyScope2 undefined variable"<<std::endl; exit(1);
		}
		printID(var.id.c_str(),var.offset,var_type.c_str());
	}
}

//bool checkExpBinOpTypes(ExpNode e1, ExpNode e2)
//{
//	if(typeid(e1).hash_code() == typeid(NumExpNode*).hash_code() || typeid(e1).hash_code() == typeid(NumBExpNode*).hash_code())
//		if(typeid(e1).hash_code() == typeid(e2).hash_code())
//			return true;
//	
//	return false;
//}

