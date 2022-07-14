/*
    判断带头结点的循环双链表是否对称
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

//初始化空的循环双链表
bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = L;
    L->next = L;
    return true;
}

//构建带头结点的循环双链表
void CreateDLinkList(DLinkList &L, int data[], int n) {
    DNode *cur = L, *s;
    for (int i = 0; i < n; i++) {
        s = (DNode *) malloc(sizeof(DNode));
        s->data = data[i];
        s->next = cur->next;
        cur->next->prior = s;
        s->prior = cur;
        cur->next = s;
        cur = s;
        //L->prior = s;
    }
}

void printDLinkList(DLinkList L) {
    DNode *cur = L->next;
    while (cur != L) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

bool isSymmetric(DLinkList L) {
    DNode *head = L->next;
    DNode *tail = L->prior;
    while (head != tail && tail->next != head) {
        if (head->data == tail->data) {
            head = head->next;
            tail = tail->prior;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    int data[] = {1, 2, 3, 4, 3, 2, 1, 1};
    int size = ARRAY_SIZE(data);
    bool flag;
    DLinkList L;
    InitDLinkList(L);
    CreateDLinkList(L, data, size);
    printDLinkList(L);
    flag = isSymmetric(L);
    if (flag) {
        printf("对称");
    }
    else {
        printf("不对称");
    }
    return 0;
}