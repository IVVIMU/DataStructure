#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct SqQueue {
    int data[MaxSize];
    int front, rear;
} SqQueue;

//初始化队列
void InitQueue(SqQueue &Q) {
    Q.front = 0;
    Q.rear = 0;
}

//判断队列是否为空
bool QueueEmpty(SqQueue Q) {
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}

//循环队列入队
bool EnQueue(SqQueue &Q, int x) {
    //浪费数组一个空间来判断是否队满
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

//循环队列出队
bool DeQueue(SqQueue &Q, int &x) {
    //如果 front==rear，表示队列为空
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

//队列元素个数
int QueueSize(SqQueue Q) {
    int size;
    size = (Q.rear + MaxSize - Q.front) % MaxSize;
    return size;
}
