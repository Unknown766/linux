#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    int value1, value2;

    // 파이프 생성
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    printf("Fir num : ");
    scanf("%d", &value1);
    printf("Sec num : ");
    scanf("%d", &value2);

    // 프로세스 생성
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        close(pipefd[0]);

        // 자식 프로세스에 데이터 보내기
        write(pipefd[1], &value1, sizeof(int));
        write(pipefd[1], &value2, sizeof(int));
        close(pipefd[1]); // 쓰기 파이프 닫기

        // 자식 프로세스가 끝나길 기다리기
        wait(NULL);
    } else {
        // 자식 프로세스 코드
        close(pipefd[1]);

        read(pipefd[0], &value1, sizeof(int));
        read(pipefd[0], &value2, sizeof(int));
        close(pipefd[0]); // 읽기 파이프 닫기

        int result = value1 + value2;
        printf("Total : %d\n", result);
        exit(EXIT_SUCCESS);
    }

    return 0;
}
