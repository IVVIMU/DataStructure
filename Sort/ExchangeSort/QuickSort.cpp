/* 
    快速排序
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

//划分函数
int Partition(int a[], int low, int high) {
    //将当前表中第一个元素设为枢轴，对表进行划分
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot) 
            high--;
        //比枢轴小的元素移到左端
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            low++;
        a[high] = a[low];
    }
    //枢轴元素存放到最终位置
    a[low] = pivot;
    //返回存放枢轴元素的最终位置
    return low;
}

//快速排序——递归实现
void QuickSortRecursion(int a[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(a, low, high);
        //依次对两个字表进行递归排序
        QuickSortRecursion(a, low, pivotpos - 1);
        QuickSortRecursion(a, pivotpos + 1, high);
    }
}