/*
    查找单链表倒数第K个元素
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

LNode * FindK(LinkList L, int k) {
    LNode *pre = L->next;
    LNode *cur = pre;
    int count = 0;
    while (cur) {
        if (count < k)
            count++;
        else 
            pre = pre->next;
        cur = cur->next;
    }
    if (count < k) 
        return NULL;
    else 
        return pre;
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6};
    int size = ARRAY_SIZE(data);
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, size);
    printLinkList(L);
    LNode *KNode = FindK(L, 3);
    printf("%d ", KNode->data);
    return 0;
}