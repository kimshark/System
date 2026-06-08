#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("head 오류");
        return 1;
    }

    char line[1024];
    int count = 0;

    // 최대 10줄까지만 읽어서 출력
    while (count < 10 && fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        count++;
    }

    fclose(file);
    return 0;
}
