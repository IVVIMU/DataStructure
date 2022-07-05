/*
    逆置线性表
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef struct {
    int data[MaxSize] = {1,2,3,4,5,6};
    int Length = 6;
}SqList;

void ListReverse(SqList &L) {
    for (int i = 0; i < (L.Length / 2); i++) {
        int value = L.data[i];
        L.data[i] = L.data[L.Length -  i - 1];
        L.data[L.Length - i -1] = value;
    }
}

int main() {
    SqList L;
    printf("原先的线性表为：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    ListReverse(L);
    printf("现在的线性表为：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }

}