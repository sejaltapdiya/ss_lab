#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main()
{
	struct{
		int ticket_no;
	}db;
	struct flock lock;
	int fd = open("db", O_RDWR);
	
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_pid = getpid();
	printf("Before entering into critical section\n");
        fcntl(fd, F_SETLKW, &lock);
	printf("Inside the critical section...\n");
	read(fd, &db, sizeof(db));
	printf("current Ticket Number: %d\n", db.ticket_no);
	db.ticket_no++;
	lseek(fd, 0, SEEK_SET);
        write(fd, &db, sizeof(db));
	printf("Enter to Unlock...\n");
        getchar();
        printf("unlocked\n");
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        printf("Exited Critical Section\n");
	}
