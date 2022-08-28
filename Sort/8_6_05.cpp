/* 
    计数排序的第二种实现
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define ElemType int 

void cmpCountSort(ElemType a[], ElemType b[], int n) {
    int i, j;
    //等价于c++  count = new int[n];
    ElemType *count = (ElemType *) malloc(sizeof(ElemType) * n);
    //初始化count数组
    for (i = 0; i < n; i++) 
        count[i] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] < a[j])
                count[j]++;
            else
                count[i]++;
        }
    }
    for (i = 0; i < n; i++) 
        b[count[i]] = a[i];
    //等价于c++  delete count;
    free(count);
}