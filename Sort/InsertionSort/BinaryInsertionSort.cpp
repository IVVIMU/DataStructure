/* 
    折半插入排序
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

//折半插入排序
void BinInsertSort(int a[], int num) {
    int temp, i, j, low, high, mid;
    //将各元素插入到已排好序的序列
    for (i = 1; i < num; i++) {
        //初始数据正序时移动次数为零
        if (a[i - 1] > a[i]) {
            //依次将a[2]~a[n]插入前面已排序序列
            temp = a[i];
            //设置折半查找范围
            low = 0;
            high = i - 1;
            //折半查找（默认递增有序）
            while (low <= high) {
                mid = (low + high) / 2;
                if (a[mid] > temp)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            //low > high时
            for (j = i - 1; j >= high + 1; j--) {
                //统一后移元素，空出插入位置
                a[j + 1] = a[j];
            }
            a[high + 1] = temp;
        }
    }
}

int main() {
    int a[MaxSize] = { 0 };
    int num;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    BinInsertSort(a, num);
    printf("输出从小到大的排序结果：");
    Print(a, num);
    return 0;
}

/* 
输入要创建的数组长度：8
输入数据元素：94 32 40 90 80 46 21 69
输出从小到大的排序结果：21 32 40 46 69 80 90 94 
*/