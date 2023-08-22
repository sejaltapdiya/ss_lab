#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(void){
	int fd1, fd2, fd3, fd4, fd5;
	fd1=open("file1",O_RDWR);
	fd2=open("file2",O_RDWR);
	fd3=open("file3",O_RDWR);
	fd4=open("file4",O_RDWR);
	fd5=open("file5",O_RDWR);
	printf("fd1=%d\n",fd1);
	printf("fd2=%d\n",fd2);
	printf("fd3=%d\n",fd3);
	printf("fd4=%d\n",fd4);
	printf("fd5=%d\n",fd5);
	for(;;);
}

