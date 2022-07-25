/*
    堆分配存储表示
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MaxSize 255

typedef struct {
    char *ch;
    int length;
} HString;

int main() {
    HString S;
    S.ch = (char *) malloc(sizeof(char) * MaxSize);
    S.length = 0;
}