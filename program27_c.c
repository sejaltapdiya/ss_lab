/*
================================================================================================
Name : Program27_c.c
Author : Sejal Tapadiya
Description : Write a program to execute ls -Rl by the following system calls
	      c. execle
Date: 5th Sept, 2023.
================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void){
	char *envp[] ={ "PATH=/bin:/usr/bin", NULL};
	execle("/bin/ls","ls", "-Rl", NULL, envp);
	perror("excle() not executed");
	exit(EXIT_FAILURE);
}


