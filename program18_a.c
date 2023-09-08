/*
================================================================================================================
Name : Program18_b.c
Author : Sejal Tapadiya
Description : Write a program to perform Record locking.
a. Implement write lock
Date: 25th Aug, 2023.
===============================================================================================================
*/
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

int main() {
	struct {
		int train_num;
		int ticket_count;
	}dbs[3];
   	int fd, input;
   	fd = open("record.txt", O_RDWR);
   	printf("Select train number: 1, 2, 3\n");
   	scanf("%d", &input);
	struct flock lock;
   	lock.l_type = F_WRLCK;
   	lock.l_whence = SEEK_SET;
	lock.l_start = (input - 1) * sizeof(dbs);

	lock.l_len = sizeof(dbs);
   	lock.l_pid = getpid();
   	lseek(fd, (input - 1) * sizeof(dbs), SEEK_SET);
   	read(fd, &dbs, sizeof(dbs));
   	printf("Before entering critical section\n");
   	fcntl(fd, F_SETLKW, &lock);
   	printf("Current ticket count: %d\n", dbs->ticket_count);
   	dbs->ticket_count++;
   	lseek(fd, -1 * sizeof(dbs), SEEK_CUR);
   	write(fd, &dbs, sizeof(dbs));
   	printf("To book ticket, press enter\n");
   	getchar();
   	getchar();
   	lock.l_type = F_UNLCK;
   	fcntl(fd, F_SETLK, &lock);
   	printf("Ticket booked with number %d\n", dbs->ticket_count);
}
