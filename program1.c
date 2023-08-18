 #include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int v = symlink("dest", "destSL");
	if(v<0){
		perror("Failed to create Soft link");
		return 1;
	}
	int f = link("dest","destHl");
	if(f<0){
		perror("Failed creating Hard link");
		return 1;
	}
	int e = mknod("destFIFO", S_IFIFO,0);
	if(e<0)
		perror("Failed\n");
	return 0;
}
