#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

main() {
	printf("[ex08-06.c] PPID : %d, PID : %d\n",getpid(), getppid());
}
