/*
    非空二叉树的宽度
    算发思想：采用层序遍历
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
void visit(BiTNode *node){
    printf("%d ",node->data);
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

int Width(BiTree T) {
    LinkQueue Q;
    InitQueue(Q);
    BiTNode *p;
    int width = 1;
    //记录一层有多少个结点
    int oldNum = 0, curNum = 0;
    EnQueue(Q, T);
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
        curNum > width ? width = curNum : NULL;
        if (!(--oldNum)) {
            //当oldNum=0时，将下一层的结点数赋给它
            oldNum = curNum;
            //下一层结点归零
            curNum = 0;
        }        
    }
    return width;
}

int main() {
    BiTree T;
    CreateBiTree(T);
    printf("二叉树的宽度为%d", Width(T));
    return 0;
}