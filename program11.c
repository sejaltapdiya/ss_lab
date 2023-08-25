#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(void){
	int fd1, dupfd, dup2fd, newfd;
	fd1 = open("file3.txt", O_RDWR|O_CREAT);
	dupfd = dup(fd1);
	dup2fd = dup2(fd1, 7);
	newfd = fcntl(fd1,  F_DUPFD, 8);
	printf("Original Descriptor: %d\n", fd1);
	printf("Duplicate Descriptor using dup: %d\n", dupfd);
	printf("Duplicate Descriptor using dup2: %d\n", dup2fd);
	printf("fcntl Descriptor : %d\n", newfd);
	//adding original file descripto in file
	char buf[10],buf2[10],buf3[10],buf4[10];
	int n = sprintf(buf,"%d",  fd1);
	write(fd1, "original descriptor: ",20);
	write(fd1, buf, n);
	//adding dup fd
	int n2 = sprintf(buf2, "%d", dupfd);
	write(dupfd, "\nDuplicate descritor (dup):",27);
	write(dupfd, buf2, n2);
	//adding dup2 fd
	int n3 = sprintf(buf3, "%d",dup2fd);
	write(dup2fd,"\nDuplicate descriptor (dup2):", 29);
	write(dup2fd, buf3, n3);
	//writing fcntl fd
	int n4 = sprintf(buf4, "%d", newfd);
	write(newfd, "\nfcntl descriptor:",18 );
	write(newfd, buf4, n4);
	/*closing all fd's*/
	close(fd1);
	close(dupfd);
	close(dup2fd);
	close(newfd);
}
