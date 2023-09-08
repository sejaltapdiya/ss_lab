/*
================================================================================================
Name : Program25.c
Author : Sejal Tapadiya
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 5th Sept, 2023.
================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
	pid_t p;
	printf("Before fork\n");
	p=fork();
	if(p==0){
		printf("I am chlid1 process: %d\n", getpid());
		printf("My parent ID: %d\n", getppid());

	}	
	else{
		pid_t q;
		printf("Inside first fork\n");
		q=fork();
		if(q==0){
			printf("I am chlid2 process: %d\n", getpid());
			printf("My parent ID: %d\n", getppid());
		}
		else{
			pid_t r;
			printf("Inside second fork\n");
			r=fork();
			if(r==0){
        			sleep(10);
				printf("I am child3 process: %d\n", getpid());
				printf("My parent ID: %d\n", getppid());
				printf("Created 3 child Proceses\n");
			}
			else{
        			waitpid(r,WIFEXITED(2), WCONTINUED);
				printf("Parent of all the Child Process: %d\n", getpid());
			}

		}
	}
}
