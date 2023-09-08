/*
================================================================================================
Name : Program22.c
Author : Sejal Tapadiya
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 21st Sept, 2023.
================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
FILE *fp; int fd;
char ch;
fp=fopen("file22","w");
fprintf(fp,"%s\n","This line is written by Parent\n");
fflush(NULL);
fd=fork();
if(fd<0)
{
	printf("Fork Error");
	exit(1);
}
if(fd==0)
{
	fprintf(fp,"%s","This line is written by Child\n");
	fclose(fp);
	fp=fopen("file22","r");
	while(!feof(fp))
		printf("%c",getc(fp));

}
if(fd>0)
{
	if(fd!=wait(NULL))
	{	perror("Parent failed to wait due to signal or error");
		return 1;
	}
}
fclose(fp);
return 0;
}
