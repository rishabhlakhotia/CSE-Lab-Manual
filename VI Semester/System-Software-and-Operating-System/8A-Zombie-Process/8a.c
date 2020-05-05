/* Write a C/Java program that creates a zombie and then calls system to 
execute the ps command to verify that the process is zombie.
*/
#include<stdio.h>
        #include <stdlib.h>
        #include <sys/types.h>
        #include <unistd.h>
        int main()
        {
                pid_t child_pid;
                                        /* Create a child process. */
                child_pid = fork ();
                if (child_pid > 0)
                {
                        printf("This is the parent process: %d. Sleep for a minute\n",getpid());
                        sleep (60);
                }
                else
                {
                        printf("This is the child process: %d. Exit immediately\n",getpid());
                        exit (0);
                }
                        system("ps -e -o pid,ppid,stat,cmd");
                       return 0;
        }
/*
**************************
Program output:
 [root@localhost ~]# vim 8a.c
[root@localhost ~]# cc 8a.c
[root@localhost ~]# ./a.out
This is the child process: 8822. Exit immediately
This is the parent process: 8821. Sleep for a minute
  PID  PPID STAT CMD
    1     0 Ss   init [5]         
    2     0 S<   [kthreadd]
    3     2 S<   [migration/0]
    4     2 S<   [ksoftirqd/0]
    5     2 S<   [watchdog/0]
    6     2 S<   [migration/1]
    7     2 S<   [ksoftirqd/1]
....
 8788  8782 SN   sleep 506
 8798  2793 T    vim p7.c
 8821  2793 S+   ./a.out
 8822  8821 Z+   [a.out] <defunct>                           
 8825  8821 R+   ps -e -o pid,ppid,stat,cmd
*/