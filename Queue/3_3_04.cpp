/*
    渡口管理，过江渡船每次能载10辆车过江
    过江车辆分为客车类（K）和货车类（H）
    同类车先到先上船；客车先于货车上船，且每上4辆客车，才允许放上一辆货车；
    若等待客车不足4辆，则以货车代替；若无货车等待，允许客车都上船
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
    printf("\n");
}

void FerryManagement() {
    //渡口队列
    SqQueue ferry;
    //客车队列
    SqQueue k;
    //货车队列
    SqQueue h;
    InitQueue(ferry); InitQueue(k); InitQueue(h);
    for (int i = 0; i < MaxSize; i++) {
        EnQueue(k, 1);
        EnQueue(h, 2);
    }
    //count表示总车辆数
    int i = 0, count = 0;
    int e;
    while (count < 10) {
        //客车队列不为空且未上足4辆
        if (!QueueEmpty(k) && i < 4) {
            DeQueue(k, e);
            EnQueue(ferry, e);
            i++;
            count++;
        }
        //货车队列不为空且客车上满4辆
        else if (i == 4 && !QueueEmpty(h)) {
            DeQueue(h, e);
            EnQueue(ferry, e);
            count++;
            i = 0;
        }
        else {
            //在主车队未满且其中客车未满4辆并且货车队列未空时则以货车代替
            while (count < 10 && i < 4 && !QueueEmpty(h)) {
                DeQueue(h, e);
                EnQueue(ferry, e);
                i++;
                count++;
            }
            i = 0;
        }
        if (QueueEmpty(k) && QueueEmpty(h)) 
            //客车和货车加起来不足10辆
            //count = 11;
            break;
    }
    printQueue(k);
    printQueue(h);
    printQueue(ferry);
}

int main() {
    FerryManagement();
    return 0;
}