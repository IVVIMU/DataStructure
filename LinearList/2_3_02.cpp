/*
    设计一个算法删除带头结点的单链表L中所有值为x的结点
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

//递归的写法行不通，递归每次调用自己都会有执行头结点的操作，但头结点只有一个
//至少我想不到方法解决
// void Delete_X(LinkList &L, int x) {
//     if (L->next == NULL)
//         return;
//     LNode *cur = L->next;
//     LNode *pre = L;
//     LNode *temp;
//     while (cur != NULL) {
//        if (cur->data == x) {
//             temp = cur;
//             cur = cur->next;
//             pre->next = cur;
//             free(temp);
//             Delete_X(cur, x);
//         }
//         else {
//             Delete_X(cur->next, x);
//         } 
//     }    
// }

void Delete_X_2(LinkList &L, int x) {
    LNode *cur = L->next;
    LNode *pre = L;
    LNode *temp;
    while (cur) {
        if (cur->data == x) {
            temp = cur;
            cur = cur->next;
            pre->next = cur;
            free(temp);
        }
        else {
            pre = cur;
            cur = cur->next;
        }
    }
}

int main() {
    int data[] = {1, 3, 3, 4};
    int n = ARRAY_SIZE(data);
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, n);
    printLinkList(L);
    Delete_X_2(L, 3);
    printLinkList(L);
    return 0;
}