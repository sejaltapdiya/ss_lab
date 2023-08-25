#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
	int flags, accessmode;
	int fd = open("file2", O_RDWR);
	flags = fcntl(fd, F_GETFL);
	if(flags == -1){
		exit(0);
	}
	if(flags & O_SYNC){
		printf("Writes are Synchronized\n");
	}
	accessmode = flags & O_ACCMODE;
	if(accessmode == O_RDONLY)
		printf("file is readonly\n");
	else if(accessmode == O_WRONLY)
		printf("File is Write only\n");
	else if(accessmode == O_RDWR)
		printf("File is Read and Write\n");
}
