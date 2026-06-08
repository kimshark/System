#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <utime.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    // 파일이 있는지 확인해보고, 없으면 쓰기 전용으로 새로 생성(0644 권한)
    int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    if (fd < 0) {
        perror("touch 오류 (파일 생성 실패)");
        return 1;
    }
    close(fd);

    // 파일의 접근/수정 시간을 현재 시간으로 업데이트
    if (utime(argv[1], NULL) < 0) {
        perror("touch 오류 (시간 업데이트 실패)");
        return 1;
    }

    return 0;
}
