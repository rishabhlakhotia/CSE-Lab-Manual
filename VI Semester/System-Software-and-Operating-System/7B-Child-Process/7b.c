/* C program that creates a child process to read commands
 from the standard input and execute them/
*/
#include<stdio.h>
int main()
{
	intch,rv;
	charcmd[10];
	rv=fork();
	if(rv==0)
	{
		do
		{
			printf(“\nEnter a command\n”);
			scanf(“%s”,cmd);
			system(cmd);
			printf(“\n1 : continue\n2 : exit\n”);
			scanf(“%d”,&ch);
		}
		while(ch!=0);
	}
	else
	{
		wait(0);
		printf(“\nChild terminated\n”);
	}
return 0;
}
/*
How to run above program
$   cc lab9b.c
$   ./a.out
Output:
Child process
 Enter the command:date
Thu June 12 13:17:32 IST 2013

 Enter 1 to continue or 0 to exit:1

 Enter the command:ls
1a.sh  2a.sh  3a.sh  4a.sh  5a.sh  6a.sh  7a.sh  1b.c   2b.c   3b.c   4b.c   5b.c   6b.c   7b.c   a.out  cc    

 Enter 1 to continue or 0 to exit:1

  Enter the command:who
root     :0           Sep 10 12:54
root     pts/1        Sep 10 12:55 (:0.0)

 Enter 1 to continue or 0 to exit:1

 Enter the command:ps
  PID TTY          TIME CMD
 3620 pts/1    00:00:00 bash
 3705 pts/1    00:00:00 a.out
 3706 pts/1    00:00:00 a.out
 3711 pts/1    00:00:00 ps

 Enter 1 to continue or 0 to exit:1

 Enter the command:pwd
/root/dsce/unix

 Enter 1 to continue or 0 to exit:0
*/


