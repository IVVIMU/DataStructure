/*
    求以孩子兄弟表示法存储的森林的叶子结点数
    算法思想：遍历过程中发现结点有左孩子的就不是叶子结点
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int

//孩子兄弟表示法
typedef struct CSNode {
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;

//初始化树的函数，递归方法
void CreateCSTree(CSTree &T) {
    ElemType ch;
    scanf("%d",&ch);
    //清空缓冲区，输入int型字符时不需要
    // getchar();
    if(ch == 0) {
        //递归结束，建立树
        T = NULL;  
    } else{
        //生成根节点
        T = (CSNode *) malloc(sizeof(CSNode));
        T->data = ch;   
        CreateCSTree(T->firstchild);  //递归创建左子树
        CreateCSTree(T->nextsibling);  //递归创建右子树
    }
}

int LeafCount(CSTree T) {
    if (!T)
        return 0;
    else
        //如果没有左孩子，该结点一定是叶子节点
        if (!T->firstchild) 
            return 1 + LeafCount(T->nextsibling);
        else 
            return LeafCount(T->firstchild) + LeafCount(T->nextsibling);
}

int main() {
    CSTree T;
    CreateCSTree(T);
    printf("该森林的叶子结点个数为：%d", LeafCount(T));
    return 0;
}