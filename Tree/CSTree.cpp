/*
    孩子兄弟表示法
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int

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