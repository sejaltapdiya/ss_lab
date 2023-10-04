/*
=======================================================================================================
Name : 16.c
Author : Sejal Tapadiya
Description : 16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 1 Oct 2023
======================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void)
{
	char buff[80], buff1[80];
	int fd1[2], fd2[2];
	pipe(fd1);
	pipe(fd2);
	if(!fork()){
		close(fd1[0]);
		printf("Enter message to the Parent: ");
		scanf("%[^\n]",buff);
		write(fd1[1], buff, sizeof(buff));
		close(fd2[1]);
		read(fd2[0], buff1, sizeof(buff1));
		printf("Message From Parent: %s\n",buff1);
	}
	else{
		close(fd1[1]);
		read(fd1[0], buff, sizeof(buff));
		printf("Message From Child: %s\n",buff);
		close(fd2[0]);
		printf("Enter message to the Child: ");
		scanf("%[^\n]",buff1);
		write(fd2[1], buff1, sizeof(buff1));
		
	}wait(0);


}

