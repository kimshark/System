#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    char *path = ".";

    // 사용자가 디렉토리를 지정한 경우
    if (argc > 1) {
        path = argv[1];
    }

    dir = opendir(path);
    if (dir == NULL) {
        perror("ls 오류");
        return 1;
    }

    // 디렉토리 내부를 순회하며 이름 출력
    while ((entry = readdir(dir)) != NULL) {
        // 기본 ls처럼 숨김 파일( . 으로 시작하는 파일)은 제외하고 출력
        if (entry->d_name[0] != '.') {
            printf("%s  ", entry->d_name);
        }
    }
    printf("\n");

    closedir(dir);
    return 0;
}
