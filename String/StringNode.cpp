/*
    堆分配存储表示
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MaxSize 255

typedef struct StringNode {
    //提高存储密度
    char ch[4];
    struct StringNode *next;
} StringNode, *String;