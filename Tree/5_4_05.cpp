/*
    以孩子兄弟链表为存储结构，设计递归算法求树的深度
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

int Depth(CSTree T) {
    int ldepth, rdepth;
    if (!T)
        return 0;
    else {
        ldepth = Depth(T->firstchild);   //记录左子树的高度
        rdepth = Depth(T->nextsibling);  //记录右兄弟的高度，这里不能加1
        if (ldepth + 1 > rdepth) {
            return ldepth + 1;
        }
        else {
            return rdepth;
        }
    }
}

int main() {
    CSTree T;
    CreateCSTree(T);
    printf("深度为：%d", Depth(T));
    return 0;
}