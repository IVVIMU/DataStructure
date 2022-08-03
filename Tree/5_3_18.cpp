/*
    在中序线索二叉树里查找指定结点在后序的前驱结点的算法
    算法思想：1、如果结点有右孩子，前驱就是右孩子
             2、如果有左孩子，没有右孩子，前驱就是左孩子
             3、如果没有孩子结点，如果左线索结点有左孩子p，那么p结点就是前驱；
                如果左线索结点没有左孩子，继续向上寻找左线索，直至有某个祖先节点有左孩子q，
                那么q就是前驱
             4、在第三种情况下寻找左线索为NULL时，没有前驱
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int 

typedef struct ThreadNode {
    ElemType data;
    //左、右孩子指针
    struct ThreadNode *lchild, *rchild;
    //左、右线索标志
    //tag == 0，表示指针指向孩子
    //tag == 1，表示指针是“线索”
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void CreateThread(ThreadTree &T) {
    ElemType ch;
    scanf("%d",&ch);
    if (ch == 0) {
        //递归结束，建立树
        T = NULL;
    } else {
        //生成根节点
        T = (ThreadNode *) malloc(sizeof(ThreadNode));
        T->data = ch;
        CreateThread(T->lchild);
        CreateThread(T->rchild);
    }
}

void InThread(ThreadTree &p, ThreadTree &pre) {
    if (p != NULL) {
        //递归，线索化左子树
        InThread(p->lchild, pre);
        //左子树为空，建立前驱节点
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        //建立前驱节点的后继结点
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        //递归，线索化右子树
        InThread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T != NULL) {
        //中序线索二叉树
        InThread(T, pre);

        //处理遍历的最后一个结点
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
        //等价于上面，但上面更健壮
        // pre->rchild = NULL;
        // pre->rtag = 1;
    }
}

ThreadNode * FindPre(ThreadTree T, ThreadNode * p) {
    ThreadNode *cur;
    //如果该结点有右孩子，那么前驱就是右孩子
    if (p->rchild && p->rtag == 0) {
        return p->rchild;
    }
    //没有右孩子只有左孩子，前驱就是左孩子
    else if (p->lchild && p->ltag == 0) {
        return p->lchild;
    }
    //执行到这步骤的一定是叶子节点
    else {
        //左线索指向某个祖先结点
        cur = p->lchild;
        //如果该祖先结点存在且没有左孩子——ltag == 1，继续向上找
        while (cur && cur->ltag == 1) {
            cur = cur->lchild;
        }
        if (cur && cur->ltag == 0) {
            return cur->lchild;
        }
        else {
            return NULL;
        }
    }
}

int main() {
    ThreadTree T;
    CreateThread(T);
    CreateInThread(T);
    ThreadNode *p = T->lchild->lchild;
    ThreadNode *node = FindPre(T, p);
    if (node)
        printf("%d", node->data);
    else
        printf("结点%d在后序遍历中没有前驱节点", p->data);
    return 0;
}