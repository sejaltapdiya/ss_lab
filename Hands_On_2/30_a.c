/*
============================================================================
Name : 30_a.c
Author : Sejal Tapadiya
Description : . Write a program to create a shared memory.
		a. write some data to the shared memory
Date: 8 Oct 2023
============================================================================
*/
#include<stdio.h>  
#include<stdlib.h>  
#include<unistd.h>  
#include<sys/shm.h>  
#include<string.h>  
int main()  
{  
	int i;  
	void *shared_memory;  
	char buff[100];  
	int shmid;  
	shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT);   
	  
	printf("Key of shared memory is %d\n",shmid);  
	shared_memory=shmat(shmid,NULL,0);   
	//process attached to shared memory segment  
	printf("Process attached at %p\n",shared_memory);   
	//this prints the address where the segment is attached with this process  
	printf("Enter some data to write to shared memory\n");  
	read(0,buff,100);
	strcpy(shared_memory,buff); //data written to shared memory  
	printf("You wrote : %s\n",(char *)shared_memory);  
}
