#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    struct stat file_stat;

    // 파일의 상태 정보 가져오기
    if (stat(argv[1], &file_stat) < 0) {
        perror("stat 오류");
        return 1;
    }

    printf("  파일: %s\n", argv[1]);
    printf("  크기: %ld 바이트\n", file_stat.st_size);
    printf("  I-node 번호: %ld\n", (long)file_stat.st_ino);
    printf("  파일 권한(Mode): %o\n", file_stat.st_mode & 0777);
    printf("  하드 링크 수: %ld\n", (long)file_stat.st_nlink);
    printf("  소유자 UID: %d, 그룹 GID: %d\n", file_stat.st_uid, file_stat.st_gid);
    printf("  최종 수정 시간: %s", ctime(&file_stat.st_mtime));

    return 0;
}
