/*
======================================================================================================
Name : 21_a.c
Author : Sejal Tapadiya
Description : 21. Write two programs so that both can communicate by FIFO -Use two way communications. 
Date: 6 Oct 2023
======================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	int fd,fd2;
	char buff[80], buff2[80];
	fd=open("prog1", O_WRONLY);
	printf("Enter message from program 1:");
	scanf(" %[^\n]", buff);
	write(fd, &buff, sizeof(buff));
	fd2=open("prog2",O_RDONLY);
	read(fd2, &buff2, sizeof(buff2));
	printf("The text from program 2: %s\n", buff2);
}
