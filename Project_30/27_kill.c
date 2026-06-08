#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <PID>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);

    // SIGKILL(9): 프로세스를 강제 종료하는 시그널 전송
    if (kill(pid, SIGKILL) == 0) {
        printf("프로세스 %d 번에 강제 종료(SIGKILL) 시그널을 성공적으로 보냈습니다.\n", pid);
    } else {
        perror("kill 오류 (시그널 전송 실패)");
        return 1;
    }

    return 0;
}
