#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char *argv[]) {

	char *arg[] = {"wc","-l","-w","-c",argv[1],(char*)0};

	execv("/bin/wc",arg);	
}
