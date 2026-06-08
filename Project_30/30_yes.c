#include <stdio.h>

int main(int argc, char *argv[]) {
    char *output = "y";

    // 사용자가 출력하고 싶은 문자열을 지정한 경우 변경
    if (argc > 1) {
        output = argv[1];
    }

    // 무한 루프 돌며 문자열 출력
    while (1) {
        printf("%s\n", output);
    }

    return 0; // 도달하진 않지만 관례상 작성
}
