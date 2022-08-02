#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ElemType int

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

//初始化树的函数，递归方法
void CreateBiTree(BiTree &T) {
    ElemType ch;
    //1 2 4 0 0 5 6 0 0 7 0 0 3 0 0
    scanf("%d", &ch);
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

//先序遍历
void PreOrderTraverse(BiTree T) {
    if (T) {
        visit(T);
        PreOrderTraverse(T->lchild);  //访问该结点的左孩子
        PreOrderTraverse(T->rchild);  //访问该结点的右孩子
    }
    //如果结点为空，返回上一层
    return;
}

//中序遍历
void InOrderTraverse(BiTree T) {
    if(T) {
        InOrderTraverse(T->lchild);
        visit(T);
        InOrderTraverse(T->rchild);
    }
    //如果结点为空，返回上一层
    return;
}

//后序遍历
void PostOrderTraverse(BiTree T) {
    if(T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        visit(T);
    }
    //如果结点为空，返回上一层
    return;
}

int main() {
    BiTree T;
    CreateBiTree(T);

    printf("先序遍历: ");
    PreOrderTraverse(T);

    printf("\n中序遍历: ");
    InOrderTraverse(T);

    printf("\n后序遍历: ");
    PostOrderTraverse(T);

    return 0;
}
