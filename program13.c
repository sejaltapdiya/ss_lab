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
                                                                                                                                                                                                         
