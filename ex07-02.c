#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int  i = 0;
int main() {
	pid_t pid;

	i++;
	printf("before calling fork(%d)\n", i);
	
	pid = fork();

	if (pid == 0) {
		printf("child process(%d)\n",++i);
	} else if (pid > 0) {
		printf("parents process(%d)\n",--i);
	} else {
		printf("fail to fork\n");
	}
}
