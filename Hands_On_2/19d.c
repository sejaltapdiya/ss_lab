/*
=======================================================================================================
Name : 19d.c
Author : Sejal Tapadiya. 
Description : Create a FIFO file by
	      d.mknod system call
Date: 2 Oct 2023
======================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void){
	int f = mknod("FIFO", S_IFIFO, 0);
	if(f<0){
		perror("Failed");
	}
	close(f);
}


