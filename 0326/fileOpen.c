#include<stdio.h>
int main()  {
    FILE *fp;
    fp = fopen("./readme.md","r");
    if(fp == NULL)
        printf("File open error");

    return(0);

}
