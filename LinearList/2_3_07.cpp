/*
    带头结点的无序单链表
    删除元素值在给定值之间的结点
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

void DeleteValue(LinkList &L, int s, int t) {
    if (s > t) {
        int value = s;
        s = t;
        t = value;
    }
    LNode *pre = L;
    LNode *cur = L->next;
    LNode *temp;
    while (cur) {
        if (cur->data > s && cur->data < t) {
            temp = cur;
            cur = cur->next;
            pre->next = cur;
            free(temp);
        }
        pre = cur;
        cur = cur->next;
    }
}

int main() {
    int data[] = {4, 3, 2, 1, 5, 0, 8, 7};
    int n = ARRAY_SIZE(data);
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, n);
    printLinkList(L);
    DeleteValue(L, 7, 3);
    //方便观察
    IncreasingeOrder(L);
    printLinkList(L);
    return 0;
}