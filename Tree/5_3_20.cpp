/*
    将给定的表达式树（二叉树）转换成等价的中缀表达式
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType char

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

//初始化树的函数，递归方法
void CreateBiTree(BiTree &T) {
    ElemType ch;
    scanf("%c",&ch);
    //清空缓冲区
    getchar();
    if(ch == '#') {
        //递归结束，建立树
        T = NULL;  
    } else{
        //生成根节点
        T = (BiTNode *) malloc(sizeof(BiTNode));
        T->data = ch;   
        CreateBiTree(T->lchild);  //递归创建左子树
        CreateBiTree(T->rchild);  //递归创建右子树
    }
}

void putInExp(BiTree T, int depth) {
    if (!T) {
        return;
    }
    //若为叶结点，直接输出
    if (T->lchild == NULL && T->rchild == NULL) {
        printf("%c", T->data);
    }
    else {
        //非根节点。添加左括号
        if (depth > 1)
            printf("(");
        putInExp(T->lchild, depth + 1);
        printf("%c", T->data);
        putInExp(T->rchild, depth + 1);
        if (depth > 1)
            printf(")");
    }
}

int main() {
    BiTree T;
    CreateBiTree(T);
    int depth = 1;
    putInExp(T, depth);
}