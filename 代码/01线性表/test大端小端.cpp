#include <iostream>
using namespace std;

int main() {

  int i = 1;
  int *p = &i;
  char *c = (char *)p;
  cout << " i " << (int)(*c) << endl;
  return 0;
}