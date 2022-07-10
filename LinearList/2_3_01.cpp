/*
    设计一个递归算法删除不带头结点的单链表L中所有值为x的结点
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

//构建不带头结点的单链表
void CreateLinkList(LinkList &L, int data[], int n) {
    LNode *cur = L, *s;
    cur->data = data[0];
    if (n == 1)
        cur->next = NULL;
    else {
        for (int i = 1; i < n; i++) {
            s = (LNode *) malloc(sizeof(LNode));
            s->data = data[i];
            cur->next = s;
            cur = cur->next;
        }
        cur->next = NULL;
    }
}
void printLinkList(LinkList L) {
    LNode *cur = L;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void Delete_X(LinkList &L, int x) {
    if (L == NULL)
        return;
    LNode *temp;
    if (L->data == x) {
        temp = L;
        L = L->next;
        free(temp);
        Delete_X(L, x);
    }
    else {
        Delete_X(L->next, x);
    }
}

int main() {
    int data[] = {1, 3, 3, 4};
    int n = ARRAY_SIZE(data);
    LinkList L;
    InitList(L); 
    CreateLinkList(L, data, n);
    printLinkList(L);
    Delete_X(L, 3);
    printLinkList(L);
    return 0;
}

