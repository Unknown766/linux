#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid1, pid2;
    int value1, value2, sum, product;

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    
    printf("Fir num : ");
    scanf("%d", &value1);
    printf("Sec num : ");
    scanf("%d", &value2);

    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        close(pipe1[0]);
        sum = value1 + value2;
        write(pipe1[1], &sum, sizeof(int));
        close(pipe1[1]); 
        exit(EXIT_SUCCESS);
    } else {
        pid2 = fork();
        if (pid2 == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid2 == 0) {
            close(pipe2[0]);
            product = value1 * value2;
            write(pipe2[1], &product, sizeof(int));
            close(pipe2[1]);
            exit(EXIT_SUCCESS);
        } else {
            close(pipe1[1]);
            close(pipe2[1]);

            read(pipe1[0], &sum, sizeof(int));
            close(pipe1[0]);

            read(pipe2[0], &product, sizeof(int));
            close(pipe2[0]);

            wait(NULL);
            wait(NULL);

            int final_result = sum + product;
            printf("Total : %d\n", final_result);
        }
    }

    return 0;
}
