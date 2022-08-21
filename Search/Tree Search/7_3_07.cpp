/* 
    求出指定结点在给定的二叉排序树中的层次
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

int level(BiTree T, ElemType x) {
    int n = 0;
    if (T) {
        n++;
        while (T->data != x) {
            //在左子树中查找
            if (x < T->data) {
                T = T->lchild;
            }
            else {
                T = T->rchild;
            }
            n++;
        }
    }
    return n;
}

int main() {
    BiTree T;
    CreateBiTree(T);
    printf("值为%d的结点在二叉树中的层次为%d", 4, level(T, 4));
    return 0;
}