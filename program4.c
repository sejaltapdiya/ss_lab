/*
================================================================================================================
Name : Program4.c
Author : Sejal Tapadiya
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 17th Aug, 2023.
===============================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(){
	int fd1, fd2;
	fd1=open("file1",O_RDWR| O_EXCL| O_RDWR);;
	fd2=open("file01",O_CREAT|O_EXCL|O_RDWR);
	printf("fd1=%d\n",fd1);
	printf("fd2=%d\n",fd2);
	close(fd1);
	close(fd2);
}
