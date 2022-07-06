/*
    线性表前后互换
    A[m+n] --> A[n+m]
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef struct SqList {
    int data[MaxSize] = {1,2,3,4,5,6,7};
    int Length = 7;
} SqList;

bool Reverse(SqList &L, int left, int right, int arraySize) {
    if (left > right || right > arraySize)
        return false;
    int mid = (left + right) / 2;
    for (int i = 0; i <= mid - left; i++) {
        int value = L.data[left + i];
        L.data[left + i] = L.data[right - i];
        L.data[right - i] = value;
    }
}

void Exchange(SqList &L, int m, int n, int arraySize) {
    Reverse(L, 0, m+n-1, L.Length);
    Reverse(L, 0, n-1, L.Length);
    Reverse(L, n, m+n-1, L.Length);
}

int main() {
    SqList L;
    printf("原先的线性表为：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    Exchange(L, 4, 3, L.Length);
    printf("现在的线性表为：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    return 0;
}