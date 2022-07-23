/*
    栈的应用 —— 括号匹配
*/

#include <stdio.h>
#include <stdlib.h>

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

bool BracketsCheck(char *str) {
    SqStack S;
    InitStack(S);
    int i = 0;
    char e;
    while (str[i] != '\0') {
        switch(str[i]) {
            //左括号入栈
            case '(' : Push(S, '('); break;
            case '[' : Push(S, '['); break;
            case '{' : Push(S, '{'); break;
            //遇到右括号，检测栈顶
            case ')' : Pop(S, e);
                if (e != '(') return false;
            break;
            case ']' : Pop(S, e);
                if (e != '[') return false;
            break;
            case '}' : Pop(S, e);
                if (e != '{') return false;
            break;
            default:
            break;
        }
        i++;
    }
    if (!StackEmpty(S)) {
        printf("括号不匹配！\n");
        return false;
    }
    else {
        printf("括号匹配！\n");
        return true;
    }
}