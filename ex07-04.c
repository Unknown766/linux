#include<stdio.h>

int main() {
	char *arg[] = {"ls","-l",(char*)0};
	printf("before execulting ls -\n");
	execv("/bin/ls", arg);
	printf("after execulting ls -l\n");
}
