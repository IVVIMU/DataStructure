/*
    线索二叉树
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

void CreateInThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T != NULL) {
        //中序线索二叉树
        InThread(T, pre);

        //先序线索二叉树
        //PreThread(T, pre);

        //后序线索二叉树
        // PostThread(T, pre);

        //处理遍历的最后一个结点
        if (pre->rchild == NULL) {
            pre->rtag = 1;
        }
        //等价于上面，但上面更健壮
        // pre->rchild = NULL;
        // pre->rtag = 1;
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

void PreThread(ThreadTree &p, ThreadTree &pre) {
    if (p != NULL) {
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
        //lchild不是前去线索
        if (p->ltag == 0) 
            PreThread(p->lchild, pre);
        PreThread(p->rchild, pre);
    }
}

void PostThread(ThreadTree &p, ThreadTree &pre) {
    if (p != NULL) {
        PostThread(p->lchild, pre);
        PostThread(p->rchild, pre);
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
    }
}

//在中序线索二叉树找中序后继
//找到以p为根的子树中，第一个被中序遍历的结点（右子树的最左下结点）
ThreadNode * FirstNode(ThreadNode *p) {
    //循环找到最左下角结点（不一定是叶结点）
    while (p->ltag == 0) {
        p = p->lchild;
    }
    return p;
}

//在中序线索二叉树中找到结点p的后继结点
ThreadNode * NextNode(ThreadNode *p) {
    //右子树没有线索化，则找到右子树最左下结点
    if (p->rtag == 0)
        return FirstNode(p->rchild);
    else 
        return p->rchild;
}

//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
void InOrder(ThreadTree T) {
    for (ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p)) {
        //visit(p);
    }
}

//在中序线索二叉树中找中序前驱
//找到以p为根的子树中，最后一个被中序遍历的结点（左子树的最右下结点）
ThreadNode * LastNode(ThreadNode *p) {
    //循环找到最右下结点（不一定是叶子结点）
    while (p->rtag == 0) {
        p = p->rchild;
    }
    return p;
}

//在中序线索二叉树中找到结点p的前驱节点
ThreadNode * PreNode(ThreadNode *p) {
    //左子树没有线索化，则找到左子树中最右下结点
    if (p->ltag == 0)
        return LastNode(p->lchild);
    else
        return p->lchild;
}

//对中序线索二叉树进行逆向中序遍历
void RevInOrder(ThreadTree T) {
    for (ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p)) {
        // visit(p);
    }
}




