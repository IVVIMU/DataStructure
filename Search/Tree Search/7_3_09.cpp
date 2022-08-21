/* 
    找出给定二叉排序树中最小和最大的关键字
    算法思想：由于是在二叉排序树中，所以最小的元素一定在二叉树的最左下角，最大的元素一定在二叉树的最右下角
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

ElemType MinKey(BiTree T) {
    while (T->lchild) {
        T = T->lchild;
    }
    return T->data;
}

ElemType MaxKey(BiTree T) {
    while (T->rchild) {
        T = T->rchild;
    }
    return T->data;
}

int main() {
    BiTree T;
    CreateBiTree(T);
    printf("二叉树中最小的关键字为%d\n", MinKey(T));
    printf("二叉树中最大的关键字为%d\n", MaxKey(T));
}