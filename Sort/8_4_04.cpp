/* 
    在基于单链表表示的待排序关键字序列上进行简单选择排序
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

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

void printList(LinkList L) {
    LNode *p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

//简单选择排序——链表实现（带头结点的单链表）
void SelectSortLink(LinkList &L) {
    LNode *r = L, *pre = L, *minpre = L, *p, *q;
    int min;
    while (r->next != NULL) {
        //从已排序的后一个元素开始遍历
        p = r->next;
        //初始时，将未排序的第一个结点设为最小
        min = p->data;
        //初始时，最小元素的前驱结点指向已排序的最后一个元素
        pre = r;
        //初始时，q指向未排序的第一个元素
        q = p;
        while (p) {
            if (p->data < min) {
                min = p->data;
                minpre = pre;
                //q记录最小值的位置
                q = p;
            }
            //当前结点的数据域比最小值大
            else {
                //前驱指针与当前指针同步后移
                pre = pre->next;
                p = p->next;
            }
        }
        //如果遍历一趟后发现最小值是未排序中的第一个元素，直接修改已排好序的最后一个元素的指针
        if (q == r->next)
            r = r->next;
        //如果最小值不是未排序元素的中第一个位置
        else {
            //将最小值的前驱指针指向最小值的后继
            minpre->next = q->next;
            //将最小值插入到已排好序元素的最后一个
            q->next = r->next;
            //修改已排好序元素的最后一个元素的指针r
            r->next = q;
            //修改指针的指向，已排序好，前进一格
            r = q;
        }
    }
}

int main() {
    LinkList L;
    InitList(L);
    List_TailInsert(L);
    printf("输出从小到大排序的单链表：");
    SelectSortLink(L);
    printList(L);
    return 0;
}