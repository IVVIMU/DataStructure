/* 
    双向冒泡排序，在正反两个反方向交替进行扫描
    第一趟把关键字最大的元素放在序列的最后面，第二趟把关键字最小的元素放在最前面，如此反复进行
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

//双向冒泡排序
void DoubleBubble(int a[], int num) {
    int low = 0, high = num - 1;
    bool flag = true;
    while (low < high && flag) {
        flag = false;
        //从前向后冒泡
        for (int i = low; i < high; i++) {
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                flag = true;
            }
        }
        //更新上界
        high--;
        for (int i = high; i > low; i--) {
            if (a[i] < a[i - 1]) {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                flag = true;
            }
        }
        //更新下界
        low++;
    }
}

int main() {
    int a[MaxSize] = { 0 };
    int num;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    DoubleBubble(a, num);
    printf("输出从小到大的排序结果：");
    Print(a, num);
    return 0;
}

/* 
输入要创建的数组长度：8
输入数据元素：49 38 65 97 76 13 27 49
输出从小到大的排序结果：13 27 38 49 49 65 76 97 
*/