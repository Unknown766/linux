#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
	printf("before execulting ls -l\n");
	execl("/bin/ls","ls","-l",(char*)0);
	printf("after execulting ls -l\n");
}
