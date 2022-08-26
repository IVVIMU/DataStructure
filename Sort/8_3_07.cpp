/* 
    将由n个正整数构成的集合A划分为两个不相交的子集A1和A2，元素个数分别是n1和n2，A1和A2中的元素之和分别为S1和S2，
    满足|n1 - n2|最小且|S1 - S2|最大
    算法思想：排好序后直接按照中位数划分子表，故采取快速排序
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
        //比枢轴大的元素移到右端
        a[high] = a[low];
    }
    //枢轴元素存放到最终位置
    a[low] = pivot;
    //返回存放枢轴元素的最终位置
    return low;
}

void QuickSort(int a[], int low, int high, int mid) {
    if (low < high) {
        int pivotpos = Partition(a, low, high);
        if (pivotpos == mid) return;
        if (pivotpos < mid) QuickSort(a, pivotpos + 1, high, mid);
        if (pivotpos > mid) QuickSort(a, low, pivotpos - 1, mid);
    }
}

int main() {
    int a[MaxSize] = { 0 };
    int num;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    QuickSort(a, 0, num - 1, num / 2);
    printf("输出从小到大的排序结果：");
    Print(a, num);
    return 0;
}

/* 
输入要创建的数组长度：8
输入数据元素：1 5 6 3 4 7 11 10
输出从小到大的排序结果：1 4 3 5 6 7 11 10 
*/