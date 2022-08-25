/* 
    直接插入排序
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

//直接插入排序
void InsertSort(int a[], int num) {
    int temp, i, j;
    //将各元素插入到已排好序的序列
    for (i = 0; i < num; i++) {
        //若a[i]关键字小于前驱
        if (a[i] < a[i - 1]) {
            temp = a[i];
            //检查前面所有已排好序的元素
            for (j = i - 1; j >= 0 && a[j] > temp; j--) {
                //所有大于temp的元素都向后挪位
                a[j + 1] = a[j];
            }
            //复制到插入位置
            a[j + 1] = temp;
        }
    }
}

int main() {
    int a[MaxSize] = { 0 };
    int num;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    InsertSort(a, num);
    printf("输出从小到大的排序结果：");
    Print(a, num);
    return 0;
}

/* 
输入要创建的数组长度：8
输入数据元素：49 38 65 97 76 13 27 49
输出从小到大的排序结果：13 27 38 49 49 65 76 97 
*/