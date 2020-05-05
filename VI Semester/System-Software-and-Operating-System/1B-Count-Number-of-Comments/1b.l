/*
1b) Program to count the number of comment lines in a given C Program. 
Also eliminate them and copy it to a separate file. 
*/
%{ 
int cc=0; 
%} 
%x CMNT 
%% 
"/*"    {BEGIN CMNT;} 
<CMNT>• ; 
<CMNT>\n        ; 
<CMNT>"*/"      {BEGIN 0; cc++;} 
%% 
 
int yywrap(void){} 
main(int argc,char *argv[]) 
{ 
        if(argc!=3) 
        { 
                printf("Usage : %s      <scr_file>      <dest_file>\n",argv[0]); 
                return; 
        } 
        yyin=fopen(argv[1],"r"); 
        yyout=fopen(argv[2],"w"); 
        yylex(); 
        printf("\nNumber of multiline comments = %d\n",cc); 
} 

/*
How to run above program
$   lex 1b.l
$   cc lex.yy.c
$   ./a.out abc abc1

Input and output:
$ cat > abc
/* my prog*/
//Prog1
// to say hi to the user
/* also say hello to the user*/
main()
{
Printf(“hi”);
Printf(“hello”);
}
^d
$ lex 1b.l
$ cc lex.yy.c –ll
$./a. Number of comment lines1 (//)=2
Number of comment lines2 (/*) =2
$ cat abc1
main()
{
Printf(“hi”); Printf(“hello”);
}
*/