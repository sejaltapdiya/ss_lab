#include<stdio.h>
#include<unistd.h>
#include<string.h>
extern char **environ ;
int prefixmatch(const char *pre, const char *str){
	return strncmp(pre, str, strlen(pre)) == 0;
}
int main(){
	char **env = environ;
	while(*env!=NULL){
		if(prefixmatch("USER",*env))
			printf("%s\n" , *env);

	env++;
	}
	return 0;
}

