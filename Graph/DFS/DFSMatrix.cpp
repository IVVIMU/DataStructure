/*
    邻接矩阵实现深度优先搜索
*/

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100  //顶点数目的最大值

typedef char VertexType;  //顶点的数据类型
typedef int EdgeType;     //带权图中边上权值的数据类型
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

//创建顶点信息，输入示例：ABCDEF#
void CreateVex(AMGraph &G) {
	int i = 0, count = 0;
	printf("输入图的顶点：");
	VertexType ch= getchar();
	while (ch != '#')
	{
		G.Vex[i++] = ch;
		ch = getchar();
		count++; //统计顶点个数
	}
	G.vexnum = count;
}

//创建邻接矩阵信息
void CreateEdge(AMGraph &G) {
    EdgeType ch;
    printf("输入邻接矩阵信息：\n");
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            scanf("%d", &ch);
            G.Edge[i][j] = ch;
        }
    }
}

//图的顶点数和边数
void Info(AMGraph &G) {
    int count = 0;
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            if (G.Edge[i][j] == 1) count++;
        }
    }
    G.edgenum = count / 2;
}

//统计顶点的度
int CountDegree(AMGraph G, VertexType point) {
    int j, count = 0;
    //找到对应顶点元素的下标
    for (int i = 0; i < G.vexnum; i++) {
        if (G.Vex[i] == point) j = i;
    }
    for (int k = 0; k < G.vexnum; k++) {
        if (G.Edge[j][k] == 1) count++;
    }
    return count;
}

//求图G中顶点x的第一个邻接点，若有则返回顶点号，若x没有邻接点或图中不存在，则返回-1
int FirstNeighbor(AMGraph G, VertexType x) {
    int i, j;
    for (i = 0; i < G.vexnum; i++) {
        if (G.Vex[i] == x) j = i;
    }
    //图中不存在值位x的顶点
    if (j >= G.vexnum) 
        return -1;
    else {
        for (i = 0; i < G.vexnum; i++) {
            if (G.Edge[j][i] == 1) 
                return i;  //返回顶点号
        }
        if (i >= G.vexnum) 
            return -1;     //x没有邻接点
    }
}

//假设图G中顶点y是顶点x的一个邻接点，返回除y外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1
int NextNeighbor(AMGraph G, VertexType x, VertexType y) {
    int i, j, k;
    for (i = 0; i < G.vexnum; i++) {
        if (G.Vex[i] == x) j = i;
        if (G.Vex[i] == y) k = i;
    }
    //不存在顶点x或顶点y
    if (j >= G.vexnum || k >= G.vexnum) {
        return false;
    }
    else {
        for (i = k + 1; i < G.vexnum; i++) {
            if (G.Edge[j][i] == 1)
                return i;  //返回顶点号
        }
        if (i >= G.vexnum)
            return -1;     //x没有邻接点
    }
}

//输出各顶点的连接情况
void PrintG(AMGraph G) {
    int i, j;
    for (i = 0; i < G.vexnum; i++) {
        for (j = 0; j < G.vexnum; j++) {
            if (G.Edge[i][j] == 1) 
                printf("%c->%c		", G.Vex[i], G.Vex[j]);
        }
        printf("\n");
    }
}

//输出邻接矩阵
void PrintMatrix(AMGraph G) {
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

void visit(VertexType x) {
    printf("%c ", x);
}

//访问标记数组
bool visited[MaxVertexNum];
void DFS(AMGraph G, VertexType ch) {
    int i, j;
    for (i = 0; i < G.vexnum; i++) {
        if (G.Vex[i] == ch)
            j = i;
    }
    visit(ch);
    visited[j] = true;  //做已访问标记
    for (i = FirstNeighbor(G, G.Vex[j]); i >= 0; i = NextNeighbor(G, G.Vex[j], G.Vex[i])) {
        if (!visited[i]) {
            DFS(G, G.Vex[i]);
        }
    }
}

void DFSTraverse(AMGraph G) {
    //访问标记数组初始化
    for (int i = 0; i < G.vexnum; i++) 
        visited[i] = false;
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i])
            DFS(G, G.Vex[i]);
    }
}

int main() {
    AMGraph G;
    InitAMG(G);
    CreateVex(G);
    CreateEdge(G);

    Info(G);
    printf("\n无向图G中共有: %d个顶点, %d条边\n", G.vexnum, G.edgenum);

    PrintMatrix(G);

    printf("输出无向图G中各顶点的连接情况: \n");
    PrintG(G);
    printf("\n");

    int sumdegree = 0, i;
    for (i = 0; i < G.vexnum; i++) {
        int degree;
        degree = CountDegree(G, G.Vex[i]);
        printf("顶点%c的度为: %d\n", G.Vex[i], degree);
        sumdegree = sumdegree + degree;
    }
    printf("无向图G中所有顶点的度之和为: %d\n", sumdegree);

    printf("\n输出深度优先搜索结果: ");
    DFSTraverse(G);

    return 0;
}

/*
输入图的顶点：ABCDEFG#
输入邻接矩阵信息：
0 1 0 0 1 0 0
1 0 0 0 0 1 0
0 0 0 1 0 1 1
0 0 1 0 0 0 0
1 0 0 0 0 0 0
0 1 1 0 0 0 1
0 0 1 0 0 1 0

无向图G中共有: 7个顶点, 7条边
输出邻接矩阵：
        A       B       C       D       E       F       G
A       0       1       0       0       1       0       0
B       1       0       0       0       0       1       0
C       0       0       0       1       0       1       1
D       0       0       1       0       0       0       0
E       1       0       0       0       0       0       0
F       0       1       1       0       0       0       1
G       0       0       1       0       0       1       0

输出无向图G中各顶点的连接情况:
A->B            A->E
B->A            B->F
C->D            C->F            C->G
D->C
E->A
F->B            F->C            F->G
G->C            G->F

顶点A的度为: 2
顶点B的度为: 2
顶点C的度为: 3
顶点D的度为: 1
顶点E的度为: 1
顶点F的度为: 3
顶点G的度为: 2
无向图G中所有顶点的度之和为: 14

输出深度优先搜索结果: A B F C D G E
*/