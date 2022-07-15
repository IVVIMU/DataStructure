/*
    判断单链表是否存在环
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

void isCircular(LinkList L) {
    LNode *cur = L->next;
    LNode *next;
    while (cur != NULL && cur->next != NULL) {
        next = cur->next;
        if (cur->next->next == next->next) {
            printf("该单链表有环");
            break;
        }
        else {
            cur = cur->next;
        }
    }
    if (cur == NULL) {
       printf("该单链表无环"); 
    }
}

//返回循环入口点
LNode *FindLoopStart(LinkList L) {
    LNode *fast = L;
    LNode *slow = fast;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (slow == NULL || fast == NULL) {
        return NULL;
    }
    LNode *loopStart = L;
    while (loopStart != slow) {
        loopStart = loopStart->next;
        slow = slow->next;
    }
    return loopStart;
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = ARRAY_SIZE(data);
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, size);
    //isCircular(L);
    LNode *loopStart = FindLoopStart(L);
    printf("%d ", loopStart->data);
    return 0;
}

