#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(){
	int fd1, fd2;
	fd1=open("file1",O_RDWR);
	fd2=open("file2",O_EXCL);
	printf("fd1=%d\n",fd1);
	printf("fd2=%d\n",fd2);
}
