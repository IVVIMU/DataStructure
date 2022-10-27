#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

//初始化双链表
bool InitDLinkList(DLinkList &L) {
    //分配一个头结点
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL) 
        return false;
    //头结点的prior永远指向NULL
    L->prior = NULL;
    L->next = NULL;
    return true;
}

//尾插法创建双链表
DLinkList DList_TailInsert(DLinkList &L) {
    int x;
    //建立双链表的头结点
    L = (DNode *) malloc(sizeof(DNode));
    L->prior = NULL;
    DNode *s, *r = L;
    printf("输入链表元素(输入9999终止):");
    scanf("%d", &x);
    while (x != 9999) {
        s = (DNode *) malloc(sizeof(DNode));
        s->data = x;
        r->next = s;
        s->prior = r;
        r = s;
        scanf("%d", &x);
    }
    //尾结点置空
    r->next = NULL;
    return L;

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
void DestoryList(DLinkList &L) {
    //循环释放各个数据结点
    while (L->next != NULL) 
        DeleteNextNode(L);
    //释放头结点
    free(L);
    //头指针指向NULL
    L = NULL;
}

//合并两个有序递增链表为一链表，且保持有序
DLinkList Merge(DLinkList L1, DLinkList L2, DLinkList L3) {
    InitDLinkList(L3);
    DNode *p, *q, *r;
    p = L1->next;
    q = L2->next;
    r = L3;
    while (p != NULL && q != NULL) {
        //记录后继结点
        // DNode *temp1 = p->next, *temp2 = q->next;
        if (p->data > q->data) {
            r->next = q;
            q->prior = r;
            r = r->next;
            q = q->next;
        } else {
            r->next = p;
            p->prior = r;
            r = r->next;
            p = p->next;
        }
    }
    if (p != NULL) {
        r->next = p;
        p->prior = r;
    }
    if (q != NULL) {
        r->next = q;
        q->prior = r;
    }
    return L3;
}

//打印双链表
void printDList(DLinkList L) {
    DNode *p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    //初始化双链表
    DLinkList L1, L2;
    DList_TailInsert(L1);
    DList_TailInsert(L2);
    printDList(L1);
    printDList(L2);
    DLinkList L3;
    L3 = Merge(L1, L2, L3);
    printDList(L3);
}

/*
输入链表元素(输入9999终止):23 45 78 9999
输入链表元素(输入9999终止):6 7 24 89 9999
23 45 78 
6 7 24 89
6 7 23 24 45 78 89
*/