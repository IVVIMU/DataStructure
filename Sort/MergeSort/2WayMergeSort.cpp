/* 
    二路归并排序
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define ElemType int

void Input(int a[], int num) {
    int data;
    printf("输入数据元素：");
    for (int i = 0; i < num; i++) {
        scanf("%d", &data);
        a[i] = data;
    }
}

void Print(int a[], int num) {
    for (int i = 0; i < num; i++) {
        printf("%d ", a[i]);
    }
}

//交换函数
void swap(ElemType &a, ElemType &b) {
    ElemType temp = a;
    a = b;
    b = temp;
}

//辅助数组b
int *b = (ElemType *) malloc(sizeof(ElemType) * MaxSize);
//表a的两段a[low...mid]和a[mid + 1...high]各自有序，将它们合并成一个有序表
void Merge(ElemType a[], int low, int mid, int high) {
    int i, j, k;
    //将a中所有元素复制到b中
    for (k = low; k <= high; k++)
        b[k] = a[k];
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
        //将较小值复制到a中
        if (b[i] <= b[j])
            a[k] = b[i++];
        else
            a[k] = b[j++];
    }
    while (i <= mid)
        a[k++] = b[i++];
    while (j <= high)
        a[k++] = b[j++];
}

void MergeSort(ElemType a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        //对左区间归并排序
        MergeSort(a, low, mid);
        //对右区间归并排序
        MergeSort(a, mid + 1, high);
        //归并
        Merge(a, low, mid, high);
    }
}

int main() {
    int a[MaxSize] = { 0 };
    int num;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    MergeSort(a, 0, num - 1);
    printf("输出归并排序结果：");
    Print(a, num);
    return 0;
}

/* 
输入要创建的数组长度：7
输入数据元素：49 38 65 97 76 13 27
输出归并排序结果：13 27 38 49 65 76 97 
*/