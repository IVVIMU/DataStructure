/* 
    线性表按顺序存储，且每个元素都是不相同的整数型类型
    设计一个算法把所有奇数移动到所有偶数前边的算法，要求时间最少，辅助空间最小
    算法思想：使用快速排序，因为快速排序是内部排序算法中最优秀的排序算法,先从前向后找到一个偶数元素，再从后向前找都一个奇数元素
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

void move(int a[], int num) {
    int low = 0, high = num - 1;
    //对表按奇偶进行一次划分
    while (low < high) {
        //从前向后找到一个偶数元素
        while (low < high && a[low] % 2 != 0) low++;
        //从后向前找到一个奇数元素
        while (low < high && a[high] % 2 != 1) high--;
        if (low < high) {
            int temp = a[low];
            a[low] = a[high];
            a[high] = temp;
        }
        low++;
        high--;
    }
}

int main() {
    int a[MaxSize] = { 0 };
    int num;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    move(a, num);
    printf("输出奇数在前偶数在后的排序结果：");
    Print(a, num);
    return 0;
}

/* 
输入要创建的数组长度：8
输入数据元素：49 38 65 97 76 13 27 49
输出奇数在前偶数在后的排序结果：49 49 65 97 27 13 76 38 
*/