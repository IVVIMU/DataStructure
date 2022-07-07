/*
    查找有序顺序表中数值为x的数据元素
    若找到，与后继元素的位置交换
    若找不到，则将其插入表中并使表中元素仍递增有序
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef struct SqList {
    int data[MaxSize] = {1,2,3,4,5,6,8};
    int Length = 7;
} SqList;

void SearchExchangeInsert(SqList &L, int x) {
    int low = 0, high = L.Length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.data[mid] == x)
            break;
        else 
            if (L.data[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
    }
    if (L.data[mid] == x && mid != L.Length - 1) {
        int temp = L.data[mid];
        L.data[mid] = L.data[mid + 1];
        L.data[mid + 1] = temp;
    }
    //查找失败
    if (low > high) {
        int i;
        for (i = L.Length - 1; i > high; i--) {
            //后移元素
            L.data[i + 1] = L.data[i];
        }
        L.data[i + 1] = x;
        L.Length++;
    }
}

int main() {
    SqList L;
    printf("原先的线性表为：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    SearchExchangeInsert(L, 4);
    printf("现在的线性表为：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    SearchExchangeInsert(L, 7);
    printf("现在的线性表为：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    return 0;
}