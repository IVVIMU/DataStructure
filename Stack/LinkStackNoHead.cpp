#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ElemType int

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkStack;

//初始化(不带头结点)
bool InitStack(LinkStack &S) {
    S = NULL;
    return true;
}

//判断栈是否为空(不带头结点)
bool StackEmpty(LinkStack S) {
    if (S == NULL)
        return true;
    else
        return false;
}

//入栈(不带头结点)
void Push(LinkStack &S, ElemType x) {
    LNode *node = (LNode *) malloc(sizeof(LNode));
    node->data = x;
    if (S == NULL) {
        node->next = NULL;
        S = node;
    }
    node->next = S;
    S = node;
}

//出栈(不带头结点)
bool Pop(LinkStack &S, ElemType &x) {
    if (S == NULL)
        return false;
    LNode *temp;
    temp = S;
    x = temp->data;
    S = temp->next;
    free(temp);
    return true;
}

//读取栈顶元素(不带头结点)
bool GetTop(LinkStack S, ElemType &x) {
    if (S == NULL)
        return false;
    x = S->data;
    return true;
}

int main() {
    LinkStack S;
    InitStack(S);
    int x;
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        Push(S, i + 1);
    }
    GetTop(S, x);
    printf("\n%d\n", x);
    /*
        循环时判空有问题，慎用
    */
    while (S) {
        Pop(S, x);
        printf("%d ", x);
    }
    return 0;
}