/* 
    荷兰国旗问题，设计一个时间复杂度为O(n)的算法，排成荷兰国旗图案（红、白、蓝）
    算法思想：将红色条块交换到线性表的最前面，蓝色条块交换到线性表的最后面
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

//交换函数
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void DutchFlag(int a[], int num) {
    int cur = 0, left = 0, right = num - 1;
    while (cur <= right) {
        if (a[cur] < 1) {
            swap(a[cur], a[left]);
            left++;
            cur++;
        }
        else if (a[cur] == 1) {
            cur++;
        }
        else {
            swap(a[cur], a[right]);
            right--;
        }
    }
} 

int main() {
    int a[MaxSize] = { 0 };
    int num, k;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    DutchFlag(a, num);
    printf("输出排序结果：");
    Print(a, num);
    return 0;
}

/* 
输入要创建的数组长度：7
输入数据元素：0 2 1 2 1 2 1
输出排序结果：0 1 1 1 2 2 2
*/
