#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
    int i;
    char *c;
};

int main(){
    struct data aData;

    aData.i = 100;
    aData.c = (char *)malloc(10);
    strcpy(aData.c, "mwyun");

    printf("aData.i = %d\n", aData.i);
    printf("aData.c = %s\n", aData.c);

    free(aData.c);

    return 0;
}