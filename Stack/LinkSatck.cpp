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

bool InitStack(LinkStack &S) {
    S = (LNode *) malloc(sizeof(LNode));
    //内存不足，分配失败
    if (S == NULL)
        return false;
    S->next = NULL;
    return true;
} 

//判断栈是否为空
bool StackEmpty(LinkStack S) {
    if (S->next == NULL)
        return true;
    else 
        return false;
}

//入栈
void Push(LinkStack &S, int x) {
    LNode *node = (LNode *) malloc(sizeof(LNode));
    node->data = x;
    if (S == NULL) {
        S  = node;
    }
    else {
        node->next = S;
        S = node;
    }
}

//出栈
bool Pop(LinkStack &S, int &x) {
    if (S == NULL) 
        return false;
    LNode *temp;
    temp = S;
    x = temp->data;
    S = temp->next;
    free(temp);
    return true;
}

//读栈顶元素
bool GetTop(LinkStack S, int &x) {
    if (S == NULL)
        return false;
    x = S->data;
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
    printf("\n");
    // while (S->next) {
    //     Pop(S, x);
    //     printf("%d ", x);
    // }
    while (S->next != NULL) {
        temp = S;
        S = S->next;
        printf("弹栈元素：%d ", temp->data);
        if (S->next != NULL) {
            printf("栈顶元素：%d\n", S->data);
        }
        else {
            printf("栈已空\n");
        }
        free(temp);
    }
    printf("栈内没有元素");
    return 0;
}