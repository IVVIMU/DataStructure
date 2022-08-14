/*
    判断图G中是否存在EL路径
    算法思想：当图G中度为奇数的顶点个数为不大于2的偶数(指为0或2)时，G存在包含所有边且长度为|E|的路径，称为EL路径
    采用邻接矩阵法表示
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

//判断是否存在EL路径，若存在则返回1，若不存在则返回0
int IsExitEL(AMGraph G) {
    int oddnums = 0;
    for (int i = 0; i < G.vexnum; i++) {
        if (CountDegree(G, G.Vex[i]) % 2 != 0) 
            oddnums++;
    }
    if (oddnums == 0 || oddnums == 2)
        return 1;
    else 
        return 0;
}

int main() {
    AMGraph G;
    InitAMG(G);
    CreateVex(G);
    CreateEdge(G);

    if (IsExitEL(G) == 1)
        printf("存在EL路径");
    else
        printf("不存在EL路径");

    return 0;
}

/*
输入图的顶点：ABCDEF#
输入邻接矩阵信息：
0 1 1 1 0 0
1 0 0 0 1 1
1 0 0 0 1 0
1 0 0 0 0 1
0 1 1 0 0 0
0 1 0 1 0 0
存在EL路径
*/

