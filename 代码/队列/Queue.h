#include "iostream"
#include "../status.h"

const int MAXSIZE = 10;
// 顺序队列
typedef struct Queue {
  ElemType *base; // 动态分配
  int front;      // 头指针 指向头元素
  int rear;
  int length; // 元素个数
} SqQueue;

// q.rear= (q.rear+1)%MAXSIZE;

Status Queue_Init(SqQueue &Q) {
  // 分配空间
  // malloc(MAXSIZE*(sizeof(ElemType)));
  Q.base = new ElemType[MAXSIZE];
  if (Q.base == nullptr) {
    exit(MyOVERFLOW);
  }
  //   头尾指针置空，值为零 元素个数置空
  Q.front = 0;
  Q.rear = 0;
  Q.length = 0;
  return OK;
}

int Queue_Get_Length(SqQueue &Q) {
  return Q.length;
  // (Q.rear-Q.front+MAXSIZE) % MAXSIZE;
}

bool Queue_Empty(SqQueue &Q) {
  if (Q.length == 0) {
    return true;
  }
  return false;
}
bool Queue_Full(SqQueue &Q) {
  if (Q.length == MAXSIZE) {
    return true;
  }
  return false;
}


//入栈
Status Queue_Push_Back(SqQueue &Q, ElemType e) {
  // 队满 if(Queue_Full == true)
  if ((Q.rear + 1) % MAXSIZE == Q.front) {
    return ERROR;
  }
  // 入队
  Q.base[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MAXSIZE;
  Q.length++;
  return OK;
}


// 出栈
Status Queue_Pop_Back(SqQueue &Q, ElemType &e) {
  // 队满 if(Queue_empty == true)
  if (Q.rear == Q.front) {
    return ERROR;
  }
  // 出队  保存队头元素，队列长度减一
  e = Q.base[Q.front];
  Q.front = (Q.front + 1) % MAXSIZE;
  Q.length--;
  return OK;
}

ElemType Queue_Get_Front(SqQueue &Q) {
    // 队列不为空，返回对头指针元素
  if (Q.front != Q.rear) {
    return Q.base[Q.front];
  }
  return NULL;
}