/*
    两个循环单链表h1和h2，将h2链表链接到h1之后，要求链接后的链表仍保持循环链表形式
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

//初始化一个循环单链表
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL) 
        return false;
    L->next = L;
    return true;
}

//构建带头结点的循环单链表
void CreateLinkList(LinkList &L, int data[], int n) {
    LNode *cur = L, *s;
    for (int i = 0; i < n; i++) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = data[i];
        cur->next = s;
        cur = cur->next;
    }
    cur->next = L;
}

void printLinkList(LinkList L) {
    LNode *cur = L->next;
    while (cur != L) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void MergeLinkList(LinkList &M, LinkList &N) {
    LNode *Mcur = M->next;
    LNode *Ncur = N->next;
    while (Mcur->next != M) {
        Mcur = Mcur->next;
    }
    while (Ncur->next != N) {
        Ncur = Ncur->next;
    }
    Mcur->next = N->next;
    Ncur->next = M;
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int data2[] = {6, 7, 8};
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
}

