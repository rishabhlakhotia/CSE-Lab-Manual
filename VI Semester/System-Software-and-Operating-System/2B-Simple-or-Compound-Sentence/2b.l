/*
2B) Program to check whether a given sentence is simple or compound.
*/
%{
%}
ws [   \t\n]
%%
{ws}”and”|”AND”{ws} | 
{ws}”or”|”OR”{ws} | 
{ws}”but”|”BUT”{ws} |
{ws}”because”{ws} |
{ws}”nevertheless”{ws}	{printf(“\compound sentence\n”);exit(0);}
•	;
\n	return 0;
%%
main()
{
	printf(“\nEnter a sentence\n”);
	yylex();
	printf(“\nSimple sentence\n”);
}
/*
How to run above program
$   lex lab2b.l
$   cc lex.yy.c	
$   ./a.out
Input & output:
A.	 Enter a sentence			          B. Enter a sentence
I and you					You  me		
^d						^d
Compound sentence				Simple sentence
*/