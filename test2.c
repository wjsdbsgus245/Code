#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

struct person
{
    char name[7], gender[3];
    int age;
};
typedef struct person PERSON;

int main(){
    PERSON user;

    FILE *fp = fopen("user.bin", "rb");
    if(fp == NULL)
    {
        printf("파일 열기 에러! \n");
        exit(1);
    }
    puts("------------------");
    puts(" 이름   성별  나이");
    puts("------------------");

    while(fread(&user, sizeof(PERSON), 1, fp) == 1)
        printf("%-8s %-3s %4d\n", user.name, user.gender, user.age);

    puts("------------------");
    fclose(fp);

    return 0;
}