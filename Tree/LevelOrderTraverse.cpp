#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ElemType int

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

//初始化树的函数，递归方法
void CreateBiTree(BiTree &T) {
    ElemType ch;
    //1 2 4 0 0 5 6 0 0 7 0 0 3 0 0
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
void displayElem(BiTNode* elem){
    printf("%d ",elem->data);
}

#define MaxSize 100

// typedef struct SqQueue {
//     struct BiTNode* numQ[MaxSize];
//     int front, rear;
// } SqQueue;

// void InitQueue(SqQueue &Q) {
//     Q.front = 0;
//     Q.rear = 0;
// }

// void EnQueue(SqQueue &Q, BiTNode *node) {
//     Q.numQ[++Q.rear] = node;
// }

// BiTNode * DeQueue(SqQueue &Q) {
//     return Q.numQ[++Q.front];
// }

// bool QueueEmpty(SqQueue Q) {
//     if (Q.rear == Q.front)
//         return true;
//     else
//         return false;
// }

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
    return temp->node;
}

void LevelOrderTraverse(BiTree T) {
    //SqQueue Q;
    LinkQueue Q;
    InitQueue(Q);
    BiTNode *p;
    EnQueue(Q, T);
    while (!QueueEmpty(Q)) {
        p = DeQueue(Q);
        displayElem(p);
        if (p->lchild != NULL) 
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}

int main() {
    BiTree T;
    CreateBiTree(T);

    printf("层序遍历: ");
    LevelOrderTraverse(T);
    return 0;
}