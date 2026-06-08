#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <디렉토리명>\n", argv[0]);
        return 1;
    }

    // 디렉토리 삭제 실행
    if (rmdir(argv[1]) != 0) {
        perror("rmdir 오류");
        return 1;
    }

    return 0;
}
