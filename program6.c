#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	char buf[100];
	int char_read = read(STDIN_FILENO,buf,100);
	write(STDOUT_FILENO,buf, char_read);
	return 0;
}

