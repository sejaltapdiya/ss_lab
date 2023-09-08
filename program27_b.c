/*
================================================================================================
Name : Program27_b.c
Author : Sejal Tapadiya
Description : Write a program to execute ls -Rl by the following system calls
	      b. execlp
Date: 5th Sept, 2023.
================================================================================================
*/
#include <unistd.h>
#include <stdio.h>  
#include <stdlib.h> 

int main(void) {
  execlp("/bin/ls", "ls", "-Rl", NULL);
  perror("Return from execlp() not expected");
  exit(EXIT_FAILURE);
}
