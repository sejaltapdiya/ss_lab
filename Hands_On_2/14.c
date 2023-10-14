/*=======================================================================================================
Name : 14.c
Author : Sejal Tapadiya
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 1 oct 2023
======================================================================================================*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	int filedes[2];
	char buf[100];
	if(pipe(filedes)==-1)
	{
		printf("Pipe not found");
	}
	write(filedes[1],"Hello\n",6);
	read(filedes[0],buf,6);
	printf("%s",buf);
	return 0;
}
