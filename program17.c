#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(){
	int fd;
	struct {
		int ticket_no;
	}db;
	printf("Enter Ticket No.:");
	scanf("%d", &db.ticket_no);
	fd = open("db", O_CREAT| O_RDWR, 744);
	write(fd, &db, sizeof(db));
	close(fd);
	fd = open("db", O_RDONLY);
	read(fd, &db, sizeof(db));
	printf("Ticket No: %d\n", db.ticket_no);
	close(fd);
}
