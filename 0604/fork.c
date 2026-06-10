1 #include <stdio.h>
2 #include <unistd.h>
3
5 int main()
6 {
7   int pid;
8   printf("[%d] 프로세스 시작 \n", getpid());
9   pid = fork();
10  printf("[%d] 프로세스 : 반환값 %d\n", getpid(), pid);
11 }
