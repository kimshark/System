#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // 하드링크: ln 원본 링크명 (인자 3개)
    // 심볼릭링크: ln -s 원본 링크명 (인자 4개)
    if (argc < 3) {
        fprintf(stderr, "사용법:\n  하드 링크: %s <원본> <링크명>\n  심볼릭 링크: %s -s <원본> <링크명>\n", argv[0], argv[0]);
        return 1;
    }

    if (argc == 4 && strcmp(argv[1], "-s") == 0) {
        // 심볼릭 링크 생성
        if (symlink(argv[2], argv[3]) != 0) {
            perror("ln (심볼릭) 오류");
            return 1;
        }
    } else {
        // 하드 링크 생성
        if (link(argv[1], argv[2]) != 0) {
            perror("ln (하드) 오류");
            return 1;
        }
    }

    return 0;
}
