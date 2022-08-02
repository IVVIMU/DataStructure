/*
    已知一棵满二叉树(所有结点值均不同)的先序序列pre，求它的后序序列post
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

void PreToPost(ElemType *arrPre, ElemType *arrPost, int l1, int h1, int l2, int h2) {
    //l1，h1表示arrPre的的起点和末尾，l2，h2表示arrPost的起点和末尾
    int half;
    if (l1 <= h1) {
        half = (h1 - l1) / 2;
        //把arrPre的第一个元素即根节点放到arrPost的末尾
        *(arrPost + h2) = *(arrPre + l1);
        //左半部分
        PreToPost(arrPre, arrPost, l1 + 1, l1 + half, l2, l2 + half - 1);
        //右半部分
        PreToPost(arrPre, arrPost, l1 + half + 1, h1, l2 + half, h2 - 1);
    }
}

int main() {
    ElemType arrPre[] = {1, 2, 4, 5, 3, 6, 7}, arrPost[7];
    PreToPost(arrPre, arrPost, 0, 6, 0, 6);
    for (int i = 0; i < 7; i++) {
        printf("%d ", *(arrPost + i));
    }
    return 0;
}