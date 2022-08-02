/*
    交换左右子树
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

void Exchange(BiTree &T) {
    BiTNode *temp;
    if (T) {
        temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
        Exchange(T->lchild);
        Exchange(T->rchild);
    }
}

int main() {
    BiTree T;
    CreateBiTree(T);
    printf("原二叉树先序遍历: ");
    PreOrderTraverse(T);
    Exchange(T);
    printf("\n交换左右子树的二叉树先序遍历: ");
    PreOrderTraverse(T);
    return 0;
}