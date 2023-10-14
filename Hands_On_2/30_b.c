/*
============================================================================
Name : 30_b.c
Author : Sejal Tapadiya
Description : . Write a program to create a shared memory.
		b. attach with O_RDONLY and check whether you are able to overwrite.
Date: 8 Oct 2023
============================================================================
*/
#include<stdio.h>  
#include<stdlib.h>  
#include<unistd.h>  
#include<sys/shm.h>  
#include<string.h>  
int main(){
	
	char buff[100];;
	int ret = shmget((key_t)2345,1024,IPC_CREAT|0744);	
 
	if(ret ==-1)
		printf("Error occured while creating the shared memory!!\n");
	else{
		printf("Created the shared memory!!\n");
		int shmid=ret;
		char *data=shmat(shmid,0,SHM_RDONLY); 
		printf("Enter the data to be stored :\n");
		int r=scanf("%s",data);// segmentation fault occurs if we try to write as its readonly

	}
	return 0;
}

