/*
    从图的邻接表表示转换成邻接矩阵表示
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100  //顶点数目的最大值

typedef char VertexType;  //顶点的数据类型
typedef int EdgeType;     //带权图中边上权值的数据类型

//边
typedef struct ArcNode {
    int adjvex;               //该边的邻接点编号
    struct ArcNode *next;     //指向下一条边的指针
    //int weight;             //该边的相关信息，如权值
} ArcNode;                    //边结点的类型

//顶点
typedef struct VNode {  //顶点表结点
    VertexType data;    //顶点信息
    ArcNode *first;     //指向第一个边结点
} VNode;

//邻接表
typedef struct {
    VNode adjlist[MaxVertexNum];  //邻接表的头结点数组
    int vexnum, edgenum;          //图中的顶点数和边数
} ALGraph;                        //ALGraph是以邻接表存储的图类型

//初始化
void InitALG(ALGraph &G) {
    for (int i = 0; i < MaxVertexNum; i++) {
        G.adjlist[i].data = '\0';
        G.adjlist[i].first = NULL;
    }
    G.vexnum = 0;
    G.edgenum = 0;
}

//创建顶点信息，输入示例：ABCDEF#
void CreateVNode(ALGraph &G) {
    int i = 0, count = 0;
    printf("输入图的顶点: ");
    VertexType ch = getchar();
    while (ch != '#') {
        G.adjlist[i].data = ch;
        G.adjlist[i].first = NULL;
        i++;
        count++;
        ch = getchar();
    }
    G.vexnum = count;
}

void CreateArcNode(ALGraph &G, VertexType ch, int num) {
    ArcNode *p;
    ArcNode *r = G.adjlist[0].first;
    int i, j, k;
    while (num--) {
        p = (ArcNode *) malloc(sizeof(ArcNode));
        p->next = NULL;
        printf("输入顶点的编号: ");
        scanf("%d", &i);
        for (j = 0; j < G.vexnum; j++) {
            if (G.adjlist[j].data == ch)
                k = j;
        }
        if (i != k) {
            p->adjvex = i;
            if (G.adjlist[k].first == NULL) {
                G.adjlist[k].first = p;
                r = p;
            }
            else {
                r->next = p;
                r = p;
            }
        }
    }
}

//打印邻接表
void PrintALG(ALGraph G) {
    ArcNode *p;
    printf("输出各顶点的连接情况: \n");
    for (int i = 0; i < G.vexnum; i++) {
        p = G.adjlist[i].first;
        printf("%d(%c) ", i, G.adjlist[i].data);
        while (p != NULL) {
            printf("-%d(%c) ", p->adjvex, G.adjlist[p->adjvex].data);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
}

typedef struct {
    VertexType Vex[MaxVertexNum];               //顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  //邻接矩阵，边表
    int vexnum, edgenum;                         //图的当前顶点数和边数
} AMGraph;

//初始化
void InitAMG(AMGraph &G) {
    int i, j;
    for (i = 0; i < MaxVertexNum; i++) G.Vex[i] = '\0';
    for (i = 0; i < MaxVertexNum; i++) {
        for (j = 0; j < MaxVertexNum; j++) {
            G.Edge[i][j] = 0;
        }
    }
    G.vexnum = 0;
    G.edgenum = 0;
}

//打印邻接矩阵
void PrintAMG(AMGraph G) {
    int i, j;
    printf("输出邻接矩阵：\n");
    for (i = 0; i < G.vexnum; i++) {
        printf("\t%c", G.Vex[i]);
    }
    printf("\n");
    for (i = 0; i < G.vexnum; i++) {
        printf("%c", G.Vex[i]);
        for (j = 0; j < G.vexnum; j++) {
            printf("\t%d", G.Edge[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//创建邻接矩阵顶点信息
void CreateVex(AMGraph &AMG, ALGraph ALG) {
    int i = 0;
    for (i = 0; i < ALG.vexnum; i++) {
        AMG.Vex[i] = ALG.adjlist[i].data;
    }
    AMG.vexnum = ALG.vexnum;
}

void ListConvertMatrix(AMGraph &AMG, ALGraph ALG) {
    CreateVex(AMG, ALG);
    ArcNode *p;
    for (int i = 0; i < AMG.vexnum; i++) {
        p = ALG.adjlist[i].first;
        while (p != NULL) {
            AMG.Edge[i][p->adjvex] = 1;;
            p = p->next;
        }
    }
}

int main() {
    int i, num;
    AMGraph AMG;
    InitAMG(AMG);
    ALGraph ALG;
    InitALG(ALG);
    //创建邻接表
    CreateVNode(ALG);
    printf("\n");
    for (i = 0; i < ALG.vexnum; i++) {
        printf("创建顶点%c的边结点\n", ALG.adjlist[i].data);
        printf("输入要创建的边结点个数: ");
        scanf("%d", &num);
        CreateArcNode(ALG, ALG.adjlist[i].data, num);
        printf("\n");
    }
    PrintALG(ALG);
    printf("将邻接表表示为邻接矩阵\n");
    ListConvertMatrix(AMG, ALG);
    PrintAMG(AMG);
    return 0;
}

/*
输入图的顶点: ABCDEF#

创建顶点A的边结点       
输入要创建的边结点个数: 3
输入顶点的编号: 1
输入顶点的编号: 2
输入顶点的编号: 3

创建顶点B的边结点       
输入要创建的边结点个数: 3
输入顶点的编号: 0
输入顶点的编号: 4
输入顶点的编号: 5

创建顶点C的边结点       
输入要创建的边结点个数: 2
输入顶点的编号: 0
输入顶点的编号: 4

创建顶点D的边结点       
输入要创建的边结点个数: 2
输入顶点的编号: 0
输入顶点的编号: 5

创建顶点E的边结点       
输入要创建的边结点个数: 2
输入顶点的编号: 1
输入顶点的编号: 2

创建顶点F的边结点
输入要创建的边结点个数: 2
输入顶点的编号: 1
输入顶点的编号: 3

输出各顶点的连接情况:
0(A) -1(B) -2(C) -3(D)
1(B) -0(A) -4(E) -5(F)
2(C) -0(A) -4(E)
3(D) -0(A) -5(F)
4(E) -1(B) -2(C)
5(F) -1(B) -3(D)

将邻接表表示为邻接矩阵
输出邻接矩阵：
        A       B       C       D       E       F
A       0       1       1       1       0       0
B       1       0       0       0       1       1
C       1       0       0       0       1       0
D       1       0       0       0       0       1
E       0       1       1       0       0       0
F       0       1       0       1       0       0
*/