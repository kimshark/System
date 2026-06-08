#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    // 파일 삭제 실행
    if (unlink(argv[1]) != 0) {
        perror("rm 오류");
        return 1;
    }

    return 0;
}
