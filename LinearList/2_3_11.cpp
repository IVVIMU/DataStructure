/*
    一个带头结点的单链表C就地拆分为两个带头结点的单链表A和B
    C = {a1, b1, a2, b2,...,an, bn } --> A = {a1, a2,...,an} B = {bn,...,b2, b1}
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

void SplitLinkList(LinkList &A) {
    LinkList B = (LinkList) malloc(sizeof(LNode));
    B->next = NULL;
    LNode *cur = A->next;
    LNode *temp;
    LNode *pre = A;
    while (cur) {
        pre->next = cur;
        pre = cur;
        cur = cur->next;
        //头插法
        if (cur != NULL) {
            temp = cur->next;
            cur->next = B->next;
            B->next = cur;
            cur = temp;
        }
    }
    //A链表的末尾指向NULL
    pre->next = NULL;
    printLinkList(A);
    printLinkList(B);
}

int main() {
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int n = ARRAY_SIZE(data);
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, n);
    SplitLinkList(L);
    return 0;
}