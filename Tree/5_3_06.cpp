/*
    通过先序序列和中序序列构建一棵二叉树
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int 

//二叉链表
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree PreInCreat(ElemType *A, ElemType *B, int l1, int h1, int l2, int h2) {
    //l1，h1为先序的第一和最后一个结点下标，l2，h2为中序的第一个最后一个结点下标
    //左子树、右子树的长度
    int llen, rlen;
    int i;
    BiTNode *root = (BiTNode *) malloc(sizeof(BiTNode));
    root->data = *(A + l1);
    //找到根结点在中序序列的中的位置
    for (i = l2; *(B + i) != root->data; i++);
    //记录左子树长度
    llen = i - l2;
    //记录右子树长度
    rlen = h2 - i;
    if (llen)
        root->lchild = PreInCreat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
    else
        root->lchild = NULL;
    if (rlen)
        root->rchild = PreInCreat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
    else
        root->rchild = NULL;
    return root;
}

//先序遍历
void PreOrderTraverse(BiTree T) {
    if (T) {
        printf("%d ", T->data);
        PreOrderTraverse(T->lchild);//访问该结点的左孩子
        PreOrderTraverse(T->rchild);//访问该结点的右孩子
    }
    //如果结点为空，返回上一层
    return;
}

int main() {
    //先序序列
    int A[] = {1, 2, 4, 5, 3, 6, 7};
    //中序序列
    int B[] = {4, 2, 5, 1, 6, 3, 7};
    BiTree T = PreInCreat(A, B, 0, 6, 0, 6);
    PreOrderTraverse(T);
    return 0;
}