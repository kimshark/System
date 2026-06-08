#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LINES 10
#define LINE_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("tail 오류");
        return 1;
    }

    // 10줄을 저장할 버퍼 동적 할당
    char lines[NUM_LINES][LINE_SIZE];
    int total_lines = 0;

    // 파일을 끝까지 읽으며 버퍼를 번갈아가며 채움 (Circular 방식)
    while (fgets(lines[total_lines % NUM_LINES], LINE_SIZE, file) != NULL) {
        total_lines++;
    }

    // 파일이 총 10줄보다 적게 가졌을 때와 많을 때를 구분하여 출력
    int start = (total_lines > NUM_LINES) ? (total_lines % NUM_LINES) : 0;
    int count = (total_lines > NUM_LINES) ? NUM_LINES : total_lines;

    for (int i = 0; i < count; i++) {
        printf("%s", lines[(start + i) % NUM_LINES]);
    }

    fclose(file);
    return 0;
}
