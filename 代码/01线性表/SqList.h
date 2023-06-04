#include <iostream>
// 包含常用预定义常量和类型
#include "../status.h"
// 两种定义常量方式，cpp推荐使用第二种
// #define SIZE 100
const int SIZE = 100;
// 顺序表结构
typedef struct {
  // 数组形式 无需初始化
  //  ElemType data[SIZE];
  //  指针形式，需要动态初始化变量大小 = new ElemType[Size];
  ElemType *data;
  int length;
} SqList;

// 初始化顺序表
void init_List(SqList &L) {
  L.data = new ElemType[SIZE];
  // 如果申请空间失败，报错且退出程序
  if (L.data == nullptr) // 或者NULL
  {
    exit(MyOVERFLOW);
  }
  L.length = 0;
}

void DestroyList(SqList &L) {
  delete[] L.data;
  L.data = nullptr;
  L.length = 0;
}
// 清空线性表
void ClearList(SqList &L) { L.length = 0; }
// 尾插法插入数据
void push_back(SqList &L, ElemType &e) {
  if (L.length > (SIZE - 1)) {
    std::cout << "OVERFLOW" << std::endl;
  } else {
    L.data[L.length] = e;
    L.length++;
  }
}

bool ListEmpty(SqList &L) {
  if (L.length == 0) {
    return true;
  } else {
    return false;
  }
}
int ListLength(SqList &L) { return L.length; }

Status List_Insert_Sq(SqList &L, int i, ElemType e) {
  if (i < 1 || i > L.length + 1) {
    return ERROR; // 不合法的I值
  }
  // 当前空间已满
  if (L.length == SIZE) {
    return ERROR;
  }

  for (int j = L.length - 1; j >= i - 1; j--) {
    L.data[j + 1] = L.data[j]; // 插入位置及之后的元素后移
  }

  L.data[i - 1] = e;
  L.length++;
  return OK;
}
int main() {
  // 创建变量
  SqList Sq;
  init_List(Sq);
  //     Test
  //   std::cout << Sq.length << std::endl;
  //   std::cout << ListEmpty(Sq) << std::endl;

  //   for (int i = 0; i < SIZE; i++) {
  //     push_back(Sq, i);
  //   }
  //   std::cout<<Sq.data[99]<<std::endl;
  DestroyList(Sq);
  //   std::cout << (int *)Sq.data << std::endl;
  return 0;
}