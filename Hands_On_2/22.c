/*
============================================================================
Name : 22.c
Author : Sejal Tapadiya
Description : 22.  Write a program to wait for data to be written into FIFO within 10 seconds, use select 
system call with FIFO. 
Date: 3 Oct 2023
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/time.h>

int main()
{
        int fd, retval;
        char buf[80];
        fd_set rfds;
        struct timeval tv;

        fd=open("myfifo22",O_RDONLY| O_CREAT| O_EXCL);
        FD_ZERO(&rfds);
        FD_SET(fd,&rfds);
        tv.tv_sec=10;
        tv.tv_usec=0;
        retval=select(fd+1,&rfds,NULL,NULL,&tv);
        if(retval)
                printf("Data is available now.....\n");
        else {
                printf("No data is available within 10 second...\n");
                exit(0);
        }
        read(fd,buf,sizeof(buf));
        printf("The text from FIFO: %s\n", buf);
        return 0;

}
