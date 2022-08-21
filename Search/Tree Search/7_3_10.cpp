/* 
    从大到小输出二叉排序树中所有值不小于k的关键字
    算法思想：右中左遍历
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

//从大到小输出二叉排序树中所有值不小于k的关键字
void InverseOutput(BiTree T, ElemType k) {
    //空结点
    if (!T) 
        return;
    if (T->rchild) {
        InverseOutput(T->rchild, k);
    }
    if (T->data <= k) {
        printf("%d ", T->data);
    }
    if (T->lchild) {
        InverseOutput(T->lchild, k);
    }
}

int main() {
    BiTree T;
    CreateBiTree(T);
    InverseOutput(T, 6);
    return 0;
}

