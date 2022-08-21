/* 
    判断二叉树是否为二叉排序树
    算法思想：对二叉树进行中序遍历，若始终保持前一个值比后一个值小，则说明该二叉树是一棵二叉排序树
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

bool IsBST(BiTree T) {
    static int min = INT_MIN;
    static bool flag = true;
    if (T) {
        IsBST(T->lchild);
        if (T->data < min)
            flag = false;
        else
            min = T->data;
        IsBST(T->rchild);
    }
    return flag;
}

int main() {
    BiTree T;
    CreateBiTree(T);
    if (IsBST(T))
        printf("是一棵二叉排序树！");
    else 
        printf("不是一棵二叉排序树！");
    return 0;
}

/* 
3 2 1 0 0 0 6 4 0 0 7 0 0
是一棵二叉排序树！
*/
