/*
    二叉树的从下而上、从右到左的的层次遍历算法
    算法思想：利用原有的层次遍历算法，出队的同时将各结点指针入栈，在所有结点入栈后再从栈顶开始依次访问
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

//链栈
typedef struct LNode {
    BiTNode *data;
    struct LNode *next;
} LNode, *LinkStack;

//初始化(带头结点)
bool InitStack(LinkStack &S) {
    S = (LNode *) malloc(sizeof(LNode));
    //内存不足，分配失败
    if (S == NULL)
        return false;
    S->next = NULL;
    return true;
} 

//判断栈是否为空(带头结点)
bool StackEmpty(LinkStack S) {
    if (S->next == NULL)
        return true;
    else 
        return false;
}

//入栈(带头结点)
void Push(LinkStack &S, BiTNode *x) {
    LNode *node = (LNode *) malloc(sizeof(LNode));
    node->data = x;
    node->next = S->next;
    S->next = node;
}

//出栈(带头结点)
BiTNode * Pop(LinkStack &S) {
    if (S->next == NULL) 
        return NULL;
    LNode *temp;
    temp = S->next;
    S->next = temp->next;
    BiTNode *tnode = temp->data;
    free(temp);
    return tnode;
}

BiTNode * GetTop(LinkStack S) {
    return S->next->data;
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

void visit(BiTNode *p) {
    printf("%d ", p->data);
}

void InvertLevel(BiTree T) {
    LinkStack S;
    InitStack(S);
    LinkQueue Q;
    InitQueue(Q);
    BiTNode *node;
    if (T) {
        EnQueue(Q, T);
        while (!QueueEmpty(Q)) {
            //出队入栈
            node = DeQueue(Q);
            Push(S, node);
            if (node->lchild)
                EnQueue(Q, node->lchild);
            if (node->rchild)
                EnQueue(Q, node->rchild);
        }
        while (!StackEmpty(S)) {
            node = Pop(S);
            visit(node);
        }
    }
}

int main() {
    BiTree T;
    CreateBiTree(T);
    printf("逆向层序遍历: ");
    InvertLevel(T);
    return 0;
}