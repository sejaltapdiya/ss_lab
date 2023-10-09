/*
============================================================================
Name : 23.c
Author : Sejal Tapadiya
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 4 Oct 2023
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(){
	long PIPE_BUF,OPEN_MAX;
	//max amount of the data that can be written atomically in the file 
	PIPE_BUF=pathconf("./",_PC_PIPE_BUF);
	//max number of files open  within a process at any time 
	OPEN_MAX=sysconf(_SC_OPEN_MAX);
	printf("max amount of the data that can be written : %ld bytes\n",PIPE_BUF);
	printf("max number of files : %ld\n",OPEN_MAX);
	return 0;
}

