#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
       	
	int fd = open("file10", O_CREAT | O_RDWR, 0744); 
	write(fd, "HELLOWORLD",10);
	lseek(fd,10L,SEEK_CUR);
	write(fd, "HELLOWORLD",10);
	close(fd);
}

