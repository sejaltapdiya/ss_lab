/*
============================================================================
Name : 26.c
Author : Sejal Tapadiya
Description : 26. Write a program to send messages to the message queue. Check $ipcs -q
Date: 5 Oct 2023
============================================================================
*/
#include<string.h>
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdlib.h>
struct msg {
	long int m_type;
	char message[80];
} myq;
int main(void){
	key_t key;
	size_t size;
	int mqid;
	key = ftok(".", 'a');
        mqid = msgget(key, 0);
        printf("Enter message type: ");
	scanf("%ld", &myq.m_type);
	printf("Enter message text:");
	scanf(" %[^\n]", myq.message);
	size = strlen(myq.message);
	// size + 1 to accommodate terminating character
	msgsnd(mqid, &myq, size + 1, 0);
}
