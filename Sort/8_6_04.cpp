/* 
    设有一个数组中存放了一个无序的关键序列k1,k2,...,kn，将kn放在元素排序后的正确位置上，要求比较关键字的次数不超过n
    算法思想：快速排序算法符合要求，以kn为枢轴进行一次划分
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define ElemType int 

int Partition(ElemType k[], int num) {
    //num是数组个数，最长下标需要减一
    int low = 0, high = num - 1;
    //以kn为枢轴
    ElemType pivot = k[high];
    while (low < high) {
        while (low < high && k[high] >= pivot)
            high--;
    //比枢轴小的元素移到左端
    k[low] = k[high];
    while (low < high && k[low] <= pivot)
        low++;
    //比枢轴大的元素移到右端
    k[high] = k[low];
    }
    //枢轴元素放到最终位置
    k[low] = pivot;
    //返回存放枢轴元素的最终位置
    return low;
}