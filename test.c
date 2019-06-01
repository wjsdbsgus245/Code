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

    FILE *fp = fopen("user2.bin", "wb");
    if(fp == NULL)
    {
        printf("파일 열기 에러! \n");
        exit(1);
    }

    printf(">> 사용자 정보를 입력하세요.(%d명)", SIZE);
    for(int i = 0; i < SIZE; i++)
    {
        printf("\n%d. 이름 : ", (i + 1)); gets(user.name);
        printf("   성별 : "); gets(user.gender);
        printf("   나이 : "); scanf("%d", &user.age);

        fwrite(&user, sizeof(PERSON), 1, fp);
        fflush(stdin);
    }

    fclose(fp);
    printf("\n==파일 출력 완료==\n");

    return 0;
}