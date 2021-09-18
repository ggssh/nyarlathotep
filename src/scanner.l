%{
#define YYSTYPE char *
#include <stdio.h>
%}

DIGIT 		[0-9]+
IDENTIFIER 	[a-zA-Z][a-zA-Z0-9]*
OP			["+"|"-"|"*"|"/"|":"|"="|"!"|">"|"<"]
COMMA		","
SEMICOLON	";"
DOT			"."
/*
CONST		"CONST"|
VAR			[]
PROCEDURE
CALL
BEGIN
END
IF
THEN
WHILE
DO
ODD
*/

%%
"CONST"|"VAR"|"PROCEDURE"|"CALL"|"BEGIN"|"END"|"IF"|"THEN"|"WHILE"|"DO"|"ODD"      printf( "A keyword: %s\n", yytext );

"const"|"var"|"procedure"|"call"|"begin"|"end"|"if"|"then"|"while"|"do"|"odd"      printf( "A keyword: %s\n", yytext );

{DIGIT}     printf( "An integer: %s\n", yytext);

{IDENTIFIER}        printf( "An identifier: %s\n", yytext );

{OP}        printf( "An operator: %s\n", yytext );

[ \t\n]+	/*吃掉空格*/

{COMMA}		printf( "An comma: %s\n", yytext);

{SEMICOLON} printf( "An semicolon: %s\n", yytext);

{DOT}		printf( "An dot: %s\n", yytext);

.			printf("Unregonized words : %s\n",yytext);
%%

int main(int argc, char ** argv){
	if(argc<0){
		yyin = stdin;
	}else{
		yyin = fopen(argv[1],"r");
	}

	yylex();
}

int yywrap(void)
{
	return 1;
}