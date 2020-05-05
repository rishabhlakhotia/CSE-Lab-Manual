/* Program to evaluate an arithmetic expression involving operators +,-,*,/
*/
%{
#include<stdio.h>
%}
%token NUM
%left ‘+’’-‘
%left ‘/’’*’
%%
expr:e		{printf(“Valid expression\n”);
		printf(“\nResult : %d\n”,$1);return 0;}
e:e’+’e		{$$=$1+$3;}
| e’-‘e		{$$=$1-$3;}
| e’*’e		{$$=$1*$3;}
| e’/’e		{$$=$1/$3;}
| ‘(‘e’)’		{$$=$2;}
| NUM		{$$=$1;}
%
main()
{
	printf(“\nEnteran arithmetic expression\n”);
	yyparse();
}

yyerror()
{	
	printf(“\nInvalid expression\n”);
	exit(0);
}
/*
How to run above program
$   lex 3b.l
$   yacc -d 3b.y
$   cc lex.yy.c -ll
$   ./a.out

Input & Output:	
Enter an arithmetic expression to be evaluated
2+3
^d
5

*/