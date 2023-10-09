/*
============================================================================
Name : 27_a.c
Author : Sejal Tapadiya
Description : 27. Write a program to receive messages from the message queue.
a. with 0 as a flag
Date: 6 Oct 2023
============================================================================
*/
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
	int mqid;
	key = ftok(".", 'a');
        mqid = msgget(key, 0);
        printf("Enter message type: ");
        scanf("%ld", &myq.m_type);
        int rec = msgrcv(mqid, &myq, sizeof(myq.message), myq.m_type, 0);

        if (rec == -1)
   		exit(-1);
	printf("Message: %s\n", myq.message);
}
