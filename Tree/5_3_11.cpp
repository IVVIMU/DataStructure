/*
    删除树中以结点值x为根的子树，并释放相应空间
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

//链式队列头结点
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

int NodeCount(LinkQueue Q) {
    int count = 0;
    LinkBiTNode *cur = Q.front->next;
    while (cur) {
        count++;
        cur = cur->next;
    }
    return count;
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

//先序遍历
void PreOrderTraverse(BiTree T) {
    if (T) {
        printf("%d ", T->data);
        PreOrderTraverse(T->lchild);//访问该结点的左孩子
        PreOrderTraverse(T->rchild);//访问该结点的右孩子
    }
    //如果结点为空，返回上一层
    return;
}

//删除以x为结点值的子树
void DeleteX(BiTree &T) {
    if (T) {
        DeleteX(T->lchild);
        DeleteX(T->rchild);
        free(T);
    }
}

//在二叉树中查找所有以x为结点值的结点，并删除以其为根的子树
void SearchX(BiTree &T, ElemType x) {
    LinkQueue Q;
    InitQueue(Q);
    BiTNode *node;
    if (T) {
        if (T->data == x) {
            DeleteX(T);
            exit(0);
        }
        EnQueue(Q, T);
        while (!QueueEmpty(Q)) {
            node = DeQueue(Q);
            if (node->lchild) {
                if (node->lchild->data == x) {
                    DeleteX(node->lchild);
                    node->lchild = NULL;
                }
                else {
                    EnQueue(Q, node->lchild);
                }
            }
            if (node->rchild) {
                if (node->rchild->data == x) {
                    DeleteX(node->rchild);
                    node->rchild = NULL;
                }
                else {
                    EnQueue(Q, node->rchild);
                }
            }
        }
    }
}

void DeleteXSub(BiTree &T, int x) {
    if (T->lchild && T->lchild->data == x) {
        DeleteX(T->lchild);
        T->lchild = NULL;
    }
    if (T->rchild && T->rchild->data == x) {
        DeleteX(T->rchild);
        T->rchild = NULL;
    }
    if (T->lchild)
        DeleteXSub(T->lchild, x);
    if (T->rchild)
        DeleteXSub(T->rchild, x);
}

int main() {
    BiTree T;
    CreateBiTree(T);
    printf("原二叉树先序遍历: ");
    PreOrderTraverse(T);
    //SearchX(T, 3);
    DeleteXSub(T, 3);
    printf("\n删除以x值为结点的二叉树先序遍历: ");
    PreOrderTraverse(T);
    return 0;
}