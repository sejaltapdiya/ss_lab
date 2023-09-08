/*
================================================================================================
Name : Program24.c
Author : Sejal Tapadiya
Description : Write a program to create an orphan process.
Date: 1st Sept, 2023.
================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
        pid_t pid=fork();
        if(pid==-1)
        {
                perror("fork() error");
        }
        if(pid==0)
        {
                printf("Child process Created:%d\n",getpid());
                sleep(5);
                printf("Exiting Child process:%d\n",getpid());
        }
        else
        {
                printf("Parent process Created:%d\n",getpid());
                sleep(3);
                printf("Exiting Parent process:%d\n",getpid());
        }
        return 0;
}

