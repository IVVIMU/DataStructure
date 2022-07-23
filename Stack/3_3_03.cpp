/*
    用栈实现递归函数的非递归计算
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

double StackToRecursion(int n, double x) {
    struct {
        int no;      //保存n
        double val;  //保存Pn(x)值
    } st[MaxSize];
    //top为栈st的下标变量
    int top = -1, i;
    double fv1 = 1, fv2 = 2*x;
    for (i = n; i >= 2; i--) {
        top++;
        st[top].no = i;
    }
    while (top >= 0) {
        st[top].val = 2*x*fv2 - 2*(st[top].no - 1)*fv1;
        fv1 = fv2;
        fv2 = st[top].val;
        top--;
    }
    if (n == 0) 
        return fv1;
    return fv2;
}

int main() {
    double result = StackToRecursion(3, 2.0);
    printf("%f", result);
    return 0;
}