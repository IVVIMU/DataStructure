/*
    后序遍历的非递归算法
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

void visit(BiTNode *p) {
    printf("%d ", p->data);
}

void PostOrderTraverse(BiTree T) {
    LinkStack S;
    InitStack(S);
    BiTNode *p = T;
    BiTNode *r = NULL;
    while (p || !StackEmpty(S)) {
        //走到最左边
        if (p) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            p = GetTop(S);
            //若右子树存在且未被访问过
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
            }
            else {
                p = Pop(S);
                visit(p);
                //记录最近访问过的结点
                r = p;
                //结点访问完后重置p指针
                p = NULL;
            }
        }
    }
}

int main() {
    BiTree T;
    CreateBiTree(T);

    printf("后序遍历: ");
    PostOrderTraverse(T);
    return 0;
}