#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
	pid_t pid;
	int x,y,status,parent,child=0;
	do {
		scanf("%d %d",&x,&y);
	} while(!((x>=1 && x<=10) && (y>=1 || y<=10) && x<y));
	pid = fork();
	
	if (pid>0) {
		parent = x;
		for (int i=0; i<y-1; i++) {
			parent*=x;
		}
		wait(&status);
		printf("parent : %d\nchild : %d\n",parent,child);
		printf("Total : %d\n",parent + child);
	} else if (pid == 0) {
		child=1;
		exit(1);
	} else {
		printf("Failed\n");
	}
}


