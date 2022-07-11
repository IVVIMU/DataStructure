/*
    带头结点的单链表，其元素递增有序
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

void IncreasingeOrder(LinkList &L) {
    LNode *pre, *next;
    LNode *cur = L->next;
    while (cur) {
        pre = cur;
        next = cur->next;
        while (next) {
            if (cur->data > next->data) {
                int value = cur->data;
                cur->data = next->data;
                next->data = value;
            }
            next = next->next;
        }
        cur = cur->next;
    }
}

int main() {
    int data[] = {4, 3, 2, 1, 5, 0, 8};
    int n = ARRAY_SIZE(data);
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, n);
    printLinkList(L);
    IncreasingeOrder(L);
    printLinkList(L);
    return 0;
}

