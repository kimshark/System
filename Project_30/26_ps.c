#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

// 문자열이 모두 숫자로만 이루어져 있는지 판별 (PID 폴더 검색용)
int is_pid_dir(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isdigit(name[i])) return 0;
    }
    return 1;
}

int main() {
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        perror("ps 오류 (/proc 열기 실패)");
        return 1;
    }

    struct dirent *entry;
    printf("%-8s %s\n", "PID", "COMMAND");
    printf("-------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        // 폴더 이름이 숫자인 것(즉, PID 폴더)만 골라냄
        if (entry->d_type == DT_DIR && is_pid_dir(entry->d_name)) {
            char cmd_path[512];
            // 각 PID 폴더 내의 cmdline 파일 경로 생성
            snprintf(cmd_path, sizeof(cmd_path), "/proc/%s/cmdline", entry->d_name);

            FILE *cmd_file = fopen(cmd_path, "r");
            if (cmd_file) {
                char cmd_name[256];
                // cmdline 파일에서 첫 줄(커맨드 이름) 읽기
                if (fgets(cmd_name, sizeof(cmd_name), cmd_file) != NULL) {
                    // cmdline 내부 특성상 널 문자(\0)가 공백 대신 쓰일 수 있어 첫 부분만 깔끔히 출력
                    if (strlen(cmd_name) > 0) {
                        printf("%-8s %s\n", entry->d_name, cmd_name);
                    }
                } else {
                    // 간혹 권한 문제 등으로 명령어를 못 읽어오면 커널 스레드로 처리
                    printf("%-8s [Unknown/Kernel]\n", entry->d_name);
                }
                fclose(cmd_file);
            }
        }
    }

    closedir(dir);
    return 0;
}
