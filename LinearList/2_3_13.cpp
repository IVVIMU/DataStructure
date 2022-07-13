/*
    有两个按元素值递增次序排列带头结点的单链表
    归并为一个按元素值递减次序排列的单链表
    要求利用原来两个单链表的结点
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

void MergeLinkList(LinkList &M, LinkList &N) {
    LNode *Mcur = M->next;
    LNode *Ncur = N->next;
    LNode *temp;
    M->next = NULL;
    while (Mcur && Ncur) {
        if (Mcur->data <= Ncur->data) {
            temp = Mcur->next;
            //逆置，头插法
            Mcur->next = M->next;
            M->next = Mcur;
            Mcur = temp;
        }
        else {
            //暂存Ncur的后继结点
            temp = Ncur->next;
            Ncur->next = M->next;
            M->next = Ncur;
            Ncur = temp;
        }
    }
    if (Mcur) 
        Ncur = Mcur;
    while (Ncur) {
        temp = Ncur->next;
        Ncur->next = M->next;
        M->next = Ncur;
        Ncur = temp;
    }
    free(N);
}

int main() {
    int data[] = {2, 4, 5, 7};
    int data2[] = {1, 3, 6, 8};
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
    MergeLinkList(M, N);
    printLinkList(M);
    return 0;
}