#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("wc 오류");
        return 1;
    }

    int lines = 0, words = 0, bytes = 0;
    int ch;
    int in_word = 0;

    while ((ch = fgetc(file)) != EOF) {
        bytes++;

        if (ch == '\n') {
            lines++;
        }

        // 공백 문자를 만나면 단어가 끝난 것으로 처리
        if (isspace(ch)) {
            in_word = 0;
        } else if (!in_word) {
            // 공백이 아닌 문자를 새로 만나면 단어 수 증가
            in_word = 1;
            words++;
        }
    }

    printf(" 줄 수: %d, 단어 수: %d, 바이트 수: %d %s\n", lines, words, bytes, argv[1]);
    fclose(file);
    return 0;
}
