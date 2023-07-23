#include "status.h"
#include <array>
#include <iostream>

using namespace std;
typedef struct {
  int weight;
  int parent, lch, rch;
} HTNode, *HuffmanTree;

// 找出一个最小值，返回其下标位置
int SelectSingle(HuffmanTree HT, int n) {
  int MIN_weight{HT[1].weight};
  int s = 1;
  for (int i = 1; i < n; i++) {
    // 双亲域为零的节点
    if (HT[i].parent == 0) {
      if (HT[i].weight <= MIN_weight) {
        MIN_weight = HT[i].weight;
        s = i;
      }
    }
  }
  return s;
}

void CreateHuffmanTree(HuffmanTree HT, int n) {
  if (n <= 1) {
    return;
  }
  int m = 2 * n - 1;
  HT = new HTNode[m + 1]; // 0号节点不使用，HT[m]为根节点
  for (int i = 1; i <= m; ++i) {
    HT[i].lch = 0;
    HT[i].rch = 0;
    HT[i].parent = 0;
  }
  for (int i = 1; i <= n; ++i) {
    // 输入前n个的权重
    cin >> HT[i].weight;
  }

  for (int i = n + 1; i < m; i++) {
    int s1{};
    int s2{};
    s1 = SelectSingle(HT, i - 1); //找1个双亲域为零，且权值最小的节点；、

    // 相当于从森林中删除这颗树
    HT[s1].parent = i;
    
    s2 = SelectSingle(HT, i - 1);//在找一个

    // 相当于从森林中删除这颗树
    HT[s2].parent = i;

    // 新树的左子树和右子树
    HT[i].lch = s1;
    HT[i].rch = s2;
    // 新数权重为子树相加
    HT[i].weight = HT[s1].weight + HT[s2].weight;
  }
}
int main() { return 0; }