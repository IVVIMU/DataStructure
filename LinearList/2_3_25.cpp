/*
    带头结点的单链表L = {a1, a2, a3,...,an} --> L = {a1, an, a2,...}
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    //内存不足，分配失败
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

//构建带头结点的单链表
void CreateLinkList(LinkList &L, int data[], int n) {
    LNode *cur = L, *s;
    for (int i = 0; i < n; i++) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = data[i];
        cur->next = s;
        cur = cur->next;
    }
    cur->next = NULL;
}

void printLinkList(LinkList L) {
    LNode *cur = L->next;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void Sorted(LinkList &L) {
    LNode *p = L, *q= L;
    LNode *temp, *s;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
        if (q->next != NULL)
            q = q->next;
    }
    //p所指结点为中间结点，q为后半段链表的首结点
    q = p->next;
    p->next = NULL;
    //链表后半段逆置
    while (q) {
        temp = q->next;
        q->next = p->next;
        p->next = q;
        q = temp;
    }
    //s指前半段的第一个数据结点，即插入点
    s = L->next;
    //q指向后半段的第一个数据结点
    q = p->next;
    p->next = NULL;
    while (q) {
        temp = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = temp;
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = ARRAY_SIZE(data);
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, size);
    printLinkList(L);
    Sorted(L);
    printLinkList(L);
    return 0;
}