/*
    一个带头结点的单链表分解为两个带头结点的单链表A和B
    A表中含有原表中序号为奇数的元素
    B表中含有原表中序号为偶数的元素
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

void SplitLinkList(LinkList L, LinkList &A, LinkList &B) {
    LNode *Lcur = L->next;
    LNode *Acur = A, *Bcur = B;
    int flag = 0;
    while (Lcur) {
        //奇数位
        if (flag % 2 != 0) {
            LNode *temp = (LNode *) malloc(sizeof(LNode));
            temp->data = Lcur->data;
            temp->next = NULL;
            Acur->next = temp;
            Acur = Acur->next;
            Lcur = Lcur->next;
            flag++;
        }
        else {
            LNode *temp = (LNode *) malloc(sizeof(LNode));
            temp->data = Lcur->data;
            temp->next = NULL;
            Bcur->next = temp;
            Bcur = Bcur->next;
            Lcur = Lcur->next;
            flag++;
        }
    }
}

int main() {
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int n = ARRAY_SIZE(data);
    LinkList L;
    LinkList A;
    LinkList B;
    InitList(L);
    InitList(A);
    InitList(B);
    CreateLinkList(L, data, n);
    printLinkList(L);
    SplitLinkList(L, A, B);
    printLinkList(A);
    printLinkList(B);
    return 0;
}