/* 
    希尔排序
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

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

//希尔排序
void ShellSort(int a[], int num) {
    int temp, i, j, d;
    //步长
    for (d = num / 2; d >= 1; d = d / 2) {
        for (i = d; i < num; i++) {
            //需将a[i]插入到有序增量子表
            if (a[i] < a[i - d]) {
                temp = a[i];
                for (j = i - d; j >= 0 && temp < a[j]; j = j - d) {
                    //记录后移，查找插入的位置
                    a[j + d] = a[j];
                }
                a[j + d] = temp;
            }
        }
    }
} 

int main() {
    int a[MaxSize] = { 0 };
    int num;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    ShellSort(a, num);
    printf("输出从小到大的排序结果：");
    Print(a, num);
    return 0;
}

/* 
输入要创建的数组长度：8
输入数据元素：8 3 9 11 4 7 5 10
输出从小到大的排序结果：3 4 5 7 8 9 10 11 
*/