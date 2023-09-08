/*
================================================================================================================
Name : Program6.c
Author : Sejal Tapadiya
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 23rd Aug, 2023.
===============================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	char buf[100];
	int char_read = read(STDIN_FILENO,buf,100);
	write(STDOUT_FILENO,buf, char_read);
	return 0;
}

