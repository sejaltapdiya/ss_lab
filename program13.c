/*
================================================================================================================
Name : Program13.c
Author : Sejal Tapadiya
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select)
Date: 25th Aug, 2023.
===============================================================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main(void){
        fd_set  rfds;
        struct timeval tv;
        int retval;
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        tv.tv_sec = 10;
        tv.tv_usec = 0;
        retval = select(1, &rfds, NULL, NULL, &tv);
        if(retval == -1)
                perror("Error Occured");
        else if(retval){
                printf("Data is available for printing in 10s");
        }
        else
                printf("Data is not available for reading in 10s");
}
                                                                                                                                                                                                         
