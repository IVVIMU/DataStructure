/* 
    判断二叉树是否是平衡二叉树
    算法思想：采用后序的递归遍历，在每一层判断平衡因子的绝对值是否大于1
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

bool IsBBT(BiTree T, int &depth) {
    //空结点，为平衡二叉树
    if (!T) {
        depth = 0;
        return true;
    }
    //判断左右子树是否为平衡二叉树
    int left = 0, right = 0;
    if (IsBBT(T->lchild, left) && IsBBT(T->rchild, right)) {
        int balance = abs(left - right);
        if (balance <= 1) {
            depth = (1 + (left > right ? left : right));
            return true;
        }
    }
    return false;
}

int main() {
    BiTree T;
    CreateBiTree(T);
    int depth = 0;
    if (IsBBT(T, depth))
        printf("是一棵平衡二叉树！");
    else
        printf("不是一棵平衡二叉树！");
    return 0;
}

/* 
3 2 1 0 0 0 6 4 0 0 7 0 9 0 10 0 0
不是一棵平衡二叉树！
*/

