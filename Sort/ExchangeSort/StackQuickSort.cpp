/* 
    快速排序——栈实现
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define ElemType int

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

//快速排序——栈实现
void QuickSortStack(ElemType a[], int num) {
    int i;
    int low, high;
    int top = -1;
    struct {
        int low, high;
    } St[MaxSize];
    //进栈
    top++;
    St[top].low = 0;
    St[top].high = num - 1;
    //栈不空取出一个子区进行划分
    while (top > -1) {
        //出栈
        low = St[top].low;
        high = St[top].high;
        top--;
        //区间内至少存在两个元素的情况
        if (low < high) {
            int pivotpos = Partition(a, low, high);
            top++;
            //左区间进栈
            St[top].low = low;
            St[top].high = pivotpos -1 ;
            top++;
            //右区间进栈
            St[top].low = pivotpos + 1;
            St[top].high = high;
        }
    }
}

int main() {
    int a[MaxSize] = { 0 };
    int num;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    QuickSortStack(a, num);
    printf("输出从小到大的排序结果：");
    Print(a, num);
    return 0;
}

/* 
输入要创建的数组长度：8
输入数据元素：49 38 65 97 76 13 27 49
输出从小到大的排序结果：13 27 38 49 49 65 76 97 
*/
