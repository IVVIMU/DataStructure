/*
    两个栈模拟队列，实现队列的三个运算
    EnQueue     //将元素x入队
    DeQueue     //出队，并将出队元素存储在x中
    QueueEmpty  //判断队列是否为空
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

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

//判断栈满
bool StackOverflow(SqStack S) {
    if (S.top == MaxSize - 1)
        return true;
    else
        return false;
}

//新元素入栈
bool Push(SqStack &S, int x) {
    //栈满
    if (S.top == MaxSize - 1)
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

void printStack(SqStack S) {
    while (!StackEmpty(S)) {
        printf("%d ", S.data[S.top]);
        S.top--;
    }
    printf("\n");
}

bool EnQueue(SqStack &S1, int x) {
    if (StackOverflow(S1))
        return false;
    S1.top = S1.top + 1;
    S1.data[S1.top] = x;
    return true;
}

bool DeQueue(SqStack &S1, SqStack &S2, int &x) {
    int temp;
    while (!StackEmpty(S1)) {
        Pop(S1, temp);
        Push(S2, temp);
    }

    Pop(S2, x);

    while (!StackEmpty(S2)) {
        Pop(S2, temp);
        Push(S1, temp);
    }
}

bool QueueEmpty(SqStack S1, SqStack S2) {
    if (StackEmpty(S1) && StackEmpty(S2))
        return true;
    else 
        return false;
}

int main() {
    SqStack S1;
    SqStack S2;
    int x;
    InitStack(S1);
    InitStack(S2);
    for (int i = 0; i < 1; i++) {
        EnQueue(S1, i + 1);
    }
    printStack(S1);
    DeQueue(S1, S2, x);
    printf("%d \n", x);
    printStack(S1);
    if (QueueEmpty(S1, S2))
        printf("已空！");
    else
        printf("未空！");
}