/* Program to recognize a valid variable,
which starts with a letter, followed by any number of letters or digits.
*/
%{
#include<stdio.h>
%}
%token L D
%%
var: L 	E	{printf(“Valid Variable\n”);return 0;}
E: E  L
| E  D
| 	;
%%
main()
{
	printf(“\nEnter a variable\n”);
	yyparse();
}
yyerror()
{
	printf(“\nInvalid Variable\n”);
	exit(0);
}
/*
How to run above program
$   lex 4b.l
$   yacc –d 4b.y
$   cc lex.yy.c -ll
$   ./a.out
Input & Output:
a.	Enter a variable				b. Enter a variable		
   Abcd3456					    34534ttt
   ^d						    ^d
   Valid variable				    Invalid variable

*/