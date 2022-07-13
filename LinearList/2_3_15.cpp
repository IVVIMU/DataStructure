/*
    有两个按元素值递增次序排列的带头结点的单链表A、B表示两个集合
    求A与B的交集，并存放于A链表中
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

void Union(LinkList &A, LinkList &B) {
    LNode *pre = A;
    LNode *Acur = A->next;
    LNode *Bcur = B->next;
    LNode *temp;
    //如果A中的结点元素不是公共元素，就释放该结点
    while (Acur && Bcur) {
        if (Acur->data == Bcur->data) {
            pre->next = Acur;
            pre = Acur;
            Acur = Acur->next;
            temp = Bcur;
            Bcur = Bcur->next;
            free(temp);
        }
        else if (Acur->data < Bcur->data) {
            temp = Acur;
            Acur = Acur->next;
            free(temp);
        }
        else {
            temp = Bcur;
            Bcur = Bcur->next;
            free(temp);
        }
    }
    while (Acur) {
        temp = Acur;
        Acur = Acur->next;
        free(temp);
    }
    while (Bcur) {
        temp = Bcur;
        Bcur = Bcur->next;
        free(temp);
    }
    pre->next = NULL;
    free(B);
    printLinkList(A);
}

int main() {
    int data[] = {2, 3, 5, 7, 9};
    int data2[] = {1, 2, 3, 4};
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
    Union(M, N);
    return 0;
}