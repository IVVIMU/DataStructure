#include <iostream>
#include <tchar.h>
using namespace std;

//邻接表的边结点类型
typedef struct edge {
    int adjvex;        //该边的终止顶点在顶点数组中的位置
    int weight;       //该边的权值
    edge * next;    //指向下一个边结点
}ELink;

//邻接表的顶点类型
typedef struct ver {
    int vertex;     //顶点的数据类型
    ELink * link;  //指向第一条边对应的边结点
}VLink;



void insertElement(VLink * G,int pos,ELink * p) {
    ELink *q;
	if (G[pos].link == NULL)	{
		G[pos].link = p;
	}
	else {
		q = G[pos].link;
		while(q->next) {
			q = q->next;
		}
		q->next = p;
	}
}

void createAdjacencyList(VLink * G,int n,int e) {
    int VInfo;    //邻接表的数据信息
    int vi,vj,weight;   //边结点与权值
    ELink *pFirst,*pLast;
    cout << "请按顺序输入邻接表顶点的数据信息：" << endl;
    for(int i=0;i<n;i++) {
        cout << "请输入第" << i+1 << "个顶点的数据信息：" << endl;
        cin >> VInfo;
        G[i].vertex = VInfo;
        G[i].link = NULL;
    }

    cout << "请输入邻接表边结点的数据信息（输入顺序：连接点1的位置编号，连接点2的位置编号，权值）：" << endl;
	for(int i=0; i<e; i++) {	//输入边的信息
		cout << "请输入第" << i+1 << "条边的数据信息：" << endl;
		cin >> vi >> vj >> weight;
		pFirst = new ELink;
		pFirst->adjvex = vj;
		pFirst->weight = weight;
		pFirst->next = NULL;
		pLast = new ELink;
		pLast->adjvex = vi;
		pLast->weight = weight;
		pLast->next = NULL;
		insertElement(G, vi, pFirst); //该函数用来将边信息pFirst链接在顶点数组G的第vi个顶点后面
		insertElement(G, vj, pLast);
	}

}

void printAdjacentcyList( VLink* G, int n ) 
{
	cout << "打印邻接表信息如下：" << endl;
	ELink* p;
	for(int i=0; i<n; i++) {
		cout << G[i].vertex;
		p = G[i].link;
		while (p) {
			cout << "---->" << p->adjvex << "|" << p->weight;
			p = p->next;
		}
		cout << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n, e;
	cout << "请输入图的顶点数：" << endl;
	cin >> n;
	cout << "请输入图的边数：" << endl;
	cin >> e;

	VLink* G = new VLink[n];
	createAdjacencyList(G, n, e);
	printAdjacentcyList(G, n);
	delete G;

	return 0;
}

// 请输入图的顶点数：
// 5
// 请输入图的边数：
// 5
// 请按顺序输入邻接表顶点的数据信息：
// 请输入第1个顶点的数据信息：
// 1
// 请输入第2个顶点的数据信息：
// 2
// 请输入第3个顶点的数据信息：
// 3
// 请输入第4个顶点的数据信息：
// 4
// 请输入第5个顶点的数据信息：
// 5
// 请输入邻接表边结点的数据信息（输入顺序：连接点1的位置编号，连接点2的位置编号，权值）：
// 请输入第1条边的数据信息：
// 0 1 3
// 请输入第2条边的数据信息：
// 1 2 4
// 请输入第3条边的数据信息：
// 2 3 9
// 请输入第4条边的数据信息：
// 3 4 6
// 请输入第5条边的数据信息：
// 0 4 2
// 打印邻接表信息如下：
// 1---->1|3---->4|2
// 2---->0|3---->2|4
// 3---->1|4---->3|9
// 4---->2|9---->4|6
// 5---->3|6---->0|2
