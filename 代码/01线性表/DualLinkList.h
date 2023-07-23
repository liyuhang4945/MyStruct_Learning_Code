#include"status.h"
#include<iostream>
typedef struct DualNode
{
    
    ElemType data;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode,*DualLinkList;

Status ListInsert_Dual(DualLinkList&L,int i,ElemType e){
    // DualLinkList p =(L,i);
    DualLinkList p;
    if( p == NULL){
        return ERROR;
    }
    DualNode* s = new DualNode;
    s->data = e;

    p->prior->next = s;
    s->prior=p->prior;

    s->next = p;
    p->prior = s;

    return OK;

    
}

Status ListDelete_Dual(DualLinkList&L,int i,ElemType e){
// 待删除的结点
    DualNode* p;

    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
}