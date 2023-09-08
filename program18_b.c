/*
================================================================================================================
Name : Program18_b.c
Author : Sejal Tapadiya
Description : Write a program to perform Record locking.
b. Implement read lock
Date: 25th Aug, 2023.
===============================================================================================================
*/#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	int fd, input;
	struct{
		int train_num;
		int ticket_count;
	}dbs[3];
	fd = open("record.txt", O_RDWR);
	printf("SELECT TRAIN NUMBER 1, 2, 3: ");
	scanf("%d", &input);
	struct flock lock;
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = (input-1)*sizeof(dbs);
	lock.l_len = sizeof(dbs);
	lock.l_pid = getpid();
	lseek(fd, (input-1)*sizeof(dbs),SEEK_SET);
	read(fd, &dbs, sizeof(dbs));
	printf("Before entering into critical section\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Current ticket Count:%d",dbs->ticket_count);
	dbs->ticket_count;
	lseek(fd, (input-1)*sizeof(dbs), SEEK_CUR);
	printf("\nPress Enter to EXIT critical section:\n");
	getchar();
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("Unlocked and out of Critical Section");
	return 0;
}
