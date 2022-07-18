#include <stdio.h>
#include <stdlib.h>

//链式队列结点
typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkQueue {
    LinkNode *front, *rear;
} LinkQueue;

//初始化队列（带头结点）
void InitQueue(LinkQueue &Q) {
    //初始时 front、rear 都指向头结点
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

//判断队列是否为空（带头结点）
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else 
        return false;
}

//入队（带头结点）
void EnQueue(LinkQueue &Q, int x) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

//出队（带头结点）
bool DeQueue(LinkQueue &Q, int &x) {
    if (Q.front == Q.rear)
        return false;
    LinkNode *temp = Q.front->next;
    x = temp->data;
    Q.front->next = temp->next;
    //如果是最后一个结点出队
    if (Q.rear == temp)
        Q.rear = Q.front;
    free(temp);
    return true;
}

//初始化队列（不带头结点）
// bool InitQueue(LinkQueue &Q) {
//     //初始时 front、rear 都指向NULL
//     Q.front = NULL;
//     Q.rear = NULL;
// }

// //判断队列是否为空（不带头结点）
// bool IsEmpty(LinkQueue Q) {
//     if (Q.front == NULL)
//         return true;
//     else
//         return false;
// }

//入队（不带头结点）
// void EnQueue(LinkQueue &Q, int x) {
//     LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
//     s->data = x;
//     s->next = NULL;
//     //在空队列中插入第一个元素
//     if (Q.front == NULL) {
//         Q.front = s;
//         Q.rear = s;
//     }
//     else {
//         Q.rear->next = s;
//         Q.rear = s;
//     }
// }

//出队（不带头结点）
// bool DeQueue(LinkQueue &Q, int &x) {
//     if (Q.front == NULL)
//         return false;
//     LinkNode *temp = Q.front;
//     x = temp->data;
//     Q.front = temp->next;
//     //如果是最后一个结点出队
//     if (Q.rear == temp) {
//         Q.front = NULL;
//         Q.rear = NULL;
//     }
//     free(temp);
//     return true;
// }