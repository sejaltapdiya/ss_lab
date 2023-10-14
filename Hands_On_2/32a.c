/*=======================================================================================================
Name : 32a.c
Author : Sejal Tapadiya
Description :Write a program to implement semaphore to protect any critical section.
	     a. rewrite the ticket number creation program using semaphore
Date: 11 oct 2023
======================================================================================================*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// Define semaphore operations
struct sembuf acquire_lock = { 0, -1, SEM_UNDO };
struct sembuf release_lock = { 0, 1, SEM_UNDO };

int main() {
    struct ticket {
        int ticketNumber;
    };
    struct ticket t;

    // Create or retrieve a semaphore set
    int semid = semget((key_t)8888, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("SEMGET ERROR");
        return -1;
    }

    // Initialize semaphore value to 1 (unlocked)
    semctl(semid, 0, SETVAL, 1);

    printf("*****WAITING TO BOOK TICKETS*****\n");
    printf("*****BOOKING IN PROGRESS*****\n");

    // Acquire the lock
    semop(semid, &acquire_lock, 1);

    int fd = open("ticketNumber.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("OPEN ERROR");
        semop(semid, &release_lock, 1); // Release the lock in case of an error
        return -1;
    }

    // Read the ticket information from the file
    read(fd, &t, sizeof(t));
    t.ticketNumber++; // Increment the current ticket number

    // Set the file pointer to the beginning
    lseek(fd, 0, SEEK_SET);

    // Update the file with the new ticket number
    write(fd, &t, sizeof(t));
    printf("Press Enter to book the ticket:\n");

    getchar();
    printf("YOUR TICKET NUMBER = %d\n", t.ticketNumber);

    // Release the lock
    semop(semid, &release_lock, 1);
    printf("*****TICKET BOOKED*****\n");

    // Close the file
    close(fd);

    return 0;
}



