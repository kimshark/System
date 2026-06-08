#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "사용법: %s <원본> <이동경로/새이름>\n", argv[0]);
        return 1;
    }

    // 이름 변경 및 이동 실행
    if (rename(argv[1], argv[2]) != 0) {
        perror("mv 오류");
        return 1;
    }

    return 0;
}
