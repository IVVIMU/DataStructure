/*
    判断是否中心对称
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

/*
    使用栈来判断链表是否对称，
    让前一半元素依次进栈，当访问到链表最后一个元素时，执行弹栈操作，比较两个元素是否相等
*/
bool isSymmetry(LinkList L, int size) {
    //创建一个栈
    int s[size / 2];
    LNode *cur = L->next;
    int i;
    for (i =0; i < size / 2; i++) {
        s[i] = cur->data;
        cur = cur->next;
    }
    //恢复到最后的i值
    i--;
    //如果size是奇数，cur指针后移过中心结点，中心节点没有存入栈
    if (size % 2 == 1)
        cur = cur->next;
    while (cur != NULL && s[i] == cur->data) {
        i--;
        cur = cur->next;
    }
    //栈为空栈的情况
    if (i == -1)
        return true;
    else 
        return false;
}

int main() {
    int data[] = {1, 2, 4, 2, 1};
    int size = ARRAY_SIZE(data);
    LinkList L;
    InitList(L);
    CreateLinkList(L, data, size);
    printLinkList(L);
    if (isSymmetry(L, size))
        printf("中心对称");
    else 
        printf("不中心对称");
    return 0;
}