/*
    将二叉树的叶结点按从左到右的顺序连成一个单链表，表头指针为head，二叉树按二叉链表方式存储，链接时用叶结点的右指针来存放单链表指针
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

// BiTNode *head = (BiTNode *) malloc(sizeof(BiTNode));
// BiTNode *pre = NULL;
BiTNode * LeafLink(BiTree T) {
    static BiTNode *head = (BiTNode *) malloc(sizeof(BiTNode));
    static BiTNode *pre = NULL;
    if (T) {
        LeafLink(T->lchild);
        if (T->lchild == NULL && T->rchild == NULL) {
            //不带头结点
            if (pre == NULL) {
                head = pre = T;
            }
            else {
                pre->rchild = T;
                pre = T;
            }
            //带头结点(全局变量pre = head)
            // pre->rchild = T;
            // pre = T;
        }
        LeafLink(T->rchild);
        //设置链表尾
        pre->rchild = NULL;
    }
    return head;
}

int main() {
    BiTree T;
    CreateBiTree(T);
    BiTNode *head = LeafLink(T);
    while (head) {
        visit(head);
        head = head->rchild;
    }
    return 0;
}