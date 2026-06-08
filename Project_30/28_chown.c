#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "사용법: %s <소유자UID> <그룹GID> <파일명>\n", argv[0]);
        fprintf(stderr, "예시: sudo %s 1000 1000 test.txt\n", argv[0]);
        return 1;
    }

    uid_t uid = atoi(argv[1]);
    gid_t gid = atoi(argv[2]);
    char *filename = argv[3];

    // 소유권 및 그룹 변경 실행
    if (chown(filename, uid, gid) == 0) {
        printf("'%s' 파일의 소유주가 UID:%d, GID:%d 로 변경되었습니다.\n", filename, uid, gid);
    } else {
        perror("chown 오류");
        return 1;
    }

    return 0;
}
