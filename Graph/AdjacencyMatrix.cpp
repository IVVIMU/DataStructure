/*
    不带权无向图邻接矩阵实现
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

//判断图G是否存在边(x,y)
bool Adjacent(AMGraph G, VertexType x, VertexType y) {
    int i, j, k;
    for (i = 0; i < G.vexnum; i++) {
        if (G.Vex[i] == x) j = i;
        if (G.Vex[i] == y) k = i;
    }
    if (G.Edge[j][k] == 1) return true;
    else return false;
}

//列出图G中与顶点x邻接的边
void Neighbors(AMGraph G, VertexType x) {
    int i, j;
    for (i = 0; i < G.vexnum; i++) {
        if (G.Vex[i] == x) j = i;
    }
    for (i = 0; i < G.vexnum; i++) {
        if (G.Edge[j][i] == 1) {
            printf("%c ", G.Vex[i]);
        }
    }
}

//在图G中插入顶点x
bool InsertVertex(AMGraph &G, VertexType x) {
    for (int i = 0; i < G.vexnum; i++) {
        //与图G中原有顶点值相同
        if (G.Vex[i] == x)
            return false;
    }
    G.Vex[G.vexnum] = x;
    G.vexnum++;
    return true;
}

//从图中删除顶点x
bool DeleteVertex(AMGraph &G, VertexType x) {
    int i, j, k;
    for (i = 0; i < G.vexnum; i++) {
        if (G.Vex[i] == x) 
            k = i;
    }
    if (k < G.vexnum) {
        //处理顶点表中的值
        for (j = k; j < G.vexnum - 1; j++) {
            G.Vex[j] = G.Vex[j + 1];
        }

        //处理邻接矩阵中的值
        //处理矩阵右上元素
        for (i = 0; i < k; i++) {
            for (j = k; j < G.vexnum -1; j++) {
                G.Edge[i][j] = G.Edge[i][j + 1];
            }
        }

        //处理矩阵左下元素
        for (i = k; i < G.vexnum - 1; i++) {
            for (j = 0; j < k; j++) {
                G.Edge[i][j] = G.Edge[i + 1][j];
            }
        }

        //处理矩阵右下元素
        for (i = k; i < G.vexnum - 1; i++) {
            for (j = k; j < G.vexnum - 1; j++) {
                G.Edge[i][j] = G.Edge[i + 1][j + 1];
            }
        }
        G.vexnum--;
        return true;
    }
    return false;
}

//若无向边(x,y)不存在，则向图G中添加该边
bool AddEdge(AMGraph &G, VertexType x, VertexType y) {
    int i, j, k;
    for (i = 0; i < G.vexnum; i++) {
        if (G.Vex[i] == x) j = i;
        if (G.Vex[i] == y) k = i;
    }
    //不存在顶点x或y
    if (j >= G.vexnum || k >= G.vexnum) {
        return false;
    } 
    else {
        if (G.Edge[j][k] == 0) {
            G.Edge[j][k] = 1;
            G.Edge[k][j] = 1;
            return true;
        }
        else 
            //该边已存在
            return false;
    }
}

//若无向边(x,y)存在，则向图G中删除该边
bool RemoveEdge(AMGraph &G, VertexType x, VertexType y) {
    int i, j, k;
    for (i = 0; i < G.vexnum; i++) {
        if (G.Vex[i] == x) j = i;
        if (G.Vex[i] == y) k = i;
    }
    if (j >= G.vexnum || k >= G.vexnum) {
        return false;
    }
    else {
        if (G.Edge[j][k] == i) {
            G.Edge[j][k] = 0;
            G.Edge[k][j] = 0;
            return true;
        }
        else 
            //该边不存在
            return false;
    }
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

int main() {
    AMGraph G;
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    InitAMG(G);
    CreateVex(G);
    CreateEdge(G);

    Info(G);
    printf("\n无向图G中共有: %d个顶点, %d条边\n", G.vexnum, G.edgenum);

    PrintMatrix(G);

    printf("输出无向图G中各顶点的连接情况: \n");
    PrintG(G);

    int sumdegree = 0;
    for (int i = 0; i < G.vexnum; i++) {
        int degree;
        degree = CountDegree(G, G.Vex[i]);
        printf("顶点%c的度为: %d\n", G.Vex[i], degree);
        sumdegree = sumdegree + degree;
    }
    printf("无向图G中所有顶点的度之和为: %d\n", sumdegree);

    VertexType x, y;

	/*printf("\n-----判断图G是否存在边(x,y)-----\n");
	x = 'C', y = 'F';
	printf("顶点%c和顶点%c之间存在边吗？(1表示存在，0表示不存在)— %d", x, y, Adjacent(G, x, y));
	x = 'A', y = 'D';
	printf("\n顶点%c和顶点%c之间存在边吗？(1表示存在，0表示不存在)— %d\n", x, y, Adjacent(G, x, y));*/

	/*printf("\n-----列出图G中与结点x邻接的边-----\n");
	x = 'B';
	printf("与顶点%c连接的边有：", x);
	Neighbors(G, x);
	printf("\n");*/

	/*printf("\n-----在图G中插入顶点x-----\n");
	x = 'G';
	printf("插入顶点%c", x);
	printf("插入成功了吗？— %d(1表示成功，0表示失败)\n", InsertVertex(G, x));
	PrintG(G);
	Info(G);
	printf("无向图G中共有：%d个顶点，%d条边\n", G.vexnum, G.edgenum);
	PrintMatrix(G);*/

	/*printf("\n-----在图G中删除顶点x-----\n");
	x = 'C';
	printf("删除顶点%c\n", x);
	printf("删除成功了吗？(1表示成功, 0表示失败)— %d\n", DeleteVertex(G, x));
	printf("输出无向图G中各顶点的连接情况: \n");
	PrintG(G);
	printf("\n");
	Info(G);
	printf("\n无向图G中共有: %d个顶点, %d条边\n", G.vexnum, G.edgenum);
	PrintMatrix(G);*/

	/*printf("\n-----图G中添加无向边(x, y)-----\n");
	x = 'E', y = 'F';
	printf("在顶点%c与顶点%c之间添加一条无向边\n", x, y);
	printf("添加成功了吗？— %d(1代表成功，原图中没有边(x, y)，0代表失败，原图中已存在该边或者顶点x/顶点y不存在)\n", AddEdge(G, x, y));
	printf("\n");
	PrintMatrix(G);

	printf("输出无向图G中各顶点的连接情况：\n");
	PrintG(G);
	printf("\n");*/

	/*printf("\n-----删除图G中无向边(x, y)-----\n");
	x = 'B', y = 'F';
	printf("删除(若存在)顶点%c与顶点%c之间的一条无向边\n", x, y);
	printf("删除成功了吗？— %d(1代表成功，原图中有边(x, y)，0代表失败，原图中不存在该边或者顶点x/顶点y不存在)\n", RemoveEdge(G, x, y));
	printf("\n");
	PrintMatrix(G);

	printf("输出无向图G中各顶点的连接情况：\n");
	PrintG(G);
	printf("\n");*/

	/*printf("\n-----求图G中顶点x的第一个邻接点-----\n");
	x = 'E';
	printf("图G中顶点%c的第一个邻接点的顶点号为：%d(-1代表x没有邻接点或图中不存在x)\n", x,FirstNeighbor(G,x));*/

	/*printf("\n-----求图G中除y之外顶点x的下一个邻接点的顶点号-----\n");
	x = 'B', y = 'E';
	printf("图G中除顶点%c之外顶点%c的下一个邻接点的顶点号为：%d(-1代表x没有邻接点或图中不存在x)\n", x, y, NextNeighbor(G, x, y));*/

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

无向图G中共有: 6个顶点, 7条边
输出邻接矩阵：
        A       B       C       D       E       F      
A       0       1       1       1       0       0      
B       1       0       0       0       1       1      
C       1       0       0       0       1       0      
D       1       0       0       0       0       1      
E       0       1       1       0       0       0      
F       0       1       0       1       0       0   

输出无向图G中各顶点的连接情况:
A->B            A->C            A->D
B->A            B->E            B->F
C->A            C->E
D->A            D->F
E->B            E->C
F->B            F->D
*/