/*
    栈的链式存储即采用头插法的单链表
*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkStack;

//初始化(带头结点)
bool InitStack(LinkStack &S) {
    S = (LNode *) malloc(sizeof(LNode));
    //内存不足，分配失败
    if (S == NULL)
        return false;
    S->next = NULL;
    return true;
} 

//判断栈是否为空(带头结点)
bool StackEmpty(LinkStack S) {
    if (S->next == NULL)
        return true;
    else 
        return false;
}

//入栈(带头结点)
void Push(LinkStack &S, int x) {
    LNode *node = (LNode *) malloc(sizeof(LNode));
    node->data = x;
    node->next = S->next;
    S->next = node;
}

//出栈(带头结点)
bool Pop(LinkStack &S, int &x) {
    if (S->next == NULL) 
        return false;
    LNode *temp;
    temp = S->next;
    x = temp->data;
    S->next = temp->next;
    free(temp);
    return true;
}

//读栈顶元素(带头结点)
bool GetTop(LinkStack S, int &x) {
    if (S->next == NULL)
        return false;
    x = S->next->data;
    return true;
}

int main() {
    LinkStack S;
    InitStack(S);
    LNode *temp;
    int x;
    for (int i = 0; i < 10; i++) {
        printf("%d ", i + 1);
        Push(S, i + 1);
    }
    GetTop(S, x);
    printf("\n%d\n", x);
    while (S->next) {
        Pop(S, x);
        printf("%d ", x);
    }
    // S = S->next;  //跳过头结点
    // while (S->next) {
    //     temp = S;
    //     S = S->next;
    //     printf("弹栈元素：%d ", temp->data);
    //     if (S) {
    //         printf("栈顶元素：%d\n", S->data);
    //     }
    //     else {
    //         printf("栈已空\n");
    //     }
    //     free(temp);
    // }
    // printf("栈内没有元素");
    return 0;
}