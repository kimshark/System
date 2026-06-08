#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <대기할 초>\n", argv[0]);
        return 1;
    }

    int seconds = atoi(argv[1]);
    if (seconds < 0) {
        fprintf(stderr, "sleep: 대기 시간은 0보다 커야 합니다.\n");
        return 1;
    }

    // 지정된 초만큼 대기
    sleep(seconds);

    return 0;
}
