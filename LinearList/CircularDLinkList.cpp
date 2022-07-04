#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinklist;

//初始化空的循环双链表
bool InitDLinkList(DLinklist &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = L;
    L->next = L;
    return true;
}

//判断循环双链表是否为空
bool Empty(DLinklist L) {
    if (L->next == L)
        return true;
    else
        return false;
}

//判断结点p是否为循环双链表的表尾结点
bool isTail(DLinklist L, DNode *p) {
    if (p->next == L)
        return true;
    else 
        return false;
}

//在p结点之后插入s结点
bool InsertNextNode(DNode *p, DNode *s) {
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

//删除p的后继结点q
bool DeleteNextNode(DNode *p) {
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
}

int main() {
    //初始化循环双链表
    DLinklist L;
    InitDLinkList(L);
}