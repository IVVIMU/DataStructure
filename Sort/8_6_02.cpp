/* 
    表中元素存储在数组下标1 ~ m + n的范围内，前m个元素递增有序，后n个元素递增有序，设计一个算法，使整个顺序表有序
    算法思想：将数组视为一个已经经过m趟插入排序的表，则从m + 1趟开始，将后n个元素依次插入到前面的有序表中
    也可以采用归并排序
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define ElemType int 

void InsertSort(ElemType a[], int m, int n) {
    int i, j;
    for (i = m + 1; i <= m + n; i++) {
        //复制为哨兵
        a[0] = a[i];
        for (j = i - 1; a[j] > a[0]; j--) {
            //元素后移
            a[j + 1] = a[j];
        }
        a[j + 1] = a[0];
    }
}

