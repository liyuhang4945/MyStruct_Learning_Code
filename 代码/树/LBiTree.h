#include "status.h"

#include <iostream>

typedef struct BiNode {
  /* data */
  ElemType data;
  BiNode *L_child, *R_child;
} BiNode, *BiTree;
// 三叉链表
typedef struct TriTNode {
  /* data */
  ElemType data;
  BiNode *L_child, *R_child, *parent;
} TriNode, *TriTree;

void visit(BiTree T) { std::cout << T->data << std::endl; }
// 先序遍历
Status PreOrderTraverse(BiTree T) {
  if (T == nullptr) {
    // 空二叉树
    return OK;
  } else {
    visit(T);
    // 递归遍历左子树
    PreOrderTraverse(T->L_child);
    // 递归遍历右子树
    PreOrderTraverse(T->R_child);
  }
}
// 中序遍历
Status InOrderTraverse(BiTree T) {
  if (T == nullptr) {
    // 空二叉树
    return OK;
  } else {

    // 递归遍历左子树
    PreOrderTraverse(T->L_child);
    visit(T);
    // 递归遍历右子树
    PreOrderTraverse(T->R_child);
  }
}
// 后序遍历
Status RearOrderTraverse(BiTree T) {
  if (T == nullptr) {
    // 空二叉树
    return OK;
  } else {

    // 递归遍历左子树
    PreOrderTraverse(T->L_child);
    // 递归遍历右子树
    PreOrderTraverse(T->R_child);
    visit(T);
  }
}

// 非递归调用
// 中序遍历非递归
// Status InOrder(BiTree T) {
//     BiTree p = T;
//     InitStack(S);
//     while (p||StackEmpty(S)!=NULL)
//     {
//         if(p!=nullptr){
//             Push(S,p);
//             p = p->L_child;
//         }else{
//             Pop(S,q);
//             // cout<<q.data<<endl;
//             // p = q.rchild;
//         }
//     }
//     return OK;

// }

// 层次遍历
// 通过一个队列，首先将根节点入队，开始循环，每次出队一个，如果该节点有左右孩子，则将其入队，
// typedef struct{
//     BiNode data[100];
//     int front,rear;
// }SqQueue;
// Status LevelOrder(BiNode *b){
//     BiNode* p;//临时指针
//     SqQueue *qu;//辅助队列
//     InitQueue(qu);//初始化队列
//     enQueue(qu,b);//入队 根节点
//     while (QueueEmpty(qu)!=NULL)// 队列不为空
//     {
//         deQueue(qu,p);//出队，
//         visit(p);//访问元素
//         // 若左子树不为空，入队
//         if(p->L_child!=nullptr){
//             enQueue(qu,p->L_child);
//         }
//         // 若右子树不为空，入队
//         if(p->R_child!=nullptr){
//             enQueue(qu,p->R_child);
//         }
//     }

// }

// 先序建立二叉树,abc##De#G##F### ＃代表空节点
Status CreateBiTree(BiTree &T) {
  //   cin >> ch;
  char ch;
  if (ch == '#') {
    T = NULL;
  } else {
    T = new BiNode;
    if (T == NULL) {
      exit(MyOVERFLOW);
    }
    T->data = ch;
    // 构造左子树
    CreateBiTree(T->L_child);
    CreateBiTree(T->R_child);
  }
}

// 复制二叉树
int Copy(BiTree T, BiTree &NewT) {
  // 空树返回，
  if (T == NULL) {
    NewT = NULL;
    return 0;
  } else {
    NewT = new BiNode;
    NewT->data = T->data;
    Copy(T->L_child, NewT->L_child);
    Copy(T->R_child, NewT->R_child);
  }
}

// 深度计算
// 空树，深度为零。左子树深度记为m，右子树记为n，深度为MAX{M，N}
int Depth(BiTree T) {
  if (T == NULL) {
    return 0;
  } else {
    int m = Depth(T->L_child);
    int n = Depth(T->R_child);
    if (m > n) {
      return (m + 1);
    } else {
      return (n + 1);
    }
  }
}

// 节点总数
int NodeCount(BiTree T) {
  if (T == NULL) {
    return 0;
  } else {
    return NodeCount(T->L_child) + NodeCount(T->R_child) + 1;
  }
}
// 叶子节点
int LeadCount(BiTree T) {
  if (T == NULL) {
    return 0;
  }
  if (T->L_child == NULL && T->R_child == NULL) {
    return 1;
  } else {
    return LeadCount(T->L_child) + LeadCount(T->R_child);
  }
}