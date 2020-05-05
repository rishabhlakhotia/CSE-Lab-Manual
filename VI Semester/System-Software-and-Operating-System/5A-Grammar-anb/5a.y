/* Program to recognize the grammar (anb, n>=10).
*/
%{
#include<stdio.h>
%}
%token A B
%%
str: S’\n’	{return 0;}
S:X  B
X: A  AAAAAAAAA  T;
T:T  A
|	;
%%
main()
{
	printf(“\nEnter a string\n”);
	yyparse();
	printf(“\nEntered string is valid\n”);
}
yyerror()
{
	printf(“\nInvalid!\n”);
	exit(0);
}
/*
How to run above program
$   lex 5a.l
$   yacc –d 5a.y
$   cc lex.yy.c -ll
$   ./a.out
Input & Output:	
Enter a string with a’s and b’s
aaaaaaaaaaaaaaab
^d
Valid
$./a.out
Enter a string with a’s and b’s
aabbbaaaa
^d
Invalid
*/