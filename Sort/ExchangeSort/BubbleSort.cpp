/* 
    冒泡排序
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

//冒泡排序
void BubbleSort(int a[], int num) {
    int temp, i, j;
    bool flag;
    for (i = 0; i < num - 1; i++) {
        //表示本趟冒泡是否发生交换的标志
        flag = false;
        //从后往前冒泡
        for (j = num - 1; j > i; j--) {
            //若为逆序
            if (a[j - 1] > a[j]) {
                temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
                flag = true;
            }
        }
        //经过一趟遍历后没有发生交换，说明表已经有序
        if (flag == false)
            return;
    }
}

int main() {
    int a[MaxSize] = { 0 };
    int num;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    BubbleSort(a, num);
    printf("输出从小到大的排序结果：");
    Print(a, num);
    return 0;
}

/* 
输入要创建的数组长度：8
输入数据元素：49 38 65 97 76 13 27 49
输出从小到大的排序结果：13 27 38 49 49 65 76 97 
*/