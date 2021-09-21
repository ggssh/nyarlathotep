%{
#define YYSTYPE char *
#include <stdio.h>
%}

/*整型*/
DIGIT 		[0-9]+
/*标识符*/
IDENTIFIER 	[a-zA-Z][a-zA-Z0-9]*
/*关键字 11个*/
BEGIN		"BEGIN"|"begin"
END			"END"|"end"
IF			"IF"|"if"
THEN		"THEN"|"then"
WHILE		"WHILE"|"while"
DO			"DO"|"do"
CONST		"CONST"|"const"
VAR			"VAR"|"var"
CALL		"CALL"|"call"
PROCEDURE	"PROCEDURE"|"procedure"
ODD			"ODD"|"odd"
/*运算符和界符 14个*/
PLUS		"+"
MINUS		"-"
MULTIPLE	"*"
DIVIDE		"/"
EQUAL		"="
NUMBER_SIGN	"#"
LARROW		"<"
RARROW		">"
ASSIGN		":="
LPAREN		"("
RPAREN		")"
COMMA		","
DOT			"."
SEMICOLON	";"


// TODO 将获得的TOKEN返回给语法分析器
%%
 /*关键字*/
{BEGIN}  			printf( "An Keyword: %s\n", yytext);
{END}				printf( "An Keyword: %s\n", yytext);
{IF}				printf( "An Keyword: %s\n", yytext);
{THEN}				printf( "An Keyword: %s\n", yytext);
{WHILE}				printf( "An Keyword: %s\n", yytext);
{DO}				printf( "An Keyword: %s\n", yytext);
{CONST}				printf( "An Keyword: %s\n", yytext);
{VAR}				printf( "An Keyword: %s\n", yytext);
{CALL}				printf( "An Keyword: %s\n", yytext);
{PROCEDURE}			printf( "An Keyword: %s\n", yytext);
{ODD}				printf( "An Keyword: %s\n", yytext);

 /*整型数*/
{DIGIT}    		 	printf( "An integer: %s\n", yytext);
 /*标识符*/
{IDENTIFIER}        printf( "An identifier: %s\n", yytext );


[ \t\n]+			/*吃掉空格*/

{PLUS}|{MINUS}|{MULTIPLE}|{DIVIDE}|{EQUAL}|{NUMBER_SIGN}|{ASSIGN} printf( "An op: %s\n", yytext);

{LARROW}|{RARROW}|{LPAREN}|{RPAREN} printf( "An bracket: %s\n", yytext);

{COMMA}				printf( "An comma: %s\n", yytext);

{SEMICOLON} 		printf( "An semicolon: %s\n", yytext);

{DOT}				printf( "An dot: %s\n", yytext);

 /*others*/
.					printf("Unregonized words : %s\n",yytext);
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