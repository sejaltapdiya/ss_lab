/*
================================================================================================================
Name : Program9.c
Author : Sejal Tapadiya
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 23rd Aug, 2023.
===============================================================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Incorrect number of arguments, Enter file name");
		return 0;
	}
	struct stat s;
	int fd_read = open(argv[1], O_RDONLY);
	stat(argv[1],&s);
	printf("1. Inode number: %ld\n",s.st_ino);
	printf("2. Number of hard links: %ld\n",s.st_nlink);
	printf("3. uid: %d\n",s.st_uid);
	printf("4. gid: %d\n",s.st_gid);
	printf("5. size: %ld\n",s.st_size);
	printf("6. block size: %ld\n",s.st_blksize);
	printf("7. number of blocks: %ld\n",s.st_blocks);
	printf("8. time of last access : %s",ctime(&s.st_atime));
	printf("9. time of last modification: %s",ctime(&s.st_mtime));
	printf("10. time of last change: %s",ctime(&s.st_ctime));

}
