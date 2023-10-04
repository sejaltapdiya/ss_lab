/*
================================================================================================================
Name : Program10.c
Author : Sejal Tapadiya
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
	a. check the return value of lseek
	b. open the file with od and check the empty spaces in between the data
Date: 23rd Aug, 2023.
===============================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
       	
	int fd = open("file10", O_CREAT | O_RDWR, 0744); 
	write(fd, "HELLOWORLD",10);
	lseek(fd,10,SEEK_CUR);
	write(fd, "HELLOWORLD",10);
	close(fd);
}
/*
================================================================================================================
Command used: od -c file10
Output: 
0000000   H   E   L   L   O   W   O   R   L   D  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   H   E   L   L   O   W   O   R   L   D  \n
0000037
===============================================================================================================
*/

