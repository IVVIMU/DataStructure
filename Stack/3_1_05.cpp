/*
    两个栈共享一片存储区，设计入栈和出栈的操作
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct ShStack {
    int data[MaxSize];
    int top[2];
} ShStack;

ShStack S;
//入栈
bool Push(int i, int x) {
    if (i < 0 || i > 1) {
        printf("栈号输入不对！\n");
        exit(0);
    }
    if (S.top[1] - S.top[0] == 1) {
        printf("栈已满！\n");
        return false;
    }
    if (i == 0) {
        S.data[++S.top[0]] = x;
        return true;
    }
    else {
        S.data[--S.top[1]] = x;
        return true;
    }
}

//出栈
bool Pop(int i, int &x) {
    if (i < 0 || i > 1) {
        printf("栈号输入不对！\n");
        exit(0);
    }
    if (i == 0) {
        if (S.top[0] == -1) {
            printf("栈空！\n");
            return false;
        }
        else {
            x = S.data[S.top[0]--];
            return true;
        }
    }
    else {
        if (S.top[1] == -1) {
            printf("栈空！\n");
            return false;
        }
        else {
            x = S.data[S.top[1]++];
            return true;
        }
    }
}

int main() {
    S.top[0] = -1;
    S.top[1] = MaxSize;
    if (Push(0,2))
        printf("0号栈进栈成功\n");
    int x;
    if (Pop(0, x))
        printf("0号栈出栈元素为：%d\n", x);

    Pop(0, x);

    return 0;
}

