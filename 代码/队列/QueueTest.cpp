#include "Queue.h"
#include <iostream>

using namespace std;

void test01() {
  SqQueue Q;
  // 初始化
  Queue_Init(Q);
  for (int i = 0; i < 5; i++) {
    // 入队五个
    Queue_Push_Back(Q, i);
  }
  cout << Q.length << endl;
  //   出队五个
  for (int i = 0; i < 5; i++) {
    Queue_Pop_Back(Q, i);
  }
  cout << Q.length << endl;
}

int main() {
  test01();
  return 0;
}