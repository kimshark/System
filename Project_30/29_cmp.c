#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "사용법: %s <파일1> <파일2>\n", argv[0]);
        return 1;
    }

    FILE *f1 = fopen(argv[1], "rb");
    if (!f1) { perror("파일1 열기 실패"); return 1; }

    FILE *f2 = fopen(argv[2], "rb");
    if (!f2) { perror("파일2 열기 실패"); fclose(f1); return 1; }

    int ch1, ch2;
    long byte_cnt = 1;
    long line_cnt = 1;
    int match = 1;

    while (1) {
        ch1 = fgetc(f1);
        ch2 = fgetc(f2);

        // 둘 중 하나라도 파일 끝(EOF)을 만나면 루프 탈출
        if (ch1 == EOF || ch2 == EOF) break;

        if (ch1 != ch2) {
            printf("%s %s 차이점 발견: %ld 바이트, %ld 라인\n", argv[1], argv[2], byte_cnt, line_cnt);
            match = 0;
            break;
        }

        if (ch1 == '\n') line_cnt++;
        byte_cnt++;
    }

    // 파일 크기가 달라서 한쪽만 먼저 끝난 경우 처리
    if (match && (ch1 != ch2)) {
        printf("cmp: EOF 발견 (%s 파일이 더 짧음)\n", (ch1 == EOF) ? argv[1] : argv[2]);
    } else if (match) {
        printf("두 파일이 완전히 일치합니다.\n");
    }

    fclose(f1);
    fclose(f2);
    return 0;
}
