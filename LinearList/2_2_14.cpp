/*
    找出距离最小的三元组
    S1 = {-1, 0, 9}
    S2 = {-25, -10, 10, 11}
    S3 = {2, 9, 17, 30, 41}
    最小的三元组为{9, 10, 9}
*/

#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 0x7fffffff
#define MaxSize 50
typedef struct SqList {
    int data[MaxSize];
    int Length;
} SqList;



