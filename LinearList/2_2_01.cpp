/*
    从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
    空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef struct SqList{
    int data[MaxSize] = {2,3,1,4,5};
    int Length = 5;
}SqList;

bool Del_Min(SqList &L, int &value) {
    if (L.Length == 0) 
        return false;
    value = L.data[0];
    int pos = 0;
    for (int i = 0; i < L.Length; i++) {
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.Length - 1];
    L.Length--;
    return true;
}

int main() {
    SqList L;
    printf("原先的线性表为：");
    for (int i = 0; i < L.Length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
    int value = 0;
    if (Del_Min(L, value)) {
        printf("最小元素为：%d\n", value);
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
