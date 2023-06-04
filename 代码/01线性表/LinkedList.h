#include "../status.h"
#include <iostream>

// 类型定义
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

// 插入  头插法
Status List_Push_front(LinkList &L, ElemType &e) {
  Lnode *p = new Lnode;
  if (p == NULL) {
    return ERROR;
  }
  p->data = e;
  p->next = L->next;
  L->next = p;
  return OK;
}
Status List_pop_front(LinkList &L, ElemType &e) {
 
  if (L->next == NULL) {
    return ERROR;
  }
   Lnode *p = L->next;
  //  std::cout<<L->next->data<<" ";
  L->next = L->next->next;
  e = p->data;
  delete p;
  p=NULL;
  return OK;
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
  Lnode *p = L->next;
  int count = 0;
  while (p != NULL) {
    count++;
    p = p->next;
  }
  return count;
}
// 取第i个位置的地址
Lnode *Get_ElemArr_By_Count(LinkList &L, int i) {
  Lnode *p = L->next;
  int j = 1;
  while (p != NULL && j != i) {
    p = p->next;
    ++j;
  }
  // 当指针为空 或者i值小于1 或者大于表长时
  if (p == NULL || j > i) {
    return NULL;
  } else {
    return p;
  }
}

// 取值,取第i个的值
Status Get_Elem_By_Count(LinkList &L, int i, ElemType &e) {
  // Lnode *p = L->next;
  // int j = 1;
  // // 初始化

  // while (p != NULL && j < i) {
  //   p = p->next;
  //   ++j;
  // }
  // // 第i个元素不存在
  // if (p == NULL || j > i) {
  //   return ERROR;
  // } else {
  //   e = p->data;
  //   return OK;
  Lnode *p = Get_ElemArr_By_Count(L, i);
  if (p != NULL) {
    e = p->data;
    return OK;
  } else {
    return ERROR;
  }
}

// 按值查找  返回地址
Lnode *Get_Elem_By_Value(LinkList &L, ElemType &e) {

  Lnode *p = L->next;
  int j = 1;
  // while (p != NULL) {
  //   if (p->data==e)
  //   {
  //     return p;
  //   }
  //   ++j;
  // }
  // return NULL;
  //  p不为空且p指向的值不等于所需的值时查找下一个
  while (p != NULL && p->data != e) {
    p = p->next;
  }
  return p;
}

// 插入 在第i个结点前插入值为e的新结点
Status Insert_By_Count(LinkList &L, int i, ElemType &e) {
  Lnode *p = L->next;
  int j = 1;

  // 找到第i-1的结点  如果j=0,j<i-1
  while (p != NULL && j < i) {
    p = p->next;
    ++j;
  }
  // 指针为空 或i大于表长或小于1 插入位置非法
  if (p == NULL || j > i) {
    return ERROR;
  } else {
    Lnode *s = new Lnode;
    s->data = e;
    // 结点插入
    s->next = p->next;
    p->next = s;
    return OK;
  }
}