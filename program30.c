/*
================================================================================================
Name : Program30.c
Author : Sejal Tapadiya
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 6th Sept, 2023.
================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include<sys/stat.h>
time_t rawtime;
struct tm *timeinfo;
int main() {
    int pid = fork();
    if(pid == 0){
    	printf("Child process\n");
    	printf("Child pid:%d\n",getpid());
    	int session_id = setsid();
    	printf("Session id:%d\n",session_id);
    	chdir("/");
    	umask(0);
    	time(&rawtime);
    	timeinfo = localtime(&rawtime);
    	while(timeinfo->tm_hour==20 && timeinfo->tm_min<10){
    		sleep(10);
    		time(&rawtime);
    		timeinfo = localtime(&rawtime);
    	}
    	if(timeinfo->tm_hour == 20 &&timeinfo->tm_min ==10){
    		system("sh $HOME/sejal/ss_lab/daemon.sh");
    		printf("Job Completed Successfully\n");
    	}
    }
    else{
    printf("Parent process completed its execution\n");
    }
}
