/*
================================================================================================================
Name : Program3.c
Author : Sejal Tapadiya
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
Date: 17th Aug, 2023.
===============================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd;
	fd=creat("myfile",S_IRUSR | S_IWUSR);
	printf("fd=%d\n",fd);
	close(fd);
}
