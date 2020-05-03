/* Program to recognize a valid arithmetic expression that uses operates +,-,*,/
*/
%{
#include<stdio.h>
%}
%token NUM ID
%left ‘+’’-‘
%left’*’’/’
%%
e:e’+’e
| e’-‘e
| e’*’e
| e’/’e
| ‘(‘e’)’
| NUM
I ID	;
%%
main()
{
	printf(“\nType the expression to be tested\n”);  
              yyparse();  
              printf(“\nValid expression\n”);
}
yyerror()
{
	printf(“\n  Invalid expression! \n”);
	exit(0);
}
/*
How to run above program
$   lex 4a.l
$   yacc –d 4a.y   // => Generates y.tab.h file
$   cc lex.yy.c –ll      // => -ll links with lex library
$   ./a.out	

Input & Output:
Enter an arithmetic expression
a1+b2-9/8
^d
valid expression
*/