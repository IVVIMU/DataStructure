/* 
    快速排序——队列实现
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

//快速排序——队列实现
void QuickSortQueue(ElemType a[], int num) {
    int i;
    int low, high;
    //队首、队尾指针
    int front = -1, rear = -1;
    struct {
        int low, high;
    } Qu[MaxSize];
    //进队
    rear = (rear + 1) % MaxSize;
    Qu[rear].low = 0;
    Qu[rear].high = num - 1;
    //队不空取出一个子区间进行划分
    while (front != rear) {
        //出队
        front = (front + 1) % MaxSize;
        low = Qu[front].low;
        high = Qu[front].high;
        if (low < high) {
            int pivotpos = Partition(a, low, high);
            rear = (rear + 1) % MaxSize;
            //左区间入队
            Qu[rear].low = low;
            Qu[rear].high = pivotpos - 1;
            rear = (rear + 1) % MaxSize;
            //右区间入队
            Qu[rear].low = pivotpos + 1;
            Qu[rear].high = high;
        }
    }
}

int main() {
    int a[MaxSize] = { 0 };
    int num;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    QuickSortQueue(a, num);
    printf("输出从小到大的排序结果：");
    Print(a, num);
    return 0;
}

/* 
输入要创建的数组长度：8
输入数据元素：49 38 65 97 76 13 27 49
输出从小到大的排序结果：13 27 38 49 49 65 76 97 
*/