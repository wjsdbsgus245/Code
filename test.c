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
        printf("���� ���� ����! \n");
        exit(1);
    }

    printf(">> ����� ������ �Է��ϼ���.(%d��)", SIZE);
    for(int i = 0; i < SIZE; i++)
    {
        printf("\n%d. �̸� : ", (i + 1)); gets(user.name);
        printf("   ���� : "); gets(user.gender);
        printf("   ���� : "); scanf("%d", &user.age);

        fwrite(&user, sizeof(PERSON), 1, fp);
        fflush(stdin);
    }

    fclose(fp);
    printf("\n==���� ��� �Ϸ�==\n");

    return 0;
}