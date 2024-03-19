#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, int *argv[]) {
	int filedes;
	off_t newpos;
	
	if ((filedes = open(argv[1], O_RDONLY))==-1) {
		printf("Error\n");
		exit(1);
	}
	newpos = lseek(filedes, (off_t)0, SEEK_END);
	printf("file size : %d\n" newpos);
}

