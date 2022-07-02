#include <stdio.h>
#include <stdlib.h>

//顺序表的动态分配

//默认的最大长度
#define InitSize 10
typedef struct {
    int *data;
    int MaxSize;
    int length;
}SeqList;

void InitList(SeqList &L) {
    //malloc申请一片连续的存储空间
    L.data = (int *)malloc(InitSize*sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

//增加动态数组的长度
void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len)*sizeof(int));
    for (int i=0; i<L.length; i++) {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

//插入数据
bool ListInsert(SeqList &L, int i, int elem) {
    //判断i的范围是否有效
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    if (L.length >= L.MaxSize) {
        return false;
    }
    //将第i个元素及之后的元素后移
    for (int j = L.length; j>=i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = elem;
    L.length++;
    return true;
}

//删除数据
bool ListDelete(SeqList &L, int i, int &elem) {
    if (i < 1 || i > L.length) {
        return false;
    }
    //将被删除的元素赋值给elem
    elem = L.data[i-1];
    //将第i个位置后的元素前移
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

//按位查找
int GetElem(SeqList L, int i) {
    return L.data[i-1];
}

//按值查找
int LocateElem(SeqList L, int elem) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == elem) {
            return i+1;
        }
        return 0;
    }
    
}

int main() {
    SeqList L;
    InitList(L);
    IncreaseSize(L,5);
    ListInsert(L,3,3);

    int elem = -1;
    if (ListDelete(L,3,elem)) {
        printf("已删除第3个元素，删除的元素值为 %d\n",elem);
    } else {
        printf("位序i不合法，删除失败\n");
    }
    return 0;
}