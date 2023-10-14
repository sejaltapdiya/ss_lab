/*
============================================================================
Name : 31b.c.c
Author : Sejal Tapadiya
Description : Write a program to create a semaphore and initialize value to the semaphore. b) create a counting semaphore
Date: 10 Oct 2023
============================================================================
*/
#include <unistd.h>
#include <string.h>
#include <sys/sem.h>
#include <stdio.h>

// Define a union to hold semaphore values or operations
union semaphore {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
};

int main() {
    union semaphore arg;
    int key, semid;

    key = ftok(".", 'C'); 
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0744); // 1 is the number of semaphores
    if (semid != -1) {
        // Initialize the counting semaphore with an initial value (e.g., 5)
        arg.val = 4; 
        if (semctl(semid, 0, SETVAL, arg) == -1) {
            perror("semctl");
            return 1;
        }

        printf("Counting semaphore created successfully\n");
    } else {
        perror("semget");
        return 1;
    }

    return 0;
}

