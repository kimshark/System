#include <stdio.h>

int main(int argc, char *argv[]) {
    // argv[1]부터 마지막 인자까지 순서대로 출력
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        if (i < argc - 1) {
            printf(" "); // 인자 사이에 공백 추가
        }
    }
    printf("\n"); // 마지막 줄 바꿈
    return 0;
}
