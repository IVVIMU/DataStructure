/*
    计算一棵二叉树的所有双分支结点个数
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int 

//二叉链表
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//先序遍历递归建立二叉链表
void CreateBiTree(BiTree &T) {
    ElemType ch;
    scanf("%d",&ch);
    if(ch == 0) {
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

int DoubleNode(BiTree T) {
    if (T == NULL)
        return 0;
    else if (T->lchild && T->rchild)
        return DoubleNode(T->lchild) + DoubleNode(T->rchild) + 1;
    else 
        return DoubleNode(T->lchild) + DoubleNode(T->rchild);
}

int DoubleNode_2(BiTree T) {
    static int count = 0;
    if (T == NULL)
        count = 0;
    else if (T->lchild && T->rchild) {
        count++;
        DoubleNode_2(T->lchild);
        DoubleNode_2(T->rchild);
    }
    else {
        if (T->lchild)
            DoubleNode_2(T->lchild);
        if (T->rchild)
            DoubleNode_2(T->rchild);
    }
    return count;
}

int main() {
    BiTree T;
    CreateBiTree(T);
    printf("二叉树中双分支结点个数为：%d", DoubleNode(T));
}