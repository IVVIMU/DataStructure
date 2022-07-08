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

int abs_(int a) {
    if (a < 0)
        return -a;
    else 
        return a;
}

bool three_min(int a, int b, int c) {
    if (a <= b && a <= c)
        return true;
    else 
        return false;
}

int findMinOfTrip(SqList A, SqList B, SqList C) {
    //D_min用于记录三元组的最小距离，初赋值为INT_MAX
    int i = 0, j = 0, k = 0;
    int D_min = INT_MAX;
    int D;
    while (i < A.Length && j < B.Length && k < C.Length && D_min > 0) {
        D = abs_(A.data[i] - B.data[j]) + abs_(B.data[j] - C.data[k]) + abs_(C.data[k] - A.data[i]);
        if (D < D_min)
            D_min = D;
        if (three_min(A.data[i], B.data[j], C.data[k]))
            i++;
        else if (three_min(B.data[j], C.data[k], A.data[i]))
            j++;
        else 
            k++;
    }
    return D_min;
}

int main() {
    SqList A = {{-1, 0, 9}, 3};
    SqList B = {{-25, -10, 10, 11}, 4};
    SqList C = {{2, 9, 17, 30, 41}, 5};
    int D_min = findMinOfTrip(A, B, C);
    printf("%d", D_min);
}