/*
============================================================================
Name : 33_client.c
Author : Sejal Tapadiya
Description : .Write a program to communicate between two machines using socket.
Date: 8 Oct 2023
============================================================================
*/
#define SOCKET_NAME "/tmp/resol.sock"
#define BUFFER_SIZE 1024

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	struct sockaddr_un addr;
	int i;
	int ret;
	int data_socket;
	char buffer[BUFFER_SIZE];
	char buf1[BUFFER_SIZE];
	/* Create local socket. */

	data_socket = socket(AF_UNIX, SOCK_STREAM, 0);
	if(data_socket == -1) 
	{
	    perror("socket");
	    exit(EXIT_FAILURE);
	}

	/*
	* For portability clear the whole structure, since some
	* implementations have additional (nonstandard) fields in
	* the structure.
	*/

	memset(&addr, 0, sizeof(struct sockaddr_un));

	/* Connect socket to socket address */

	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) - 1);

	ret = connect (data_socket, (const struct sockaddr *) &addr, sizeof(struct sockaddr_un));
	if(ret == -1) 
	{
	    fprintf(stderr, "The server is down.\n");
	    exit(EXIT_FAILURE);
	}

	/* Send arguments. */

	char buff1[]="Hello this is client\n";
	ret = write(data_socket, buff1, strlen(buff1));
	if(ret == -1) 
	{
	    perror("write");
	    exit(EXIT_FAILURE);
	}
	ret = read(data_socket, buf1, BUFFER_SIZE);
	if(ret == -1) 
	{
	    perror("read");
	    exit(EXIT_FAILURE);
	}
	printf("%s",buf1);

	/* Close socket. */
	close(data_socket);
	exit(EXIT_SUCCESS);
}
