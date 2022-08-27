/* 
    堆排序
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define ElemType int

void Input(int a[], int num) {
    int data;
    printf("输入数据元素：");
    for (int i = 1; i <= num; i++) {
        scanf("%d", &data);
        a[i] = data;
    }
}

void Print(int a[], int num) {
    for (int i = 1; i <= num; i++) {
        printf("%d ", a[i]);
    }
}

//交换函数
void swap(ElemType &a, ElemType &b) {
    ElemType temp = a;
    a = b;
    b = temp;
}

//将以下标k的元素为根的子树进行调整（大根堆）
void HeadAdjust(ElemType a[], int k, int num) {
    int i, temp;
    //暂存子树的根结点
    temp = a[k];
    //沿关键字较大的子结点向下筛选
    for (i = 2 * k; i <= num; i = i * 2) {
        //取关键字较大的子结点的下标
        if (i < num && a[i] < a[i + 1])
            i++;
        if (temp >= a[i])
            break;
        else {
            //将左右孩子中较大的值调整到父结点上
            a[k] = a[i];
            //记录该元素下标,进行下一轮调整
            k = i;
        }
    }
    //被筛选结点的值放入最终位置
    a[k] = temp;
}

//建立大根堆
void BuildMaxHeap(ElemType a[], int num) {
    for (int i = num / 2; i > 0; i--)
        HeadAdjust(a, i, num);
}

//堆的插入
void HeapInsert(ElemType a[], int &num, ElemType x) {
    int i;
    //元素个数加一
    num++;
    //新元素放到末尾
    a[num] = x;
    //与父结点对比
    for (i = num; i > 1; i = i / 2) {
        //若新元素比父结点更小，则将二者互换
        if (a[i] > a[i / 2])
            swap(a[i], a[i / 2]);
    }
}

//堆的删除
bool Delete(ElemType a[], int &num, ElemType x) {
    int i, temp;
    //查找要删除的元素的位置
    for (i = 1; i <= num && a[i] != x; i++);
    if (i > num) 
        return false;
    else
        a[i] = a[num];  //被删除的元素用堆底元素代替
    num--;
    temp = a[i];
    //元素不断“下坠”
    for (int j = 2 * i; j <= num; j *= 2) {
        //j指向孩子结点中关键字较大的一个
        if (j < num && a[j] < a[j + 1])
            j++;
        if (temp >= a[j])
            break;
        else {
            a[i] = a[j];
            i = j;
        }
        a[i] = temp;
    }
    return true;
}

//堆排序
void HeapSort(ElemType a[], int num) {
    BuildMaxHeap(a, num);
    //n-1趟的建堆和交换过程
    for (int i = num; i > 1; i--) {
        //堆顶元素与堆底元素交换
        swap(a[1], a[i]);
        //把剩下i - 1个元素调整成堆
        HeadAdjust(a, 1, i - 1);
    }
}

int main() {
    int a[MaxSize] = { 0 };
    int num;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    HeapSort(a, num);
    printf("输出大根堆排序结果：");
    Print(a, num);
}

/* 
输入要创建的数组长度：9
输入数据元素：36 74 28 43 59 12 7 80 67
输出大根堆排序结果：7 12 28 36 43 59 67 74 80 
*/