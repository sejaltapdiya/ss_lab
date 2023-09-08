/*
================================================================================================
Name : Program20.c
Author : Sejal Tapadiya
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 21st Sept, 2023.
================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/resource.h>
int main(void){

	printf("The Priority of current process is: %d\n",getpriority(PRIO_PROCESS, 0));
	nice(5);
	printf("The modified Priority = %d\n", getpriority(PRIO_PROCESS, 0));
}

