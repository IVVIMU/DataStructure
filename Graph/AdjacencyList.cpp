/*
    不带权无向图邻接表实现
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100  //顶点数目的最大值

typedef char VertexType;  //顶点的数据类型

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

//判断图G是否存在弧(x,y)
bool Adjacent(ALGraph G, VertexType x, VertexType y) {
    int i, j, k;
    for (i = 0; i < G.vexnum; i++) {
        if (G.adjlist[i].data == x) j = i;
        if (G.adjlist[i].data == y) k = i;
    }
    ArcNode *p = G.adjlist[j].first;
    while (p != NULL) {
        if (p->adjvex == k) 
            return true;
        else 
            p = p->next;
    }
    return false;
}

//列出图G中与结点x邻接的弧
void Neighbors(ALGraph G, VertexType x) {
    int i, j;
    for (i = 0; i < G.vexnum; i++) {
        if (G.adjlist[i].data == x)
            j = i;
    }
    ArcNode *p = G.adjlist[j].first;
    while (p != NULL) {
        printf("%c ", G.adjlist[p->adjvex].data);
        p = p->next;
    }
}

//在图G中插入顶点x
bool InsertVertex(ALGraph &G, VertexType x) {
    for (int i = 0; i < G.vexnum; i++) {
        //与图G中原有顶点值相同
        if (G.adjlist[i].data == x)
            return false;
    }
    G.adjlist[G.vexnum].data = x;
    G.adjlist[G.vexnum].first = NULL;
    G.vexnum++;
    return true;
}

//在图G中删除顶点x
bool DeleteVertex(ALGraph &G, VertexType x) {
    int i, j;
    for (i = 0; i < G.vexnum; i++) {
        if (G.adjlist[i].data == x)
            j = i;
    }
    if (j >= G.vexnum)
        return false;
    
    //删除顶点x所在邻接表中的一行数据
    ArcNode *p = G.adjlist[j].first;
    ArcNode *q = p->next;
    while (q != NULL) {
        free(p);
        p = q;
        q = q->next;
    }
    G.adjlist[j].first = NULL;

    //删除其他顶点与顶点x有关的数据
    for (i = 0; i < G.vexnum; i++) {
        p = G.adjlist[i].first;
        while (p != NULL) {
            if (p->adjvex == j) {
                if (p->adjvex == G.adjlist[i].first->adjvex) {  //环
                    G.adjlist[i].first = p->next;
                    free(p);
                    break;
                }
                else {
                    q->next = p->next;
                    free(p);
                    break;;
                }
            }
            q = p;
            p = p->next;
        }
    }

    //调整顶点表，将其他元素上移填补删除元素的空缺
    for (i = j; i < G.vexnum; i++) {
        G.adjlist[i].data = G.adjlist[i + 1].data;    //对应顶点上移
        G.adjlist[i].first = G.adjlist[i + 1].first;  //对应边结点链表上移
    }

    //修改边结点边表中的数据
    for (i = 0; i < G.vexnum; i++) {
        p = G.adjlist[i].first;
        while (p != NULL) {
            if (p->adjvex > j)
                p->adjvex - 1;
            p = p->next;
        }
    }

    //顶点数减一
    G.vexnum--;
    return true;
}

//若无向边(x,y)不存在，则向图G中添加该边
bool AddEdge(ALGraph &G, VertexType x, VertexType y) {
    int i, j, k;
    for (i = 0; i < G.vexnum; i++) {
        if (G.adjlist[i].data == x) j = i;
        if (G.adjlist[i].data == y) k = i;
    }
    //不存在顶点x或顶点y
    if (j >= G.vexnum || k >= G.vexnum)
        return false;
    else {
        ArcNode *p = G.adjlist[j].first;
        ArcNode *r = G.adjlist[k].first;
        ArcNode *q, *s;
        q = (ArcNode *) malloc(sizeof(ArcNode));
        q->adjvex = k;
        q->next = p;
        G.adjlist[j].first = q;

        s = (ArcNode *) malloc(sizeof(ArcNode));
        s->adjvex = j;
        s->next = r;
        G.adjlist[k].first = s;
        return true;
    }
}

//若无向边(x,y)存在，则从图G中删除该边
bool DeleteEdge(ALGraph &G, VertexType x, VertexType y) {
    int i, j, k;
    for (i = 0; i < G.vexnum; i++) {
        if (G.adjlist[i].data == x) j = i;
        if (G.adjlist[i].data == y) k = i;
    }
    //不存在顶点x或顶点y
    if (j >= G.vexnum || k >= G.vexnum) 
        return false;
    else {
        ArcNode *p = G.adjlist[j].first;
        ArcNode *q;
        ArcNode *r = G.adjlist[k].first;
        ArcNode *s;
        while (p != NULL) {
            if (p->adjvex == k) {
                if (p->adjvex == G.adjlist[j].first->adjvex) {  //环
                    G.adjlist[j].first = p->next;
                    free(p);
                    break;
                }
                else {
                    q->next = p->next;
                    free(p);
                    break;
                }
            }
            else {
                q = p;
                p = p->next;
            }
        }
        while (r != NULL) {
            if (r->adjvex == j) {
                if (r->adjvex == G.adjlist[k].first->adjvex) {  //环
                    G.adjlist[k].first = r->next;
                    free(r);
                    break;
                }
                else {
                    s->next = r->next;
                    free(r);
                    break;
                }
            }
            else {
                s = r;
                r = r->next;
            }
        }
    }
    return true;
}

//求图G中顶点x的第一个邻接点，若有则返回顶点号，若x没有邻接点或图中不存在，则返回-1
int FirstNeighbor(ALGraph &G, VertexType x) {
    int i, j;
    for (i = 0; i < G.vexnum; i++) {
        if (G.adjlist[i].data == x)
            j = i;
    }
    //图中不存在x
    if (j >= G.vexnum)
        return -1;
    ArcNode *p = G.adjlist[j].first;
    //若x没有邻接点
    if (p == NULL)
        return -1;
    else 
        return p->adjvex;
}

//假设图G中顶点y是顶点x的一个邻接点，返回除y外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1
int NextNeighbor(ALGraph &G, VertexType x, VertexType y) {
    int i, j, k;
    for (i = 0; i < G.vexnum; i++) {
        if (G.adjlist[i].data == x) j = i;
        if (G.adjlist[i].data == y) k = i;
    }
    //不存在顶点x或顶点y
    if (j >= G.vexnum || k >= G.vexnum) 
        return -1;
    else {
        ArcNode *p = G.adjlist[j].first;
        while (p != NULL) {
            if (p->adjvex == k) {
                if (p->next != NULL)
                    return p->next->adjvex;
                else 
                    return -1;
            }
            else {
                p = p->next;
            }
        }
    }
}

//统计顶点x的度
void CountDegree(ALGraph &G) {
    ArcNode *p;
    int sumdegree = 0;
    printf("输出各顶点的度: \n");
    for (int i = 0; i < G.vexnum; i++) {
        p = G.adjlist[i].first;
        int degree = 0;
        while (p != NULL) {
            degree++;
            p = p->next;
        }
        sumdegree = sumdegree + degree;
        printf("顶点%c的度为: %d\n", G.adjlist[i].data, degree);
    }
    printf("无向图G中所有顶点的度之和为: %d", sumdegree);
    G.vexnum = sumdegree / 2;
}

void PrintG(ALGraph G) {
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

int main() {
    ALGraph G;
    VertexType ch;
    int i, num;
    ArcNode *p;

    InitALG(G);
    CreateVNode(G);
    printf("\n");
    for (i = 0; i < G.vexnum; i++) {
        printf("创建顶点%c的边结点\n", G.adjlist[i].data);
        printf("输入要创建的边结点个数: ");
        scanf("%d", &num);
        CreateArcNode(G, G.adjlist[i].data, num);
        printf("\n");
    }

    PrintG(G);

    CountDegree(G);
    printf("\n");
    printf("\n无向图G中顶点数为: %d, 边数为: %d\n", G.vexnum, G.edgenum);

    VertexType x, y;

	/*printf("\n-----判断图G是否存在弧<x,y>-----\n");
	x = 'C', y = 'F';
	printf("顶点%c和顶点%c之间存在弧吗？(1表示存在，0表示不存在)— %d", x, y, Adjacent(G, x, y));
	x = 'A', y = 'D';
	printf("\n顶点%c和顶点%c之间存在弧吗？(1表示存在，0表示不存在)— %d\n", x, y, Adjacent(G, x, y));

	printf("\n-----列出图G中与结点x邻接的弧-----\n");
	x = 'B';
	printf("与顶点%c连接的弧有: ", x);
	Neighbors(G, x);
	printf("\n");*/

	/*printf("\n-----在图G中插入顶点x-----\n");
	x = 'G';
	printf("插入顶点%c", x);
	printf("插入成功了吗？— %d(1表示成功，0表示失败)\n", InsertVertex(G, x));
	printf("\n");
	PrintG(G);
	CountDegree(G);
	printf("\n");
	printf("\n无向图G的顶点数为: %d，边数为: %d\n", G.vexnum, G.edgenum);*/

	/*printf("\n-----在图G中插入删除顶点x-----\n");
	x = 'C';
	printf("删除顶点%c\n", x);
	printf("删除成功了吗？— %d(1表示成功，0表示失败)\n", DeleteVertex(G, x));
	printf("\n");
	PrintG(G);
	CountDegree(G);
	printf("\n");
	printf("\n无向图G的顶点数为: %d，边数为: %d\n", G.vexnum, G.edgenum);*/

	/*printf("\n-----图G中添加无向边(x, y)-----\n");
	x = 'E', y = 'F';
	printf("在顶点%c与顶点%c之间添加一条无向边\n", x, y);
	printf("添加成功了吗？— %d(1代表成功，原图中没有边(x, y)，0代表失败，原图中已存在该边或者顶点x/顶点y不存在)\n", AddEdge(G, x, y));
	printf("\n");
	PrintG(G);
	CountDegree(G);
	printf("\n");
	printf("\n无向图G的顶点数为: %d，边数为: %d\n", G.vexnum, G.edgenum);*/

	/*printf("\n-----删除图G中无向边(x, y)-----\n");
	x = 'B', y = 'F';
	printf("删除顶点%c与顶点%c之间的一条无向边\n", x, y);
	printf("删除成功了吗？— %d(1代表成功，原图中有边(x, y)，0代表失败，原图中不存在该边或者顶点x/顶点y不存在)\n", RemoveEdge(G, x, y));
	printf("\n");
	PrintG(G);
	CountDegree(G);
	printf("\n");
	printf("\n无向图G的顶点数为: %d，边数为: %d\n", G.vexnum, G.edgenum);*/

	/*printf("\n-----求图G中顶点x的第一个邻接点-----\n");
	x = 'E';
	printf("图G中顶点%c的第一个邻接点的顶点号为: %d(-1代表x没有邻接点或图中不存在x)\n", x, FirstNeighbor(G, x));*/

	/*printf("\n-----求图G中除y之外顶点x的下一个邻接点的顶点号-----\n");
	x = 'B', y = 'E';
	printf("图G中除顶点%c之外顶点%c的下一个邻接点的顶点号为: %d(-1代表x没有邻接点或图中不存在x)\n", x, y, NextNeighbor(G, x, y));*/

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
*/

