#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("free 오류 (/proc/meminfo 열기 실패)");
        return 1;
    }

    char line[256];
    long mem_total = 0, mem_free = 0;

    // 파일을 한 줄씩 읽으며 필요한 필드 매칭
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            sscanf(line, "MemTotal: %ld", &mem_total);
        } else if (strncmp(line, "MemFree:", 8) == 0) {
            sscanf(line, "MemFree: %ld", &mem_free);
        }
    }
    fclose(file);

    long mem_used = mem_total - mem_free;

    printf("             total        used        free\n");
    printf("Mem:    %10ld  %10ld  %10ld KB\n", mem_total, mem_used, mem_free);

    return 0;
}
