/*
    判定一棵二叉树是否是完全二叉树
    算发思想：采用层次遍历，将所有结点加入队列（包括空结点）
    若遇到空结点，查看其后是否有空结点，若有，则二叉树不是完全二叉树
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int 

//二叉链表
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
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

//链式队列结点
typedef struct LinkBiTNode {
    BiTNode *node;
    struct LinkBiTNode *next;
} LinkBiTNode;

typedef struct LinkQueue {
    LinkBiTNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q) {
    //初始时 front、rear 都指向头结点
    Q.front = Q.rear = (LinkBiTNode *) malloc(sizeof(LinkBiTNode));
    Q.front->next = NULL;
}

bool QueueEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

void EnQueue(LinkQueue &Q, BiTNode *p) {
    LinkBiTNode *s = (LinkBiTNode *) malloc(sizeof(LinkBiTNode));
    s->node = p;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}   

BiTNode * DeQueue(LinkQueue &Q) {
    if (Q.front == Q.rear)
        return NULL;
    LinkBiTNode *temp = Q.front->next;
    Q.front->next = temp->next;
    //如果是最后一个结点出队
    if (Q.rear == temp)
        Q.rear = Q.front;
    BiTNode *tnode = temp->node;
    free(temp);
    return tnode;
}

bool IsComplete(BiTree T) {
    LinkQueue Q;
    InitQueue(Q);
    //空树为满二叉树
    if (!T)
        return true;
    EnQueue(Q, T);
    BiTNode *node;
    while (!QueueEmpty(Q)) {
        node = DeQueue(Q);
        //结点非空，左右子树入队
        if (node) {
            EnQueue(Q, node->lchild);
            EnQueue(Q, node->rchild);
        }
        else {
            while (!QueueEmpty(Q)) {
                node = DeQueue(Q);
                //空结点后面有非空结点，则该树不是完全二叉树
                if (node)
                    return false;
            }
        }
    }
    return true;
}

int main() {
    BiTree T;
    CreateBiTree(T);
    if (IsComplete(T))
        printf("该树是完全二叉树！");
    else
        printf("该树不是完全二叉树！");
    return 0;
}