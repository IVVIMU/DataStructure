/*
    删除线性表中所有值为x的数据元素
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef struct SqList {
    int data[MaxSize] = {1,2,3,4,1,2,3,2};
    int Length = 8;
} SqList;

void RemoveValue(SqList &L, int value) {
    //记录不等于value的数据元素个数
    int count = 0;
    for (int i = 0; i < L.Length; i++) {
        if (value != L.data[i]) {
            L.data[count] = L.data[i];
            count++;
        }
    }
    L.Length = count;
}

void RemoveValue_2(SqList &L, int value) {
    //记录等于value的数据元素个数
    int count = 0;
    for (int i = 0; i < L.Length; i++) {
        if (value == L.data[i]) {
            count++;
        }
        else {
            //将不等于value的数据元素前移count个单位
            L.data[i-count] = L.data[i];
        }
    }
    L.Length = L.Length - count;
}

int main() {
    SqList L;
    printf("原先的线性表为：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    RemoveValue(L, 1);
    printf("现在的线性表为：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    return 0;
}