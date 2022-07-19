/*
    Q是一个队列，S是一个空栈，实现将队列中的元素逆置
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct SqQueue {
    int data[MaxSize];
    int front, rear;
    int tag;
} SqQueue;

//初始化队列
void InitQueue(SqQueue &Q) {
    Q.front = 0;
    Q.rear = 0;
    Q.tag = 0;
}

//判断队列是否为空
bool QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear && Q.tag == 0)
        return true;
    else 
        return false;
}

//入队
bool EnQueue(SqQueue &Q, int x) {
    //队满则返回false
    if (Q.front == Q.rear && Q.tag == 1)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = 1;
    return true;
}

//出队
bool DeQueue(SqQueue &Q, int &x) {
    if (Q.front == Q.rear && Q.tag == 0)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.tag = 0;
    return true;
}

//打印队列
void printQueue(SqQueue Q) {
    int x;
    for (int i = 0; i < MaxSize; i++) {
        printf("%d ", Q.data[Q.front]);
        Q.front = (Q.front + 1) % MaxSize;
    }
}

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

void Inverse(SqQueue &Q, SqStack &S) {
    int x;
    while (!(QueueEmpty(Q))) {
        DeQueue(Q, x);
        Push(S, x); 
    }

    while (!(StackEmpty(S))) {
        Pop(S, x);
        EnQueue(Q, x);
    }
}

int main() {
    SqQueue Q;
    SqStack S;
    InitQueue(Q);
    InitStack(S);
    for (int i = 0; i < MaxSize; i++) {
        EnQueue(Q, i + 1);
    }
    printQueue(Q);
    Inverse(Q, S);
    printf("\n");
    printQueue(Q);
    return 0;
}