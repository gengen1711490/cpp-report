#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(){
  ofstream fout("test.txt");
  if (!fout){
      cout << "出力ファイルが開けません";
      return 1;
  }
  for (int c = 0; c < 5; c++){
    fout << c << "\n";
  }
  fout.close();
  ifstream fin("test.txt");

  if (!fin){
    cout << "入力ファイルが開けません";
    return 1;
  }

  int k = 0;
  while (!fin.eof()){
    string str;
    fin >> str;
    cout << "line " << k << ": " << str << "\n";
    k++;
  }
  fin.close();
  return 0;
}
