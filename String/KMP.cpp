#include <stdio.h>
#include <stdlib.h>

#define MaxSize 255

typedef struct {
    char ch[MaxSize];
    int length;
} SString;

void get_next(SString T, int next[]) {
    int i = 0, j = 0;
    next[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            //若pi=pj，则next[j+1]=next[j]+1
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

void get_nextval(SString T, int nextval[]) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            ++i;
            ++j;
            if (T.ch[i] != T.ch[j]) {
                nextval[i] = j;
            }
            else {
                nextval[i] = nextval[j];
            }
        }
        else {
            j = nextval[j];
        }
    }
}

//KMP算法
int Index_KMP(SString S, SString T) {
    int i = 1, j = 1;
    int next[T.length + 1];
    get_next(T, next);
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        }
        else {
            j = next[j];
        }
    }
    //匹配成功
    if (j > T.length)
        return i - T.length;
    else 
        return 0;
}