#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *target_dir;

    if (argc < 2) {
        // 인자가 없으면 HOME 디렉토리로 설정
        target_dir = getenv("HOME");
        if (target_dir == NULL) {
            fprintf(stderr, "cd: HOME 디렉토리를 찾을 수 없습니다.\n");
            return 1;
        }
    } else {
        target_dir = argv[1];
    }

    // 디렉토리 이동 실행
    if (chdir(target_dir) != 0) {
        perror("cd 오류");
        return 1;
    }

    return 0;
}
