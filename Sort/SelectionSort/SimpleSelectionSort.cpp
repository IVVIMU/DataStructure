/* 
    简单选择排序
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define ElemType int

void Input(int a[], int num) {
    int data;
    printf("输入数据元素：");
    for (int i = 0; i < num; i++) {
        scanf("%d", &data);
        a[i] = data;
    }
}

void Print(int a[], int num) {
    for (int i = 0; i < num; i++) {
        printf("%d ", a[i]);
    }
}

//交换函数
void swap(ElemType &a, ElemType &b) {
    ElemType temp = a;
    a = b;
    b = temp;
}

//简单选择排序——线性表实现
void SelectSort(ElemType a[], int num) {
    int i, j, min;
    for (i = 0; i < num - 1; i++) {
        //记录最小元素位置
        min = i;
        for (j = i + 1; j < num; j++) {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
            swap(a[i], a[min]);  //swap函数共移动元素三次
    }
}

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

//判断单链表是否为空（带头结点）、
bool ListEmpty(LinkList L) {
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
    int a[MaxSize] = { 0 };
    int num;
    printf("输入要创建的数组长度：");
    scanf("%d", &num);
    Input(a, num);
    SelectSort(a, num);
    printf("输出从小到大的排序结果：");
    Print(a, num);

    LinkList L;
    InitList(L);
    List_TailInsert(L);
    printf("输出从小到大排序的单链表：");
    SelectSortLink(L);
    printList(L);

    return 0;
}

/* 
输入要创建的数组长度：10
输入数据元素：75 23 98 44 57 12 29 64 38 82
输出从小到大的排序结果：12 23 29 38 44 57 64 75 82 98

输入链表元素(输入9999终止):75 23 98 44 57 12 29 64 38 82 9999
输出从小到大排序的单链表：12 23 29 38 44 57 64 75 82 98 
*/