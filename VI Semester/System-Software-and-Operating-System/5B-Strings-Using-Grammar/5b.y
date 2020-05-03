/* Program to recognize strings aaab,abbb,ab and a using the grammar (anbn,n>=0).
*/
%{
#include<stdio.h>
%}
%token A B
%%
str: S’\n’	{return 0;}
S:A  S
| S  B
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
$   lex 5b.l
$   yacc –d 5b.y
$   cc lex.yy.c -ll
$   ./a.out
Input & Output:	
Enter a string with a’s and b’s 
aaab
^d
Valid
$ ./a.out
Enter a string with a’s and b’s
aabbbaaaa
^d
Invalid

*/
