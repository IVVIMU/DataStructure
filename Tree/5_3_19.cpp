/*
    计算二叉树的带权路径长度（WPL）
    WPL是二叉树中所有叶结点的带权路径长度之和
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct BiTNode{
    ElemType weight;
    struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

//初始化树的函数，递归方法
void CreateBiTree(BiTree &T) {
    ElemType ch;
    scanf("%d",&ch);
    if(ch == 0) {
        //递归结束，建立树
        T = NULL;  
    } else{
        //生成根节点
        T = (BiTNode *) malloc(sizeof(BiTNode));
        T->weight = ch;   
        CreateBiTree(T->lchild);  //递归创建左子树
        CreateBiTree(T->rchild);  //递归创建右子树
    }
}

int CountWPL(BiTree T, int depth) {
    static int WPL = 0;
    if (T) {
        //叶结点
        if (!T->lchild && !T->rchild) {
            WPL += T->weight * depth;
        }
        else {
            CountWPL(T->lchild, depth + 1);
            CountWPL(T->rchild, depth + 1);
        }
    }
    return WPL;
}

int main() {
    BiTree T;
    CreateBiTree(T);
    int depth = 0;
    int WPL = CountWPL(T, depth);
    printf("带权路径长度为%d", WPL);
}