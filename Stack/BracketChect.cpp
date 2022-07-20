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

bool bracketCheck(char str[], int length) {
    SqStack S;
    InitStack(S);
    for (int i; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);
        }
        else {
            //扫描到右括号且当前栈空，则匹配失败
            if (StackEmpty(S))
                return false;
            char topElem;
            Pop(S, topElem);
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    //检索完全部括号后，栈空说明匹配成功
    return StackEmpty(S);
}