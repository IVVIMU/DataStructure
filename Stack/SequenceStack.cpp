#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef struct SqStack {
    int data[MaxSize];
    int top;
} SqStack;

//初始化
void InitStack(SqStack &S) {
    S.top = -1;
}

//判断栈空
bool StackEmpty(SqStack S) {
    if (S.top == -1)
        return true;
    else 
        return false;
}

//新元素入栈
bool Push(SqStack &S, int x) {
    //栈满
    if (S.top = MaxSize - 1)
        return false;
    //S.data[++S.top] = x;
    S.top = S.top + 1;
    S.data[S.top] = x;
    return true;
}

//元素出栈
bool Pop(SqStack &S, int &x) {
    //栈空
    if (S.top == -1) 
        return false;
    //x = S.data[S.top--];
    x = S.data[S.top];
    S.top = S.top - 1;
    return true;
}

//读栈顶元素
bool GetTop(SqStack S, int &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

//共享栈
typedef struct ShStack {
    int data[MaxSize];
    int top0;
    int top1;
} ShStack;

void InitShStack(ShStack &S) {
    S.top0 = -1;
    S.top1 = MaxSize;
}

//判断栈满
bool ShStackFull(ShStack &S) {
    if (S.top0 + 1 == S.top1)
        return true;
    else 
        return false;
}