/*
    邻接表实现深度优先搜索
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

void visit(VertexType x) {
    printf("%c ", x);
}

//标记访问数组
bool visited[MaxVertexNum];
void DFS(ALGraph G, VertexType ch) {
    int i, j;
    for (i = 0; i < G.vexnum; i++) {
        if (G.adjlist[i].data == ch)
            j = i;
    }
    visit(ch);
    visited[j] = true;  //做已访问标记
    for (i = FirstNeighbor(G, G.adjlist[j].data); i >= 0; i = NextNeighbor(G, G.adjlist[j].data, G.adjlist[i].data)) {
        if (!visited[i])
            DFS(G, G.adjlist[i].data);
    }
}

void DFSTraverse(ALGraph G) {
    //访问标记数组初始化
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i])
            //对每个连通分量调用一次BFS，调用BFS的次数即图中连通分量的个数
            DFS(G, G.adjlist[i].data);
    }
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
    printf("\n无向图G的顶点数为: %d, 边数为: %d\n", G.vexnum, G.edgenum);

    printf("\n输出深度优先搜索结果: ");
    DFSTraverse(G);

    return 0;
}

/*
输入图的顶点: ABCDEFG#

创建顶点A的边结点
输入要创建的边结点个数: 2
输入顶点的编号: 1
输入顶点的编号: 4

创建顶点B的边结点
输入要创建的边结点个数: 2
输入顶点的编号: 0
输入顶点的编号: 5

创建顶点C的边结点
输入要创建的边结点个数: 3
输入顶点的编号: 3
输入顶点的编号: 5
输入顶点的编号: 6

创建顶点D的边结点
输入要创建的边结点个数: 1
输入顶点的编号: 2

创建顶点E的边结点
输入要创建的边结点个数: 1
输入顶点的编号: 0

创建顶点F的边结点
输入要创建的边结点个数: 3
输入顶点的编号: 1
输入顶点的编号: 2
输入顶点的编号: 6

创建顶点G的边结点
输入要创建的边结点个数: 2
输入顶点的编号: 2
输入顶点的编号: 5

输出各顶点的连接情况:
0(A) -1(B) -4(E)
1(B) -0(A) -5(F)
2(C) -3(D) -5(F) -6(G)
3(D) -2(C)
4(E) -0(A)
5(F) -1(B) -2(C) -6(G)
6(G) -2(C) -5(F)

输出各顶点的度:
顶点A的度为: 2
顶点B的度为: 2
顶点C的度为: 3
顶点D的度为: 1
顶点E的度为: 1
顶点F的度为: 3
顶点G的度为: 2
无向图G中所有顶点的度之和为: 14

无向图G的顶点数为: 7, 边数为: 0

输出深度优先搜索结果: A B F C D G E
*/