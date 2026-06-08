#include <stdio.h>
#include <time.h>

int main() {
    time_t raw_time;
    struct tm *time_info;
    char buffer[80];

    // 현재 에포크 타임(초) 가져오기
    time(&raw_time);
    // 지역 시간 구조체로 변환
    time_info = localtime(&raw_time);

    // 사용자가 원하는 서식으로 시간 문자열 포맷팅
    // %F: YYYY-MM-DD, %T: HH:MM:SS
    strftime(buffer, sizeof(buffer), "%F %T (%A)", time_info);

    printf("%s\n", buffer);
    return 0;
}
