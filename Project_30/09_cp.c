#include <stdio.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "사용법: %s <원본파일> <대상파일>\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");
    if (src == NULL) {
        perror("cp 오류 (원본 파일 열기 실패)");
        return 1;
    }

    FILE *dst = fopen(argv[2], "wb");
    if (dst == NULL) {
        perror("cp 오류 (대상 파일 생성 실패)");
        fclose(src);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // 원본을 버퍼 크기만큼 읽어서 대상 파일에 그대로 쓰기
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes_read, dst);
    }

    fclose(src);
    fclose(dst);
    return 0;
}
