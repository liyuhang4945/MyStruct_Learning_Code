#include "status.h"
#include <iostream>

#define MAXQSIZE 100

// 结点指针
typedef struct Qnode {
  ElemType data;
  Qnode *next;
} Qnode, *QueuePtr;

// 队列指针
typedef struct LinkQueue {
  QueuePtr front;
  QueuePtr rear;
  int length;
} LinkQueue;

// 初始化
Status InitQueue(LinkQueue &Q) {
  Q.front = Q.rear = new Qnode;
  if (Q.front == NULL) {
    exit(MyOVERFLOW);
  }
  Q.front->next = NULL;
  Q.length = 0;
  return OK;
}

// 入队
Status Queue_Push_back(LinkQueue &Q, ElemType e) {
  // 申请结点
  Qnode *node = new Qnode;
  if (node == NULL) {
    exit(MyOVERFLOW);
  }
  node->data = e;
  node->next = NULL;

  // 链接结点
  Q.rear->next = node;

  // 尾指针移动，指向最后一个结点
  Q.rear = node;
  //   链队长度+1
  Q.length++;

  return OK;
}
// 出队
Status Queue_pop_back(LinkQueue &Q, ElemType &e) {
  if (Q.front == Q.rear) {
    return ERROR;
  }
  //   临时结点
  Qnode *node = Q.front->next;
  e = node->data;
  //   头指针偏移
  Q.front->next = node->next;
  delete node;
  //   链队长度-1
  Q.length--;
  return OK;
}

// 销毁链队列

Status DestroyQueue(LinkQueue &Q) {
  Qnode *temp;
  while (Q.front != NULL) {
    temp = Q.front->next;
    delete Q.front;
    Q.front = temp;
  }
  Q.length = 0;
}

// 获取队头元素

Status Link_Queue_GetHead(LinkQueue &Q, ElemType &e) {
  if (Q.front == NULL) {
    exit(MyOVERFLOW);
  }
  e = Q.front->next->data;
  return OK;
}