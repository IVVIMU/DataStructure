#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/* 
    单链表实现——带头结点
*/

//初始化一个空的单链表（带头结点）
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    //内存不足，分配失败
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
} 

//判断单链表是否为空（带头结点）
bool LinkEmpty(LinkList L) {
    if (L->next == NULL)
        return true;
    else 
        return false;
}

//LNode *  强调这是一个结点
//LinkList   强调这是一个单链表
//LNode * 和LinkList是等价的，是为了代码可读性才这么做的

//按位取值（带头结点）
LNode * GetElem(LinkList L, int i) {
    if (i < 0) 
        return NULL;
    //p指向头结点，j置0（即头结点的序号为0）
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找
LNode * LocateElem(LinkList L, ElemType e) {
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

//按位序插入（带头结点）
//在第i个位置插入元素e
bool ListInsert(LinkList &L, int i, ElemType e) {
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
bool InsertNextNode(LNode *p, ElemType e) {
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
bool InsertPriorNode(LNode *p, ElemType e) {
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
bool ListDelete(LinkList &L, int i, ElemType &e) {
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
    printf("输入链表元素(输入9999终止):");
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
    printf("输入链表元素(输入9999终止):");
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
LinkList Reverse(LinkList L) {
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

//链表排序
LinkList Sort(LinkList L) {
    LNode *p, *q; 
    p = L->next;
    q = p->next;
    while (p->next != NULL) {
        while (q != NULL) {
            if (p->data > q->data) {
                int temp;
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
        q = p->next; 
    }
    return L;
}

//两个有序链表求交
LinkList Intersection(LinkList L1, LinkList L2) {
    LinkList L3;
    InitList(L3);
    LNode *p, *q, *r, *s;
    p = L1->next;
    q = L2->next;
    r = L3;
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            r->next = p;
            r = r->next;
            p = p->next;
            q = q->next;
        }
        else if (p->data < q->data) {
            p = p->next;
        }
        else {
            q = q->next;
        }
    }
    r->next = NULL;
    return L3;
}

//两个无序链表求交
LinkList unorder_Intersection(LinkList L1, LinkList L2) {
    LinkList L3;
    InitList(L3);
    LNode *p, *q, *r, *s;
    p = L1->next;
    q = L2->next;
    r = q;
    s = L3;
    while (p != NULL) {
        while (q != NULL) {
            if (p->data == q->data) {
                s->next = p;
                s = s->next;
            }
            q = q->next;
        }
        p = p->next;
        q = r;
    }
    s->next = NULL;
    L3 = Sort(L3);
    return L3;
}

void printList(LinkList L) {
    LNode *p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

/* 
    单链表实现——不带头结点
*/

//初始化一个空的单链表（不带头结点）
// bool InitList(LinkList &L) {
//     L = NULL;
//     return true;
// }

//判断单链表是否为空（不带头结点）
// bool LinkEmpty(LinkList L) {
//     return (L == NULL);
// }

//按位取值（不带头结点）
// LNode * GetElem(LinkList L, int i) {
//     int j = 1;
//     LNode *p = L->next;
//     if (i == 0) 
//         return L;
//     if (i < 1) 
//         return NULL;
//     while (p != NULL && j < i) {
//         p = p->next;
//         j++;
//     }
//     return p;
// }

//按位序插入（不带头结点）
// bool ListInsert(LinkList &L, int i, ElemType e) {
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

int main() {
    //声明一个指向单链表的指针
    LinkList L;
    //初始化一个空表
    // InitList(L);
    List_TailInsert(L);
    printList(L);
    printf("\n单链表逆置之后的元素：\n");
    // L = Reverse(L);
    printList(Reverse(L));
    printf("\n单链表排序之后的元素：\n");
    printList(Sort(L));

    //有序链表求交的操作
    LinkList L1, L2;
    List_TailInsert(L1);
    List_TailInsert(L2);
    LinkList L3 = Intersection(L1, L2);
    printList(L3);

    //无序链表求交的操作
    LinkList L4, L5;
    List_TailInsert(L3);
    List_TailInsert(L4);
    LinkList L6 = unorder_Intersection(L4, L5);
    printList(L6);
}

/* 
输入链表元素(输入9999终止):78 23 45 6 7 24 89 9999
78 23 45 6 7 24 89 
单链表逆置之后的元素：
89 24 7 6 45 23 78

有序链表求交的操作
输入链表元素(输入9999终止):1 3 4 9999
输入链表元素(输入9999终止):2 3 5 9999
3

无序链表求交的操作
输入链表元素(输入9999终止):1 5 8 3 9999
输入链表元素(输入9999终止):8 3 1 9999
1 3 8 
*/