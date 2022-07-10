/*
    带头结点的单链表就地逆置，空间复杂度为O(1)
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

void ReverseLinkList(LinkList &L) {
    LNode *cur = L->next;
    LNode *temp;
    //摘下头结点
    L->next = NULL;
    while (cur) {
        temp = cur->next;
        //将cur结点插入到头结点之后
        cur->next = L->next;
        L->next = cur;
        cur = temp;
    }
}

void ReverseLinkList_2(LinkList &L) {
    //依次遍历线性表L，并将指针反转
    LNode *pre;
    LNode *cur = L->next;
    LNode *temp = cur->next;
    cur->next = NULL;
    //temp为空，说明cur为最后一个结点
    while (temp) {
        //指针反转
        pre = cur;
        cur = temp;
        temp = temp->next;
        cur->next = pre;
    }
    //处理头结点
    L->next = cur;
}

int main() {
    int data[] = {1, 3, 3, 4};
    int n = ARRAY_SIZE(data);
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, n);
    printLinkList(L);
    ReverseLinkList(L);
    printLinkList(L);
    return 0;
}