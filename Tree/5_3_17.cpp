/*
    判断两棵二叉树是否相似
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

//初始化树的函数，递归方法
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

//模拟操作结点元素的函数，输出结点本身的数值
void visit(BiTNode *node){
    printf("%d ",node->data);
}

bool IsSimilar(BiTree T1, BiTree T2) {
    //T1、T2均为空
    if (!T1 && !T2) {
        return true;
    }
    //T1、T2只有一棵为空
    else if (!T1 || !T2) {
        return false;
    }
    else {
        if (IsSimilar(T1->lchild, T2->lchild) && IsSimilar(T1->rchild, T2->rchild)) {
            return true;
        }
        else {
            return false;
        }
    }
}

int main() {
    BiTree T1, T2;
    CreateBiTree(T1);
    CreateBiTree(T2);
    if (IsSimilar(T1, T2)) 
        printf("两棵二叉树相似！");
    else 
        printf("两棵二叉树不相似！");
    return 0;
}