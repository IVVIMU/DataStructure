/* 
    判断一个数据序列是否构成一个小根堆
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define ElemType int

bool IsMinHeap(ElemType a[], int num) {
    //num为偶数，有一个单分支结点
    if (num % 2 == 0) {
        //判断单分支节点
        if (a[num / 2] > a[num])
            return false;
        //判断所有双分支结点
        for (int i = num / 2 - 1; i >= 1; i--) {
            if (a[i] > a[2 * i] || a[i] > a[2 * i + 1])
                return false;
        }
    }
    //num为奇数，没有单分支结点
    else {
        for (int i = num / 2; i >= 1; i--) {
            //判断所有双分支结点
            if (a[i] > a[2 * i] || a[i] > a[2 * i + 1])
                return false;
        }
    }
    return true;
}