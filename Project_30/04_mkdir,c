#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <디렉토리명>\n", argv[0]);
        return 1;
    }

    // 0755 권한으로 디렉토리 생성 (rwxr-xr-x)
    if (mkdir(argv[1], 0755) != 0) {
        perror("mkdir 오류");
        return 1;
    }

    return 0;
}
