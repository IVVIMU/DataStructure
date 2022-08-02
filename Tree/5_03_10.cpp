/*
    求先序遍历序列中第k个节点的值
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
void PreOrderTraverse(BiTree T, int k) {
    static int count = 0;
    if (T) {
        if (++count == k)
            printf("%d ", T->data);
        PreOrderTraverse(T->lchild, 3);//访问该结点的左孩子
        PreOrderTraverse(T->rchild, 3);//访问该结点的右孩子
    }
    //如果结点为空，返回上一层
    return;
}

int main() {
    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T, 3);
    return 0;
}