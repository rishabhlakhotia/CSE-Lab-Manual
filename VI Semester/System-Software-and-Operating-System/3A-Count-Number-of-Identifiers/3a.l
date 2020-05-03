/* Program to recognize and count the number of identifiers in a given input file. */
%{
intidc=0;
%}
e[=][   ]*[0-9]+
ws[   \n\t]*
id[_a-zA-Z][_a-zA-Z0-9]*
decln	“int”|”float”|”clear”|”double”|”short”|”long”|”unsigned”
%x defn
%%
{decln}				{BEGIN defn;}
<defn>{ws}{id}{ws}\,		{idc++;}
<defn>{ws}{id}{ws}\;		{BEGIN 0;idc++;}
<defn>{ws}{id}{ws}{e}{ws}\,	{idc++;}
<defn>{ws}{id}{ws}{e}{ws}\;	{BEGIN 0;idc++;}
<*>\n		;
<*>•		;
%%
main(int argc,char *argv[])
{
	if(argc==2)
	{
		yyin=fopen(argv[1],”r”);
		yylex();
		printf(“\nNumber of identifiers = %d\n”,idc);
	}
	else
	{
		printf(“\nUsage : %s	<src_file> \n”,argv[0]);
	}
}
/*
How to run above program
$   lex 3a.l
$   cc lex.yy.c
$   ./a.out file3


Input & Output: $ cat >  myfile						$ lex 3a.l
int a, b,c;						$ cc lex.yy.c -ll
char a,b;							$ ./a.out myfile
float a1, g56;						Number of identifiers=7
^d
*/