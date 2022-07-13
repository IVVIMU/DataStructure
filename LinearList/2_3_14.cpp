/*
    有两个按元素值递增次序排列的带头结点的单链表A、B
    两个链表中的公共元素产生单链表C，不破坏A、B的结点
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

void CommonLinkList(LinkList A, LinkList B) {
    LinkList C;
    InitList(C);
    LNode *Ccur = C;
    LNode *Acur = A->next;
    LNode *Bcur = B->next;
    while (Acur && Bcur) {
        if (Acur->data < Bcur->data)
            Acur = Acur->next;
        else if (Acur->data > Bcur->data)
            Bcur = Bcur->next;
        else {
            LNode *node = (LNode *) malloc(sizeof(LNode));
            node->data = Acur->data;
            Ccur->next = node;
            Ccur = node;
            Acur = Acur->next;
            Bcur = Bcur->next;
        }
    }
    Ccur->next = NULL;
    printLinkList(C);
}

int main() {
    int data[] = {1, 2, 3, 4};
    int data2[] = {2, 3, 5, 7, 9};
    int m = ARRAY_SIZE(data);
    int n = ARRAY_SIZE(data2);
    LinkList M;
    LinkList N;
    InitList(M);
    InitList(N);
    CreateLinkList(M, data, m);
    CreateLinkList(N, data2, n);
    printLinkList(M);
    printLinkList(N);
    CommonLinkList(M, N);
    return 0;
}