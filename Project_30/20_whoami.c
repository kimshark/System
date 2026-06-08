#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main() {
    uid_t uid = getuid();          // 현재 사용자의 UID 가져오기
    struct passwd *pw = getpwuid(uid); // UID 기반으로 사용자 정보 구조체 가져오기

    if (pw != NULL) {
        printf("%s\n", pw->pw_name); // 유저 네임 출력
    } else {
        perror("whoami 오류");
        return 1;
    }
    return 0;
}
