/*
    从有序顺序表中删除所有其值重复的元素，使表中元素的值均不同
    实现集合
    注意是有序顺序表，值相同的元素一定在连续的位置上
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef struct SqList {
    int data[MaxSize] = {2,2,3,3,3,5,6,6,7};
    int Length = 9;
} SqList;

//没解决不知道怎么改
void SqListToSet(SqList &L) {
    int data[] = {};
    data[0] = L.data[0];
    int count = 1;
    for (int i = 1; i < L.Length; i++) {
        for (int j = 0; j < i;  j++) {
            if (data[j] != L.data[i - 1]) {
                data[count] = L.data[i];
                L.data[count] = L.data[i];
                count++;
            }
        }
    }
    L.Length = count;
}

void Delete_Same(SqList &L) {
    int count = 1;
    for (int i = 1; i < L.Length; i++) {
        if (L.data[i] != L.data[i -1]) {
            L.data[count] = L.data[i];
            count++;
        }
    }
    L.Length = count;
}

int main() {
    SqList L;
    printf("原先的线性表为：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    Delete_Same(L);
    //SqListToSet(L);
    printf("现在的线性表为：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    return 0;
}