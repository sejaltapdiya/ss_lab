#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd;
	fd=creat("myfile",S_IRUSR | S_IWUSR);
	printf("fd=%d\n",fd);
}
