/*
    带头结点的单链表
    删除一个最小是节点的高效算法
    假设最小是结点时唯一的
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

void DeleteMin(LinkList &L) {
    LNode *pre = L, *cur = pre->next;
    LNode *minPre = pre, *minP = cur;
    while (cur) {
        if (cur->data <= minP->data) {
            minP = cur;
            minPre = pre;
        }
        pre = cur;
        cur = cur->next;
    }
    //删除最小的结点
    minPre->next = minP->next;
    free(minP);
}

int main() {
    int data[] = {1, 3, 3, 4};
    int n = ARRAY_SIZE(data);
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, n);
    printLinkList(L);
    DeleteMin(L);
    printLinkList(L);
    return 0;
}