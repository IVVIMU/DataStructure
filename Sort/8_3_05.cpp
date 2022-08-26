/* 
    在数组中找出第k小的元素（即从小到大排序后处于第k个位置的元素）
    算法思想：最直接的做法是先从小到大排序再提取第k个元素；还可以采用快速排序的划分操作
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

int Partition(int a[], int low, int high) {
    //将当前表中第一个元素设为枢轴，对表进行划分
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] > pivot) 
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
    //如果low == k，即a[low]为第k小的元素
    return low;
}

int QuickSortKth(int a[], int low, int high, int k) {
    if (low < high) {
        int pivotpos = Partition(a, low, high);
        if (pivotpos == k) return a[pivotpos];
        //在右区间递归寻找
        if (pivotpos < k) return QuickSortKth(a, pivotpos + 1, high, k);
        //在左区间递归寻找
        if (pivotpos > k) return QuickSortKth(a, low, pivotpos - 1, k);
    }
    //区间内只有一个元素
    else if (low == high && low == k) {
        return a[low];
    }
}

int main() {
    int a[MaxSize] = { 0 };
    int num, k;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    printf("输入要查找第k小的元素的k的值：");
    scanf("%d", &k);
    printf("输出数组中找出第k小的元素：%d", QuickSortKth(a, 0, num - 1, k - 1)); //数组下标从0开始，查找第k小的元素需要输入k - 1
    return 0;
}

/* 
输入要创建的数组长度：8
输入数据元素：49 38 65 97 76 13 27 49
输入要查找第k小的元素的k的值：6
输出数组中找出第k小的元素：65
*/