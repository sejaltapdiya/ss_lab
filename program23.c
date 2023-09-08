/*
================================================================================================
Name : Program23.c
Author : Sejal Tapadiya
Description : Write a program to create a Zombie state of the running program.
Date: 1st Sept, 2023.
================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int pid = fork();
	if(pid>0){
		printf("Parent process id: %d\n", pid);
		printf("Parent process entering into sleep...\n");
		sleep(20);
		printf("Parent process Wakes up\n");
	}
	else{
		printf("Child process id: %d\n", pid);
		printf("Process is in Zombie State\n");
	}
}

