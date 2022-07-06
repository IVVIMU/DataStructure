/*
    从顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素
    若s或t不合理或顺序表为空，则显示错误信息并推出运行
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef struct SqList {
    int data[MaxSize] = {1,2,3,4,5,6};
    int Length = 6;
} SqList;

bool RemoveValue(SqList &L, int s, int t) {
    if (L.Length == 0)
        return false;
    if (s >= t) 
        return false;
    int count = 0;
    for (int i = 0; i < L.Length; i++) {
        if (L.data[i] <= s || L.data[i] >= t) {
                L.data[count] = L.data[i];
                count++;
        }
    }
    L.Length = count;
    return true;
}

int main() {
    SqList L;
    printf("原先的线性表为：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    if (RemoveValue(L, 3, 5)) {
        printf("现在的线性表为：");
        for (int i = 0; i < L.Length; i++) {
            printf("%d ", L.data[i]);
        }
        printf("\n");
    }
    else {
        printf("错误");
    }
    return 0;
}