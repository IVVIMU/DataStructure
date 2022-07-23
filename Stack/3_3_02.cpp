/*
    车厢调度，分别用H和S表示硬座和软座
    编写算法，使所有的软座车厢都被调整到硬座车厢之前
*/

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define MaxSize 50

typedef struct SqStack {
    char data[MaxSize];
    int top;
} SqStack;

//初始化
void InitStack(SqStack &S) {
    S.top = -1;
}

//判断栈空
bool StackEmpty(SqStack S) {
    if (S.top == -1)
        return true;
    else 
        return false;
}

//新元素入栈
bool Push(SqStack &S, char x) {
    //栈满
    if (S.top == MaxSize - 1)
        return false;
    //S.data[++S.top] = x;
    S.top = S.top + 1;
    S.data[S.top] = x;
    return true;
}

//元素出栈
bool Pop(SqStack &S, char &x) {
    //栈空
    if (S.top == -1) 
        return false;
    //x = S.data[S.top--];
    x = S.data[S.top];
    S.top = S.top - 1;
    return true;
}

void TrainDispatch(char trains[], int size) {
    SqStack S;
    InitStack(S);
    for (int i = 0; i < size; i++) {
        if (trains[i] == 'H') {
            Push(S, trains[i]);
        }
        else {
            printf("%c ", trains[i]);
        }
    }
    char e;
    while (!StackEmpty(S)) {
        Pop(S, e);
        printf("%c ", e);
    }
}

void TrainArrange(char *trains) {
    char *p = trains, *q = trains;
    char e;
    SqStack S;
    InitStack(S);
    while (*p) {
        if (*p == 'H') {
            Push(S, *p);
        }  
        else {
            *(q++) = *p;
            printf("%c ", *p);
        }  
        p++;
    }
    while (!StackEmpty(S)) {
        Pop(S, e);
        *(q++) = e;
        printf("%c ", e);
    }
}

int main() {
    char trains[] = {'H', 'S', 'S', 'H', 'H', 'S'};
    int size = ARRAY_SIZE(trains);
    //TrainDispatch(trains, size);
    TrainArrange(trains);
    return 0;
}