/*
    给定两个单链表，找出两个链表的公共结点
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

void CommonNode(LinkList M, LinkList N) {
    LNode *Mcur = M->next;
    LNode *Ncur = N->next;
    LNode *temp;
    printf("公共结点：");
    while (Mcur) {
        //记录N的初始结点
        temp = Ncur;
        while (Ncur) {
            if (Mcur->data == Ncur->data) {
                printf("%d ", Ncur->data);
                while (Ncur) {
                    if (Ncur->data == Ncur->next->data) {
                        Ncur = Ncur->next;
                    }
                    else {
                        break;
                    }
                }
                Ncur = Ncur->next;
            }
            Ncur = Ncur->next;
        }
        Mcur = Mcur->next;
        Ncur = temp;
    }
}

int main() {
    int data[] = {4, 3, 2, 1, 5, 0, 8, 7};
    int data2[] = {4, 1, 1, 1, 1, 1, 1, 8};
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
    CommonNode(M, N);
    return 0;
}