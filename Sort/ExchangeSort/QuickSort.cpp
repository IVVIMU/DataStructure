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
        //比枢轴大的元素移到右端
        a[high] = a[low];
    }
    //枢轴元素存放到最终位置
    a[low] = pivot;
    //返回存放枢轴元素的最终位置
    return low;
}

//划分函数（随机选取元素为枢轴值）
int PartitionRandom(int a[], int low, int high) {
    //随机选取当前表中地一个元素设为枢轴
    int randIndex = low + rand() % (high - low + 1);
    //将枢轴值交换到第一个元素
    int temp = a[low];
    a[low] = a[randIndex];
    a[randIndex] = temp;
    //置当前表中第一个元素为枢轴值
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

int main() {
    int a[MaxSize] = { 0 };
    int num;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    QuickSortRecursion(a, 0, num - 1);
    printf("输出从小到大的排序结果：");
    Print(a, num);
    return 0;
}

/* 
输入要创建的数组长度：8
输入数据元素：49 38 65 97 76 13 27 49
输出从小到大的排序结果：13 27 38 49 49 65 76 97 
*/