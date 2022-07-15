/*
    带头结点的非循环双向链表，每个结点除有pred（前驱指针）、data（数据）和next（后继指针）外
    还有一个访问频度域freq，初始值位0，每当链表中进行一次Locate(L, x)运算时，值增1
    并使节点按访问频度递减顺序排列，同时最近访问的结点排在频度相同的结点前面
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef struct DNode {
    int data;
    int freq;
    struct DNode *prior, *next;
} DNode, *DLinklist;

//初始化空的非循环双链表
bool InitDLinkList(DLinklist &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

//构建带头结点的非循环双链表
void CreateDLinkList(DLinklist &L, int data[], int n) {
    DNode *cur = L, *s;
    for (int i = 0; i < n; i++) {
        s = (DNode *) malloc(sizeof(DNode));
        s->data = data[i];
        s->freq = 0;
        cur->next = s;
        s->prior = cur;
        cur = cur->next;
    }
    cur->next = NULL;
}

void printDLinkList(DLinklist L) {
    DNode *cur = L->next;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

// DNode * Locate(DLinklist L, int x) {
//     DNode *cur = L->next;
//     while (cur->data != x && cur != NULL) {
//         cur = cur->next;
//     }
//     cur->freq++;
//     return cur;
// }

// void SortedFreq(DLinklist &L, DNode *record) {
//     DNode *pre = L;
//     DNode *fcur = L->next;
//     printf("%d ", record->data);
//     printf("%d ", record->freq);
//     record->next->prior = record->prior;
//     record->prior->next = record->next;
//     while (fcur) {
//         if (fcur->freq <= record->freq && fcur != L) {
//             break;
//         }
//         else {
//            fcur = fcur->next; 
//         }
        
//     }
//     printf("%d ", fcur->data);
//     printf("%d ", fcur->freq);
//     printf("\n");
//     pre = fcur->prior;
//     //将记录结点插入到表头
//     record->next = fcur;
//     fcur->prior = record;
//     pre->next = record;
//     record->prior = pre;
//     printDLinkList(L);
// }

void Locate(DLinklist &L, int x) {
    DNode *pre;
    DNode *cur = L->next;
    while (cur && cur->data != x) {
        cur = cur->next;
    }
    if (cur == NULL) {
        printf("没有这个结点\n");
    }   
    else {
        cur->freq++;
        if (cur->next != NULL) {
            cur->next->prior = cur->prior;
        }
        cur->prior->next = cur->next;
        pre = cur->prior;
        while (pre != L && pre->freq <= cur->freq) {
            pre = pre->prior;
        }
        cur->next = pre->next;
        pre->next->prior = cur;
        cur->prior = pre;
        pre->next = cur;
    }
    printDLinkList(L);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = ARRAY_SIZE(data);
    DLinklist L;
    InitDLinkList(L);
    CreateDLinkList(L, data, size);
    printDLinkList(L);
    // SortedFreq(L, Locate(L, 3));
    // SortedFreq(L, Locate(L, 5));
    Locate(L, 3);
    Locate(L, 5);
    Locate(L, 2);
    Locate(L, 8);
    return 0;
}