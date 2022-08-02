/*
    p、q分别为指向该二叉树中任意两个结点的指针，设p在q的左边。找到p和q的公共结点r
    算发思想：采用后序遍历的非递归算法，使用两个辅助栈，一个栈存放p的所有祖先结点，另一个存放q的所有祖先结点，再从栈顶开始逐个匹配，第一个匹配的元素即为最近公共结点
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int 

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

//判断栈中是否含有某个元素
bool Contain(LinkStack S, BiTNode *node) {
    if (StackEmpty(S))
        return false;
    LNode *temp = S->next;
    while (temp) {
        if (temp->data == node)
            return true;
        temp = temp->next;
    }
    return false;
}

void visit(BiTNode *p) {
    printf("%d ", p->data);
}

void FindAllAncestor(BiTree T,LinkStack &S, BiTNode *node) {
    BiTNode *m = T;
    BiTNode *r = NULL;
    while (m || !StackEmpty(S)) {
        //走到最左边
        if (m) {
            Push(S, m);
            m = m->lchild;
        }
        else {
            m = GetTop(S);
            //若右子树存在且未被访问过
            if (m->rchild && m->rchild != r) {
                m = m->rchild;
            }
            else {
                m = Pop(S);
                if (m->data == node->data)  //我他妈的疯了，把==写成=了，调试了2个小时，啊啊啊啊啊啊，我的时间啊啊啊啊啊
                    break;
                //记录最近访问过的结点
                r = m;
                //结点访问完重置p指针
                m = NULL;
            }
        }
    }
}

BiTNode * FindCommonAncestor(BiTree T, BiTNode *p, BiTNode *q) {
    LinkStack A, B;
    InitStack(A);
    InitStack(B);
    
    FindAllAncestor(T, A, p);
    FindAllAncestor(T, B, q);

    BiTNode *node;
    while (!StackEmpty(A)) {
        node = GetTop(A);
        if (Contain(B, node))
            break;
        Pop(A);
    }
    return node;
}

int main() {
    BiTree T;
    CreateBiTree(T);
    BiTNode *p = T->lchild->lchild;
    BiTNode *q = T->rchild->rchild;
    BiTNode *node = FindCommonAncestor(T, p, q);
    visit(node);
    return 0;
}