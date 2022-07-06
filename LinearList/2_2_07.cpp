/*
    将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
    注意是有序顺序表
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef struct SqList {
    int data[MaxSize];
    int Length;
} SqList;

void MergeSqList(SqList M, SqList N, SqList &L) {
    int count = 0;
    int i = 0, j = 0;
    while (i < M.Length && j < N.Length) {
        if (M.data[i] <= N.data[j]) {
            L.data[count] = M.data[i];
            count++;
            i++;
        }
        else {
            L.data[count] = N.data[j];
            count++;
            j++;
        }
    }
    while (i < M.Length) {
        L.data[count] = M.data[i];
        count++;
        i++;
    }
    while (j < N.Length) {
        L.data[count] = N.data[j];
        count++;
        j++;
    }
    L.Length = count;
}

int main() {
    SqList M = {{2,3,4,6,7},5};
    SqList N = {{3,4,4},3};
    SqList L;
    printf("原先的线性表M：");
    for (int i = 0; i < M.Length; i++) {
        printf("%d ", M.data[i]);
    }
    printf("\n");
    printf("原先的线性表N：");
    for (int i = 0; i < N.Length; i++) {
        printf("%d ", N.data[i]);
    }
    printf("\n");
    MergeSqList(M, N, L);
    printf("合并的线性表L：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    return 0;
}