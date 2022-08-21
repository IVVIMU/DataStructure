/* 
    编写一个递归算法，在一棵有n个结点的、随机建立起来的二叉排序树中查找第k小的元素，并返回指向该结点的指针。
    二叉排序树中每个结点中除data，lchild，rchild等数据成员外，增加一个count成员，保存以该结点为根的子树上的节点个数

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ElemType int

//二叉链表
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
    int count;  //保存以该结点为根的子树上的节点个数
} BiTNode, *BiTree;

//先序遍历递归建立二叉链表
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

//统计每个节点的以它为根结点的子树的结点数
int getCount(BiTree T) {
    //空结点
    if (!T) {
        return 0;
    }
    int lcount, rcount;
    lcount = getCount(T->lchild);
    rcount = getCount(T->rchild);
    T->count = lcount + rcount + 1;  //包括该结点
    return lcount + rcount + 1;
}

//查找第k小的元素
/* 
T->lchild为空时
    T->lchild非空且k == 1，T即为第k小的元素 
    T->lchild非空且k != 1，第k小的元素必在T的右子树中
T->lchild非空时
    T->lchild->count == k - 1， T即为第k小的元素
    T->lchild->count > k - 1，第k小的元素必在T的左子树
    T->lchild->count < k - 1，第k小的元素必在T的右子树
*/
BiTNode * FindKthMin(BiTree T, int k) {
    if (k < 1 || k > T->count)
        return NULL;
    //左子树为空
    if (!T->lchild) {
        if (k == 1)
            return T;
        else
            return FindKthMin(T->rchild, k - 1);
    }
    else {
        if (T->lchild->count == k - 1) return T;
        if (T->lchild->count > k - 1) return FindKthMin(T->lchild, k);
        if (T->lchild->count < k - 1) return FindKthMin(T->rchild, k - (T->lchild->count + 1));
    }
}

int main() {
    BiTree T;
    CreateBiTree(T);
    getCount(T);
    int k = 5;
    BiTNode *p = FindKthMin(T, k);
    printf("第%d小的元素为%d", k, p->data);
    return 0;
}

/* 
3 2 1 0 0 0 6 4 0 0 7 0 0 
第5小的元素为6
*/