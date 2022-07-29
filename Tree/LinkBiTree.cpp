/*
    二叉树链式存储表示
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int 

//二叉链表
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//三叉链表
typedef struct TriTNode {
    ElemType data;
    struct TriTNode *lchild, *rchild;
    struct TriTNode *parent;
} TriTNode, *TriTree;

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

//复制二叉树
void Copy(BiTree T, BiTree &NewT) {
    if (T == NULL) {
        NewT = NULL;
        return;
    }
    else {
        NewT = (BiTNode *) malloc(sizeof(BiTNode));
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);  //递归复制左子树  
        Copy(T->rchild, NewT->rchild);  //递归复制右子树
    }
}

//计算二叉树深度
int Depth(BiTree T) {
    int m = 0, n = 0;
    if (T == NULL) 
        return 0;
    else {
        m = Depth(T->lchild);
        n = Depth(T->rchild);
        return (m > n ? m : n) + 1;
    }
}

//统计二叉树中结点的个数
int NodeCount(BiTree T) {
    if (T == NULL)
        return 0;
    else {
        //左子树的结点个数+右子树的结点个数 + 1
        return NodeCount(T->lchild) + NodeCount(T->lchild) + 1;
    }
}

//二叉树左右子树互换
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

//删除二叉树中所有以值为x的结点为根的子树并释放空间
void DelSubTree(BiTree &T) {
    if (T) {
        DelSubTree(T->lchild);
        DelSubTree(T->rchild);
        free(T);
    }
}

void DelTree(BiTree &T, ElemType x) {
    if (T) {
        if (T->data == x) {
            DelSubTree(T);
            T = NULL;
        }
        else {
            DelTree(T->lchild, x);
            DelTree(T->rchild, x);
        }
    }
}

int main() {
    BiTree T;
    CreateBiTree(T);
    return 0;
}