/*
    循环删除循环单链表中结点值最小的结点，直至单链表为空
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

void CircularDeleteMin(LinkList &L) {
    LNode *cur, *pre;
    LNode *minp, *minpre;
    while (L->next != L) {
        cur = L->next;
        pre = L;
        minp = cur;
        minpre = pre;
        while (cur != L) {
            if (cur->data < minp->data) {
                minp = cur;
                minpre = pre;
            }
            pre = cur;
            cur = cur->next;
        }
        printf("%d ", minp->data);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
}

int main() {
    int data[] = {3, 7, 2, 1, 9};
    int size = ARRAY_SIZE(data);
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, size);
    CircularDeleteMin(L);
    return 0;
}