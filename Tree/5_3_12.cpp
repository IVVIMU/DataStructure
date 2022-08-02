/*
    打印值位x的结点的所有祖先，假设值位x的结点不多于一个
    算法思想：采用非递归的后序遍历算法，结点依次入栈，当访问到值为x的结点时，栈中所有元素均为该结点的祖先
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

void FindAllAncestor(BiTree T, ElemType x) {
    LinkStack S;
    InitStack(S);
    BiTNode *p = T;
    BiTNode *r = NULL;
    BiTNode *temp;
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
                if (p->data == x) {
                    printf("祖先元素有：");
                    while (!StackEmpty(S)) {
                        temp = Pop(S);
                        printf("%d ", temp->data);
                    }
                }
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
    FindAllAncestor(T, 4);
    return 0;
}