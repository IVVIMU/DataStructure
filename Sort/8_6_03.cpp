/* 
    计数排序，表中元素各不相同，每趟排序中扫描有多少个元素比选定元素小，假设统计值为c,则这个记录在新有序表中的合适存放位置即为c
    算法思想：对每个元素，统计关键字比它小的元素个数，然后把它放入另一个数组对应的位置上
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define ElemType int 

void CountSort(ElemType a[], ElemType b[], int num) {
    int count = 0;
    //逐个遍历元素
    for (int i = 0; i < num; i++) {
        for (int j = 0, count = 0; j < num; j++) {
            if (a[j] < a[i])
                count++;
        }
        b[count] = a[i];
    }
}