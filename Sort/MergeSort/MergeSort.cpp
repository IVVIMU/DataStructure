/* 
    归并排序
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

//归并排序
void MergeSort(ElemType a[], ElemType b[], ElemType c[], int num1, int num2) {
    int i = 0, j = 0, k = 0;
    while (i < num1 && j < num2) {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    if (i >= num1)
        while (j < num2)
            c[k++] = b[j++];
    if (j >= num2)
        while (i < num1)
            c[k++] = a[i++];
}

int main() {
    int a[MaxSize] = { 0 };
    int b[MaxSize] = { 0 };
    int c[MaxSize] = { 0 };
    int num1, num2;
    printf("输入要创建的数组a长度：");
    scanf("%d", &num1);
    Input(a, num1);
    printf("输入要创建的数组b长度：");
    scanf("%d", &num2);
    Input(b, num2);
    MergeSort(a, b, c, num1, num2);
    printf("输出合并结果（从小到大）：");
    Print(c, num1 + num2);
    return 0;
}

/* 
输入要创建的数组a长度：7
输入数据元素：12 16 24 33 45 56 60
输入要创建的数组b长度：5
输入数据元素：7 10 21 24 37
输出合并结果（从小到大）：7 10 12 16 21 24 24 33 
37 45 56 60
*/