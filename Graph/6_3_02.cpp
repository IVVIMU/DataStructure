/*
    判断一个无向图G是否为一棵树
    算法思想：一个无向图是一棵树的条件是:图G必须是无回路的连通图或者有n-1条边的连通图。
    因此我们可以采用深度遍历，若图连通，那么只要一次深度遍历就可以遍历出所有的顶点，于是只需要调用一次dfs，并设置两个计数器记录边和顶点的数目即可。
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
void DFS(AMGraph G, VertexType ch, int &count_v, int &count_e) {
    int i, j;
    for (i = 0; i < G.vexnum; i++) {
        if (G.Vex[i] == ch)
            j = i;
    }
    visit(ch);
    visited[j] = true;  //做已访问标记
    count_v++;          //顶点计数
    for (i = FirstNeighbor(G, G.Vex[j]); i >= 0; i = NextNeighbor(G, G.Vex[j], G.Vex[i])) {
        count_e++;      //边存在则边计数
        if (!visited[i]) {
            DFS(G, G.Vex[i], count_v, count_e);
        }
    }
}

bool IsTree(AMGraph G) {
    //访问标记数组初始化
    for (int i = 0; i < G.vexnum; i++) 
        visited[i] = false;
    //顶点和边计数器
    int count_v = 0;
    int count_e = 0;
    //进行一次深度优先搜索
    DFS(G, G.Vex[0], count_v, count_e);
    //邻接矩阵(表)在存储无向图的时， 每一条边都存储了两次，所以计数器中得到的是两倍的边数
    if (count_v == G.vexnum && count_e == (G.vexnum - 1) * 2)
        return true;
    else 
        return false;
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

    

    return 0;
}