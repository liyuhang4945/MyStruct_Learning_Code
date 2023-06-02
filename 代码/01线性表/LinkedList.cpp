#include "../status.h"
#include <iostream>

typedef struct Lnode {
  ElemType data;
  struct Lnode *next;
} LNode, *LinkList;

Status InitList_L(LinkList &L) {
  if (L != NULL) {
    L = new LNode;
    L->next = NULL;
    return OK;
  } else {
    return ERROR;
  }
}

// 判断链表是否为空 空表返回 1 非空返回零
Status ListEmpty(LinkList &L) {
  if (L->next == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// 单链表的销毁
void DestroyList(LinkList &L) {
  LNode *p;
  while (L != NULL) {
    p = L;
    L = L->next;
    delete p;
  }
}

// 清空

Status ClearList(LinkList &L) {
  LNode *q;
  Lnode *p = L->next;
  while (p != NULL) {
    q = p;
    p = p->next;
    delete q;
  }
  L->next = NULL;

  return OK;
}

// 获取链表中元素个数
int Get_List_Length(LinkList &L) {
    // 首元结点
    Lnode* p=L->next;
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}
