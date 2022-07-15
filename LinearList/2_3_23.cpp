/*
    两个单链表共享后缀
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef struct LNode {
    char data;
    struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    //内存不足，分配失败
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

//构建带头结点的单链表
void CreateLinkList(LinkList &L, char data[], int n) {
    LNode *cur = L, *s;
    for (int i = 0; i < n; i++) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = data[i];
        cur->next = s;
        cur = cur->next;
    }
    cur->next = NULL;
}

void printLinkList(LinkList L) {
    LNode *cur = L->next;
    while (cur) {
        printf("%c", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

LNode * startSuffix(LinkList M, int m, LinkList N, int n) {
    LNode *Mcur = M->next;
    LNode *Ncur = N->next;
    int dist = abs(m - n);
    if (m >= n) {
        while (dist--)
            Mcur = Mcur->next;
    }
    else {
        while (dist--)
            Ncur = Ncur->next;
    }
    while (Mcur) {
        if (Mcur->data != Ncur->data) {
           Mcur = Mcur->next;
            Ncur = Ncur->next; 
        }
        else {
            return Mcur;
        }
    }
    return Mcur;
}

int main() {
    char word[] = {'l', 'o', 'a', 'd', 'i', 'n', 'g'};
    char word2[]= {'b', 'e', 'i', 'n', 'g'};
    int m = ARRAY_SIZE(word);
    int n = ARRAY_SIZE(word2);
    LinkList M;
    LinkList N;
    InitList(M);
    InitList(N);
    CreateLinkList(M, word, m);
    CreateLinkList(N, word2, n);
    printLinkList(M);
    printLinkList(N);
    LNode *start = startSuffix(M, m, N, n);
    printf("%c", start->data);
    return 0;
}