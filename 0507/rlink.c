#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char buffer[1024];
    ssize_t nread;

    if (argc < 2) {
        exit(1);
    }

    nread = readlink(argv[1], buffer, sizeof(buffer));

    if (nread != -1) {
        write(1, buffer, nread);
        exit(0);
    } else {
        fprintf(stderr, "오류 : 해당 링크 없음\n");
        exit(1);
    }
}
