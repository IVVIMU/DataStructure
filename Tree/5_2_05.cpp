/*
    两个结点的最近公共祖先结点的值
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int 
#define MaxSize 100

typedef ElemType SqBiTree[MaxSize]; 

int main() {
    SqBiTree bt;
}

ElemType CommonAncester(SqBiTree T, int i, int j) {
    //结点存在
    if (T[i] != '#' && T[j] != '#') {
        while (i != j) {
            if (j > j)
                i = i / 2;
            else
                j = j / 2;
        }
        return T[i];
    }
}