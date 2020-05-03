/* Write a C/Java program to avoid zombie process by forking twice.
*/
#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
        pid_t  pid;
        if ((pid=fork())< 0)
         {
           printf("Fork  error");
         }
         else if( pid==0)
         {
         printf("first child pid=%d\n", getpid());
         if((pid=fork())< 0)
         printf("Fork  error");
         else if( pid > 0)
          exit(0);
         sleep(5);
         printf("second child pid = %d\n  parent pid=%d\n", getpid(),  getppid());
         exit (0);
        }
}

/*
**************************
Program output:
 [root@localhost ~]# vi p8b.c
[root@localhost ~]# cc 8b.c
[root@localhost ~]# ./a.out
first child pid=4071
second child pid = 4072
 parent of second child pid=4071
  PID  PPID STAT CMD
    1     0 Ss   init [5]                                              
    2     0 S<   [kthreadd]
    3     2 S<   [migration/0]
    4     2 S<   [ksoftirqd/0]
    5     2 S<   [watchdog/0]
    6     2 S<   [migration/1]
    7     2 S<   [ksoftirqd/1]
........
 4070  2686 S+   ./a.out
 4071  4070 S+   ./a.out
 4072  4071 Z+   [a.out] <defunct>
 4073  4071 R+   ps -e -o pid,ppid,stat,cmd
second child pid = 4071
 parent of second child pid=4070
*/