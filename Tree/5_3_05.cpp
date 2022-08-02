/*
    非递归算法求二叉树的高度
    算发思想：采用层序遍历的非递归算法求二叉树的高度
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

int Depth(BiTree T) {
    LinkQueue Q;
    InitQueue(Q);
    BiTNode *p;
    int depth = 0;
    //记录一层有多少个结点
    int oldNum = 0, curNum = 0;
    EnQueue(Q, T);
    //此时队列中只有一个结点
    oldNum++;
    while (!QueueEmpty(Q)) {
        p = DeQueue(Q);
        if (p->lchild) {
            //下一层结点数+1
            curNum++;
            EnQueue(Q, p->lchild);
        }
        if (p->rchild) {
            //下一层结点数+1
            curNum++;
            EnQueue(Q, p->rchild);
        }
        //如果一层元素取完，高度+1    
        if (!(--oldNum)) {
            depth++;
            //当oldNum=0时，将下一层的结点数赋给它
            oldNum = curNum;
            //下一层结点归零
            curNum = 0;
        }
    }
    return depth;
}

int main() {
    BiTree T;
    //1 2 4 0 0 5 0 0 3 6 0 0 7 0 0
    CreateBiTree(T);
    int depth = Depth(T);
    printf("二叉树的高度为：%d", depth);
    return 0;
}