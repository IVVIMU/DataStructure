/*
    带头尾指针的链表
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int

//结点定义
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LNode;

//带头尾节点的单链表定义
typedef struct {
    LNode head;
    LNode tail;
} List, *LinkList;

//创建空链表
LinkList create() {
    LinkList L;
    LNode HeadNode;
    L = (LinkList) malloc(sizeof(List));
    HeadNode = (LNode) malloc(sizeof(Node));

    HeadNode->next = NULL;
    L->head = HeadNode;
    L->tail = HeadNode;
    return L;
}

//尾插法
void AddBack(LinkList L, ElemType val) {
    LNode newNode;
    newNode = (LNode) malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    L->tail->next = newNode;
    L->tail = newNode;
}

void Add(LinkList L, ElemType val) {
    LNode p;
    LNode newNode;
    newNode = (LNode) malloc(sizeof(Node));
    newNode->data = val;
    p = L->head;
    while (p->next->data < val) {
        p = p->next;
        if (p->next == NULL) 
            break;
    }
    newNode->next = p->next;
    p->next = newNode;
    if (p == L->tail) {
        L->tail = newNode;
    }
}