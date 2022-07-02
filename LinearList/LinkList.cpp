#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

//初始化一个空的单链表（不带头结点）
// bool InitList(LinkList &L) {
//     L = NULL;
//     return true;
// }

//判断单链表是否为空（不带头结点）
// bool Empty(LinkList L) {
//     return (L == NULL);
// }

//初始化一个空的单链表（带头结点）
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    //内存不足，分配失败
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
} 

//判断单链表是否为空（带头结点）、
bool Empty(LinkList L) {
    if (L->next == NULL)
        return true;
    else 
        return false;
}

//LNode *  强调这是一个结点
//LinkList   强调这是一个单链表
//LNode * 和LinkList是等价的，是为了代码可读性才这么做的

//按位取值
LNode * GetElem(LinkList L, int i) {
    // int j = 1;
    // LNode *p = L->next;
    // if (i == 0) 
    //     return L;
    // if (i < 1) 
    //     return NULL;
    // while (p != NULL && j < i) {
    //     p = p->next;
    //     j++;
    // }
    // return p;
    if (i < 0) 
        return NULL;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找
LNode * LocateElem(LinkList L, int e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

//求表的长度
int Length(LinkList L) {
    int len = 0;
    LNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

//按位序插入（不带头结点）
// bool ListInsert(LinkList &L, int i, int e) {
//     if (i < 1)
//         return false;
//     //插入第一个结点的操作与其他结点操作不同
//     if (i == 1) {
//         LNode *s = (LNode *) malloc(sizeof(LNode));
//         s->data = e;
//         s->next = L;
//         L = s;
//         return true;
//     }
//     LNode *p;       //指针p指向当前扫描到的结点
//     int j = 1;          //当前p指向的是第几个结点
//     p = L;              //L指向头结点，头结点是第0个结点（不含数据）
//     //循环找到第i - 1个结点
//     while (p != NULL && j < i - 1) {
//         p = p->next;
//         j++;
//     }
//     if (p == NULL) 
//         return false;
//     LNode *s = (LNode *) malloc(sizeof(LNode));
//     s->data = e;
//     s->next = p->next;
//     p->next = s;
//     return true;
// }

//按位序插入（带头结点）
//在第i个位置插入元素e
bool ListInsert(LinkList &L, int i, int e) {
    if (i < 1)
        return false;
    LNode *p;       //指针p指向当前扫描到的结点
    int j = 0;          //当前p指向的是第几个结点
    p = L;              //L指向头结点，头结点是第0个结点（不含数据）
    //循环找到第i - 1个结点
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) 
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//后插操作
bool InsertNextNode(LNode *p, int e) {
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    //内存分配失败
    if (s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//前插操作
bool InsertPriorNode(LNode *p, int e) {
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) 
        return false;
    //通过数值交换的方式达到前插操作
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

//按位序删除（带头结点）
bool ListDelete(LinkList &L, int i, int &e) {
    if (i < 1)
        return false;
    LNode *p;       //指针p指向当前扫描到的结点
    int j = 0;          //当前p指向的是第几个结点
    p = L;              //L指向头结点，头结点是第0个结点（不含数据）
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//删除指定结点p
bool DeleteNode(LNode *p) {
    if (p == NULL)
        return false;
    if (p->next == NULL) {
        //p = NULL;
        free(p);
        return true;
    }
    //如果删除的结点是最后一个结点程序会出错
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(p);
    return true;
}

//尾插法
LinkList List_TailInsert(LinkList &L) {
    int x;
    //建立单链表的头结点
    L = (LinkList) malloc(sizeof(LNode));
    //r作为表尾指针
    LNode *s, *r = L;
    scanf("%d", &x);
    //输入9999表示结束
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    //尾结点指针置空
    r->next = NULL;
    return L;
}

//头插法，链表的逆置思想
//每取一次数据元素对头结点进行后插操作
LinkList List_HeadInsert(LinkList &L) {
    LNode *s;
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    //初始化空链表
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

//链表逆置
LinkList Reverse(LinkList &L) {
    LinkList p,q;
    //初始化
    p = L->next;
    L->next = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
        q->next = L->next;
        L->next = q;
    }
}

void printList(LinkList L) {
    while (L) {
        printf("%d ", L->data);
        L = L->next;
    }
}

int main() {
    //声明一个指向单链表的指针
    LinkList L;
    //初始化一个空表
    InitList(L);
    LinkList A = (LNode *) malloc(sizeof(LNode));
    LinkList B = (LNode *) malloc(sizeof(LNode));
    LinkList C = (LNode *) malloc(sizeof(LNode));
    LinkList D = (LNode *) malloc(sizeof(LNode));
    A->data = 1;
    B->data = 2;
    C->data = 3;
    D->data = 4;
    L->next = A;
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = NULL;
    printList(L->next);
    printf("\n单链表逆置之后的元素：\n");
    L = Reverse(L);
    printList(L->next);
}