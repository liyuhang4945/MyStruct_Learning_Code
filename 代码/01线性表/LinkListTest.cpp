#include "./LinkedList.h"
#include <iostream>

using namespace std;
void testDelete() {
  LinkList L;
  InitList_L(L);
  for (int i = 0; i < 10; i++) {
    List_Push_front(L, i);
  }
  ElemType e = 0;
  ListDelete_L(L, 2, e);
  for (int i = 0; i < 9; i++) {
    int j = 0;
    List_pop_front(L, j);
    cout << j << " ";
  }
}
int main() {

  // LinkList L;
  // InitList_L(L);
  // for (int i = 0; i < 10; i++) {
  //   List_Push_front(L, i);
  // }
  // // int t = 100;
  // // Insert_By_Count(L, 1, t);
  // for (int i = 0; i < Get_List_Length(L); i++) {
  //   ElemType temp = 0;
  //   Get_Elem_By_Count(L, i + 1, temp);
  //   cout << temp << " ";
  //   // Lnode *p = Get_Elem_By_Value(L, i);
  //   // cout << p->data << endl;
  // }
  // }
  // cout << Get_List_Length(L) << endl;
  // cout << Get_List_Length(L) << endl;
  // int count = Get_List_Length(L);
  // for (int i = 0; i < count; i++) {
  //   int t = 0;
  //   List_pop_front(L, t);
  //   cout << t << " ";
  // }
  testDelete();
  return 0;
}
