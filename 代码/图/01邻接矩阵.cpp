#include <iostream>
#include <status.h>
#define MAXInt 32767;
using namespace std;
typedef int VetTextype; //顶点的类型
typedef int ArcType;    //边的权值类型
#define MVNum 100       //最大顶点数
typedef struct {
  VetTextype vexs[MVNum];     //顶点表
  ArcType arcs[MVNum][MVNum]; //邻接矩阵
  int vexnum;
  int arcnum;
} AMGraph;
// 在邻阶矩阵中定位顶点的位置
int LocateVex(AMGraph &G, int v) { return 0; }
Status CreateUDN(AMGraph &AMG) {
  // 輸入总顶点数，总边数
  cin >> AMG.vexnum;
  cin >> AMG.arcnum;
  for (int i = 0; i < AMG.vexnum; ++i) {
    cin >> AMG.vexs[i]; //输入点，
  }
  // 初始化邻接矩阵
  for (int i = 0; i < AMG.vexnum; i++) {
    for (int j = 0; j < AMG.vexnum; j++) {
      AMG.arcs[i][j] = MAXInt; //边的权值设为最大值
    }
  }

  for (int k = 0; k < AMG.arcnum; k++) {
    VetTextype v1, v2; //顶点
    ArcType w;         //权值
    int i, j;
    cin >> v1 >> v2 >> w;
    i = LocateVex(AMG, v1);
    j = LocateVex(AMG, v2); //确定顶点位置
    AMG.arcs[i][j] = w;
    AMG.arcs[j][i] = AMG.arcs[i][j];
    // 置<v1,v2>的权值为w
    // 置对称边<v2,v1>的权值为w
  }
  return OK;
}