/*
    设置一个标志域tag，并以tag的值为0或1来区分对空或队满，使循环队列中的元素都能得到利用
    出队将tag值设置为0，入队将tag值设置为1；
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