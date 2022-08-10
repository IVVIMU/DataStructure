/*
    双亲表示法
*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define MaxSize 100

//树的结点定义
typedef struct {
    //数据元素
    ElemType data;
    //双亲数据域
    int parent;
} PTNode;

//树的类型定义
typedef struct {
    //双亲表示
    PTNode nodes[MaxSize];
    //结点数
    int n;
} PTree;