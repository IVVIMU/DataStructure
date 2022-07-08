/*
    主元素
    {0，5，5，3，5，7，5，5} --> 5为主元素
    {0，5，5，3，5，1，5，7} --> 没有主元素
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef struct SqList {
    int data[MaxSize];
    int Length;
} SqList;

int Majority(SqList L) {
    int mid = L.Length / 2;
    int i, majority;
    int count = 1;
    majority = L.data[0];
    for (i = 1; i < L.Length; i++) {
        if (L.data[i] == majority) {
            count++;
        }
        else {
            if (count > 0) {
                count--;
            }
            else {
                majority = L.data[i];
                count = 1;
            }
        }
    }
    if (count > 0) {
            for (i = count = 0; i < L.Length; i++) {
                if (L.data[i] == majority)
                    count++;
            }
        }
        if (count > mid)
            return majority;
        else 
            return -1;
}

int main() {
    SqList L = {{0,5,5,3,5,7,5,5}, 8};
    int majority;
    majority = Majority(L);
    printf("%d", majority);

}