/*
    朴素模式匹配算法
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MaxSize 255

typedef struct {
    char ch[MaxSize];
    int length;
} SString;

int Index(SString S, SString T) {
    int k = 1;
    int i = k, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[i]) {
            ++i;
            ++j;
        }
        else {
            k++;
            i = k;
            j = 1;
        }
    }
    if (j > T.length)
        return k;
    else 
        return 0;
}