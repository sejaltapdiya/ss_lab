/*
================================================================================================
Name : Program21.c
Author : Sejal Tapadiya
Description : Write a program, call fork and print the parent and child process id.
Date: 21st Sept, 2023.
================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    int p_id, p_pid;
    fork();
    p_id = getpid(); /*process id*/
    p_pid = getpid(); /*parent process id*/

    printf("Process ID: %d\n", p_id);

    printf("Parent Process ID: %d\n", p_pid);
	wait(0);
    return 0;
}	

