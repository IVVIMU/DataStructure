/*
    数组中未出现的最小正整数
    {-5，3，2，3} --> 1
    {1,2,3} --> 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MaxSize 50
typedef struct SqList {
    int data[MaxSize];
    int Length;
} SqList;

int findMinPositive(SqList L) {
    int i;
    int max = L.data[0];
    for (i = 0; i < L.Length; i++) {
        if (L.data[i] > max) {
            max = L.data[i];
        }
    }
    int *B;
    B = (int *) malloc(sizeof(int)*max);
    //赋初值为0
    memset(B, 0, sizeof(int)*max);
    for (i = 0; i < max; i++) {
        if (L.data[i] > 0 && L.data[i] < max) {
            B[L.data[i] - 1] = 1;
        }
    }
    for (i = 0; i < max; i++) {
        if (B[i] == 0)
            break;
    }
    return i + 1;
}

int main() {
    SqList L = {{2,3,4,6,7},5};
    int MinPos = findMinPositive(L);
    printf("%d", MinPos);
    return 0;
}