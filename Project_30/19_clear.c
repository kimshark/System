#include <stdio.h>

int main() {
    // \033[H : 커서를 화면 좌측 상단 맨 처음으로 이동
    // \033[2J: 화면 전체의 내용을 지움
    printf("\033[H\033[2J");
    fflush(stdout); 
    return 0;
}
