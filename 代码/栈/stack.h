#pragma once
#include "status.h"
#include <iostream>

typedef struct stack {
  ElemType *data;
  int length;
  int capacity;
} Stack;

Status St_Init(Stack *&st, int size) {
  if (st == NULL || size < 0) {
    return ERROR;
  }
  // 初始化内存空间
  st->data = new ElemType[size];
  st->length = 0;
  st->capacity = size;
}
Status St_Push_Back(Stack *&st, ElemType &e) {
  if (st == NULL || st->length > st->capacity) {
    return ERROR;
  }
  st->data[st->length] = e;
  (st->length)++;
  return OK;
}

Status St_Pop_Back(Stack *&st, ElemType &e) {
  if (st == NULL||st->length > st->capacity) {
    return ERROR;
  }
  st->data[st->length] = e;
  (st->length)--;
  return OK;
}
