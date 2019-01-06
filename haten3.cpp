#include <iostream>
using namespace std;

void exchange(int &x, int &y){
  int z;
  z = x;
  x = y;
  y = z;
}

int main(){
  int x = 2;
  int y = 3;
  cout << "x=" << x << "  y=" << y << "\n";
  exchange(x,y);
  cout << "x=" << x << "  y=" << y << "\n";
}
