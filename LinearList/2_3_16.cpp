/*
    A = {a1, a2, a2,...,an} B = {b1, b2, b3,...,bn}
    判断B是否是序列A的连续子序列
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

void isSubSequence(LinkList M, LinkList N) {
    LNode *Mpre = M->next;
    LNode *Mcur = M->next;
    LNode *Ncur = N->next;
    while (Mcur && Ncur) {
        if (Mcur->data == Ncur->data) {
            Mcur = Mcur->next;
            Ncur = Ncur->next;
        }
        else {
            Mpre = Mpre->next;
            Mcur = Mpre;
            Ncur = N->next;
        }
    }
    if (Ncur == NULL)
        printf("LinkListB is the sub sequence of LinkListA.");
    else 
        printf("false");

}

int main() {
    int data[] = {2, 5, 7, 8, 3, 5, 7, 9};
    int data2[] = {5, 7, 9};
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
    isSubSequence(M, N);
    return 0;
}