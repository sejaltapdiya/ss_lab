/*
================================================================================================================
Name : Program8.c
Author : Sejal Tapadiya
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
	      Close the file when end of file is reached.
Date: 23rd Aug, 2023.
===============================================================================================================
*/
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc,char* argv[]){
int fd_read;
char buf[200];
fd_read=open(argv[1],O_RDONLY);
int ind=0,read_char=0;
buf[0]='\0';
while(1){

read_char=read(fd_read,&buf[ind],1);

if(buf[ind]=='\n')
{
        write(STDOUT_FILENO,&buf,ind+1);
	
	ind=-1;
	for(int i=0;i<ind;i++){
	buf[i]='\0';
	}
}
ind++;
if(read_char==0)
        break;
}


close(fd_read);
return 0;
}
