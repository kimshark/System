#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "사용법: %s <찾을문자열> <파일명>\n", argv[0]);
        return 1;
    }

    char *pattern = argv[1];
    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        perror("grep 오류 (파일 열기 실패)");
        return 1;
    }

    char line[1024];
    int line_num = 1;

    // 파일을 한 줄씩 읽으며 패턴 검사
    while (fgets(line, sizeof(line), file) != NULL) {
        // strstr 함수로 한 줄 안에 패턴이 존재하시는지 확인
        if (strstr(line, pattern) != NULL) {
            printf("%d: %s", line_num, line);
        }
        line_num++;
    }

    fclose(file);
    return 0;
}
