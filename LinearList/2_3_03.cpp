/*
    带头结点的单链表
    实现从尾到头反向输出每个结点的值
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

// int * Reverse(LinkList L, int n) {
//     LNode *cur = L->next;
//     int* const arr = (int*) malloc(sizeof(int) * n);
//     int count = 0;
//     while (cur) {
//         arr[count++] = cur->data;
//         cur = cur->next;
//     }
//     return arr;
// }

//每当访问一个结点时，先递归输出它后面的结点，在输出该结点自身
void ReverseLinkList(LinkList L) {
    if (L->next != NULL) {
        ReverseLinkList(L->next);
    }
    if (L != NULL)
        printf("%d ", L->data);
}

//忽略头结点
void ReverseIgnoreHead(LinkList L) {
    if (L->next != NULL)
        ReverseLinkList(L->next);
}


int main() {
    int data[] = {1, 3, 3, 4};
    int n = ARRAY_SIZE(data);
    int *arr;
    int arrSize;
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, n);
    ReverseIgnoreHead(L);
    //ReverseLinkList(L);
    return 0;
}