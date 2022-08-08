/*
    孩子兄弟表示法
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct CSNode {
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;