/*=======================================================================================================
Name : 32b.c
Author : Sejal Tapadiya
Description :Write a program to implement semaphore to protect any critical section.
	     b. protect shared memory from concurrent write access
Date: 11 oct 2023
======================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_KEY 8888

// Define semaphore operations
struct sembuf acquire_lock = { 0, -1, SEM_UNDO };
struct sembuf release_lock = { 0, 1, SEM_UNDO };

int main() {
    int shmid;
    int *shared_memory;
    int *counter;
    int semid;

    // Create a shared memory segment
    shmid = shmget(SHM_KEY, sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("SHMGET ERROR");
        exit(1);
    }

    // Attach the shared memory segment
    shared_memory = (int *)shmat(shmid, NULL, 0);
    if (shared_memory == (int *)(-1)) {
        perror("SHMAT ERROR");
        exit(1);
    }

    // Create or retrieve a semaphore set
    semid = semget(SHM_KEY, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("SEMGET ERROR");
        exit(1);
    }

    // Initialize semaphore value to 1 (unlocked)
    semctl(semid, 0, SETVAL, 1);

    // Acquire the lock
    semop(semid, &acquire_lock, 1);

    // Access shared memory
    counter = shared_memory;
    (*counter)++;

    // Release the lock
    semop(semid, &release_lock, 1);

    printf("Shared Memory Value: %d\n", *counter);

    // Detach and remove shared memory segment
    shmdt(shared_memory);

    // Remove the semaphore set
    semctl(semid, 0, IPC_RMID);

    return 0;
}

