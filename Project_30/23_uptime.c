#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;

    // 시스템 정보 구조체 가져오기
    if (sysinfo(&info) != 0) {
        perror("uptime 오류");
        return 1;
    }

    long uptime_secs = info.uptime;
    long days = uptime_secs / (24 * 3600);
    uptime_secs %= (24 * 3600);
    long hours = uptime_secs / 3600;
    uptime_secs %= 3600;
    long mins = uptime_secs / 60;

    printf("시스템 가동 시간: ");
    if (days > 0) {
        printf("%ld일 ", days);
    }
    printf("%ld시간 %ld분\n", hours, mins);

    return 0;
}
