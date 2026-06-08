#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "사용법: %s <8진수권한> <파일명>\n", argv[0]);
        fprintf(stderr, "예시: %s 755 test.txt\n", argv[0]);
        return 1;
    }

    // 문자열로 된 권한 값을 8진수 정수로 변환 (기수 8 지정)
    mode_t mode = strtol(argv[1], NULL, 8);

    // 권한 변경 실행
    if (chmod(argv[2], mode) < 0) {
        perror("chmod 오류");
        return 1;
    }

    return 0;
}
