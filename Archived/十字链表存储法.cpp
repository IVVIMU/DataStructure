#include <stdio.h>
#include <malloc.h>

#define  MAX_VERTEX_NUM 20
#define  InfoType int//图中弧包含信息的数据类型
#define  VertexType int
typedef struct ArcBox{
    int tailvex,headvex;//弧尾、弧头对应顶点在数组中的位置下标
    struct ArcBox *hlik,*tlink;//分别指向弧头相同和弧尾相同的下一个弧
    InfoType *info;//存储弧相关信息的指针
}ArcBox;
typedef struct VexNode{
    VertexType data;//顶点的数据域
    ArcBox *firstin,*firstout;//指向以该顶点为弧头和弧尾的链表首个结点
}VexNode;
typedef struct {
    VexNode xlist[MAX_VERTEX_NUM];//存储顶点的一维数组
    int vexnum,arcnum;//记录图的顶点数和弧数
}OLGraph;
int LocateVex(OLGraph * G,VertexType v){
    int i=0;
    //遍历一维数组，找到变量v
    for (; i<G->vexnum; i++) {
        if (G->xlist[i].data==v) {
            break;
        }
    }
    //如果找不到，输出提示语句，返回 -1
    if (i>G->vexnum) {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}
//构建十字链表函数
void CreateDG(OLGraph *G){
    printf("输入有向图的顶点数和弧数（用英文逗号隔开）：\n");
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    //使用一维数组存储顶点数据，初始化指针域为NULL
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->xlist[i].data));
        G->xlist[i].firstin=NULL;
        G->xlist[i].firstout=NULL;
    }
    //构建十字链表
    for (int k=0;k<G->arcnum; k++) {
        int v1,v2;
        printf("输入第%d个弧的两个顶点 ",k);
        scanf("%d,%d",&v1,&v2);
        //确定v1、v2在数组中的位置下标
        int i=LocateVex(G, v1);
        int j=LocateVex(G, v2);
        //建立弧的结点
        ArcBox * p=(ArcBox*)malloc(sizeof(ArcBox));
        p->tailvex=i;
        p->headvex=j;
        //采用头插法插入新的p结点
        p->hlik=G->xlist[j].firstin;
        p->tlink=G->xlist[i].firstout;
        G->xlist[j].firstin=G->xlist[i].firstout=p;
    }
}

int visited[100] = {0};

//出弧遍历
void showOut(OLGraph &G,int n) {
    int a = LocateVex(&G,n);
    printf("遍历出：%d\n",n);
    visited[a] = 1;
    ArcBox *p = (ArcBox*)malloc(sizeof(ArcBox));
    p = G.xlist[a].firstout;
    int w;
    while(p != NULL) {
        w = p->tailvex;
        printf("%d  ",G.xlist[p->headvex].data);      //遍历某条弧的头
        printf("%d",G.xlist[p->tailvex].data);           //遍历某条弧的尾
        if(visited[w] == 0) {
            showOut(G,G.xlist[w].data);
        }
        p = p->hlik;
    }
}

//入弧遍历
void showIn(OLGraph &G,int n) {
    int a = LocateVex(&G,n);
    printf("遍历出：%d\n",n);
    visited[a] = 1;
    ArcBox *p = (ArcBox*)malloc(sizeof(ArcBox));
    p = G.xlist[a].firstin;
    int w;
    while(p != NULL) {
        w = p->headvex;
        printf("%d  ",G.xlist[p->headvex].data);   //遍历某条弧的头
        printf("%d",G.xlist[p->tailvex].data);        //遍历某条弧的尾
        if(visited[w]==0) {
            showIn(G,G.xlist[w].data);
        }
        p = p->tlink;
    }
}

int main() {
  OLGraph *G = (OLGraph*)malloc(sizeof(OLGraph));
  CreateDG(G);
  printf("从哪个数开始遍历：");
  int a;
  scanf("%d",&a);
  int m = LocateVex(G,a);
  ArcBox *p = (ArcBox*)malloc(sizeof(ArcBox));
  p = G->xlist[a].firstout;
  if(!p) {
      showOut(*G,a);
  }else {
      showIn(*G,a);
  }
}