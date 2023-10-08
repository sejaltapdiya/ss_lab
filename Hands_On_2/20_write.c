/*
============================================================================
Name : 20_write.c
Author : Sejal Tapadiya
Description : 20. Write two programs so that both can communicate by FIFO -Use one way communication. 
Date: 3 Oct 2023
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	int fd;
	char buff[80];
	fd=open("myfifo",O_RDONLY);
	read(fd, &buff, sizeof(buff));
	printf("The text from FIFO file: %s\n", buff);
}
