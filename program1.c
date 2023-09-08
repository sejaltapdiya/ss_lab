/*
============================================================================
Name : Program1.c
Author : Sejal Tapadiya
Description : 1. Create the following types of a files using (i) shell command (ii) system call
	a. soft link (symlink system call)
	b. hard link (link system call)
	c. FIFO (mkfifo Library Function or mknod system call)
Date: 17th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int v = symlink("dest", "destSL");
	if(v<0){
		perror("Failed to create Soft link: ");
		return 1;
	}
	int f = link("dest","destHl");
	if(f<0){
		perror("Failed creating Hard link: ");
		return 1;
	}
	int e = mknod("destFIFO: ", S_IFIFO,0);
	if(e<0)
		perror("Failed: \n");
	return 0;
}
