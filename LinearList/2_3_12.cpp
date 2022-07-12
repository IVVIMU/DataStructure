/*
    一个带头结点的单链表递增有序，去掉数值相同的结点
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

void RemoveSame(LinkList &L) {
    LNode *cur = L->next;
    LNode *temp;
    while (cur->next != NULL) {
        if (cur->data == cur->next->data) {
            temp = cur->next;
            cur->next = cur->next->next;
            free(temp);
        }
        else {
            cur = cur->next;
        }
    }
}

int main() {
    int data[] = {4, 1, 1, 1, 1, 1, 1, 8};
    int n = ARRAY_SIZE(data);
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, n);
    printLinkList(L);
    RemoveSame(L);
    printLinkList(L);
    return 0;
}