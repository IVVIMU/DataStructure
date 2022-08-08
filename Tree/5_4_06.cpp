/*
    已知一棵树的的层次序列和每个结点的度，构造此树的孩子-兄弟链表
    算法思想：
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int

//孩子兄弟表示法
typedef struct CSNode {
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;

void CreateCSTree_Degree(int *level, int *degree, CSNode **pointer, int n) {  //n为结点个数
    //判断到了哪个结点
    int k = 0;
    //初始化pointer
    for (int i = 0; i < n; i++) {
        pointer[i]->data = level[i];
        pointer[i]->firstchild = NULL;
        pointer[i]->nextsibling = NULL;
    }

    for (int i = 0; i < n; i++) {
        int d = degree[i];
        //如果度不为0
        if (d) {
            k++;  //k为子女结点序号
            //第一个结点为当前结点的左孩子
            pointer[i]->firstchild = pointer[k];
            //剩下的d - 1各节点为当前结点的兄弟结点
            for (int j = 0; j < d - 1; j++) {
                k++;
                pointer[k - 1]->nextsibling = pointer[k];
            }
        }
    }
}

//模拟操作结点元素的函数，输出结点本身的数值
void visit(CSNode *node){
    printf("%d ",node->data);
}

//先序遍历
void PreOrderTraverse(CSTree T) {
    if (T) {
        visit(T);
        PreOrderTraverse(T->firstchild);  //访问该结点的左孩子
        PreOrderTraverse(T->nextsibling);  //访问该结点的右孩子
    }
    //如果结点为空，返回上一层
    return;
}

void inOrderTraverse(CSTree T) {
    if (T) {
        inOrderTraverse(T->firstchild);
        visit(T);
        inOrderTraverse(T->nextsibling);
    }
    return;
}

int main() {
    //层次遍历序列
    int level[6] = {1, 2, 3, 4, 5, 6};
    int degree[] = {3, 2, 0, 0, 0, 0};
    //分配二维数组空间
    CSNode* *pointer = (CSNode* *) malloc(sizeof(CSNode*) * 6);
    //构造二维数组
    for (int i = 0; i < 6; i++) {
        pointer[i] = (CSNode*) malloc(sizeof(CSNode*));
    }
    CreateCSTree_Degree(level, degree, pointer, 6);
    PreOrderTraverse(pointer[0]);
    printf("\n");
    inOrderTraverse(pointer[0]);
    return 0;
}