/*
    I和O分别表示入栈和出栈的操作，判断序列是否合法
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef struct LNode {
    char data;
    struct LNode *next;
} LNode, *LinkStack;

bool InitList(LinkStack &S) {
    S = (LNode *) malloc(sizeof(LNode));
    //内存不足，分配失败
    if (S == NULL)
        return false;
    S->next = NULL;
    return true;
}

//入栈
void Push(LinkStack &S, char x) {
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
bool Pop(LinkStack &S, char &x) {
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
bool GetTop(LinkStack S, char &x) {
    if (S == NULL)
        return false;
    x = S->data;
    return true;
}

void CreateStack(LinkStack &S, char data[], int size) {
    for (int i = 0; i < size; i++) {
        Push(S, data[i]);
    }
}

void printStack(LinkStack S) {
    while (S->next != NULL) {
        printf("%c ", S->data);
        S = S->next;
    }    
}

bool isLegal(char sequence[], int size) {
    int I = 0, O = 0;
    for (int i = 0; i < size; i++) {
        if (sequence[i] == 'I') 
            I++;
        else
            O++;
        if (O > I) 
            return false;
        i++;
    }
    if (I == O)
        return true;
    else
        return false;
}

int main() {
    char sequence1[] = {'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O'};
    char sequence2[] = {'I', 'O', 'O', 'I', 'O', 'I', 'I', 'O'};
    int size = 8;
    if (isLegal(sequence2, size))
        printf("合法序列");
    else  
        printf("非法序列");
    return 0;
}