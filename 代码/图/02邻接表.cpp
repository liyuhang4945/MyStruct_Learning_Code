#include <iostream>
#include <status.h>

#define MAXInt 32767;
typedef int VerTextype; //顶点的类型

#define MVNum 100 //最大顶点数
typedef int OtherInfo;
typedef struct ArcNode {
  int adjvex;              //顶点的位置
  struct ArcNode *nextarc; //下一条边的指针
  OtherInfo info;          //和边有关的信息
} ArcNode;
typedef struct VNode {
  VerTextype data;   //顶点的信息
  ArcNode *firstarc; //顶点边的指针
} VNode, AdjList[MVNum];

// 图的定义
typedef struct {
  AdjList vertices;
  int vexnum;
  int arcnum; //顶点数和弧数
} ALGraph;

// 从从邻接表中定位顶点位置
int LocateVex(ALGraph &G, int v) { return OK; }
Status CreateUDG(ALGraph &G) {
  //输入总顶点数和总边数
  std::cin >> G.vexnum >> G.arcnum;
  for (int i = 0; i < G.vexnum; i++) {
    // 输入各顶点的值
    std::cin >> G.vertices[i].data;
    G.vertices[i].firstarc = NULL; //初始化头节点的指针域
  }
  //   输入边,构造邻接表
  for (int k = 0; k < G.arcnum; k++) {
    int v1, v2;
    std::cin >> v1 >> v2;
    // 从邻接表中定位v1顶点位置
    int i = LocateVex(G, v1);
    int j = LocateVex(G, v2);

    // 生成边节点
    ArcNode *p1 = new ArcNode;
    p1->adjvex = j; //顶点位置为v2
    // 采用头插法将节点插入vi的边表
    p1->nextarc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = p1;
    // 生成边节点,插入一个对称的位置
    ArcNode *p2 = new ArcNode;
    p2->adjvex = i; //顶点位置为v1
    // 采用头插法将节点插入vj的边表
    p2->nextarc = G.vertices[j].firstarc;
    G.vertices[j].firstarc = p2;
  }

  return OK;
}