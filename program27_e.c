/*
================================================================================================
Name : Program27_e.c
Author : Sejal Tapadiya
Description : Write a program to execute ls -Rl by the following system calls
	      e. execvp
Date: 5th Sept, 2023.
================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	char *command = "ls";
	char *args[] = {"ls", "-Rl", NULL};
	execvp(command,args);
	perror("execvp() : ");
	exit(EXIT_FAILURE);
}

