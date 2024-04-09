#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main() {
	int target;
	int total = 0;
	pid_t pid;
	scanf("%d",&target);
	pid = fork();
	if (pid == 0) {
		total = 1;
		for (int i = 1; i < target; i++) {
			total*=i;
		}
		printf("child : %d\n",total);
	} else if (pid > 0) {
		for (int i = 1; i < target; i++) {
			total+=i;
		}
		printf("parents : %d\n",total);
	} else {
		printf("Error\n");
	}	
}
