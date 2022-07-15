/*
    删除单链表中绝对值相同的元素
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

void DeleteAbs(LinkList &L, int size) {
    LNode *pre = L;
    LNode *temp;
    int *arr, m;
    arr = (int *) malloc(sizeof(int) * (size + 1));
    for (int i = 0; i < size + 1; i++) {
        *(arr + i) = 0;
    }
    while (pre->next != NULL) {
        m = abs(pre->next->data);
        if (*(arr + m) == 0) {
            *(arr + m) = 1;
            pre = pre->next;
        }
        else {
            temp = pre->next;
            pre->next = temp->next;
            free(temp);
        }
    }
    free(arr);
}

int main() {
    int data[] = {21, -15, -15, 7, 2, 15};
    //int data[] = {1,-4,2,3,4,-2};
    int size = ARRAY_SIZE(data);
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, size);
    printLinkList(L);
    DeleteAbs(L, 21);
    printLinkList(L);
    return 0;
}