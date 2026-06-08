#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    char hostname[HOST_NAME_MAX]; // 시스템이 정의한 호스트 이름 최대 길이

    // 호스트 이름 읽어오기
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("%s\n", hostname);
    } else {
        perror("hostname 오류");
        return 1;
    }
    return 0;
}
