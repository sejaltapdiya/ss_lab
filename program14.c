/*
================================================================================================================
Name : Program14.c
Author : Sejal Tapadiya
Description : Write a program to find the type of a file.
	      a. Input should be taken from command line.
  	      b. program should be able to identify any type of a file
Date: 25th Aug, 2023.
===============================================================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc, char **argv) {
        struct stat *st;
        st = (struct stat *) malloc(sizeof(struct stat));
 
        stat(argv[1], st);
 
        if(S_ISDIR(st->st_mode))
                printf("file type is : Directory\n");
        else if (S_ISCHR(st->st_mode))
                printf("file type is : Character device\n");
        else if (S_ISBLK(st->st_mode))
                printf("file type is : Block device\n");
        else if (S_ISREG(st->st_mode))
                printf("file type is : Regular file\n");
        else if (S_ISFIFO(st->st_mode))
                printf("file type is : FIFO or Pipe\n");
        else if (S_ISLNK(st->st_mode))
                printf("file type is : Symbolic link\n");
        else if (S_ISSOCK(st->st_mode))
                printf("file type is : Socket\n");
        return 0;
}

