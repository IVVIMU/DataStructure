#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinklist;

//初始化双链表
bool InitDLinkList(DLinklist &L) {
    //分配一个头结点
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL) 
        return false;
    //头结点的prior永远指向NULL
    L->prior = NULL;
    L->next = NULL;
    return true;
}

//双链表的插入，在p结点之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s) {
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    //如果p结点有后续代码
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//双链表的删除，删除p结点的后续结点
bool DeleteNextNode(DNode *p) {
    if (p == NULL)
        return false;
    DNode *q = p->next;
    if (q == NULL)
        return false;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

//双链表的销毁
void DestoryList(DLinklist &L) {
    //循环释放各个数据结点
    while (L->next != NULL) 
        DeleteNextNode(L);
    //释放头结点
    free(L);
    //头指针指向NULL
    L = NULL;
}

int main() {
    //初始化双链表
    DLinklist L;
    InitDLinkList(L);
}