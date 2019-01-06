#include <iostream>
using namespace std;

class bookshelf(){
  string top;
  string middle;
  string bottom;
  string& getShelf(string destination);

}




int main(){
  bookshelf bs;
  string name, time;
  cout << "  本の名前を入力してください: ";
  cin >> name;
  cout << "  その本をいつ読みますか（すぐ読む・後で読む・積ん読） ";
  cout << "  ー＞ ";
  cin >> time;


  cout << name << " : " << time << '\n';



}
