/*
    二叉查找树链式存储表示
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int 

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//二叉排序树插入结点
bool BST_insert(BiTree &T, ElemType val) {
    if (T == NULL) {
        T = (BiTree) malloc(sizeof(BiTNode));
        T->data = val;
        T->lchild = T->rchild = NULL;
        return true;
    }
    else if (T->data > val) return BST_insert(T->lchild, val);
    else if (T->data < val) return BST_insert(T->rchild, val);
    else return false;
}

//建立二叉排序树
void BST_create(BiTree &T, int* arr, int n) {
    T = NULL;
    int i = 0;
    while (i < n) {
        BST_insert(T, arr[i]);
        i++;
    }
}

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

int main() {
    BiTree T;
    int arr[] = {1,2,3,4,5,6,7};
    int len = sizeof(arr) / sizeof(int);
    BST_create(T, arr, len);
    PreOrderTraverse(T);
    return 0;
}