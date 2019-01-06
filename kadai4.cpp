#include <iostream>
using namespace std;

class person{
public:
  string address;
  string name;
  person(){name = ""; address = "";};
};

class addressbook{
  int maximumFriends = 100;
  int numberOfFriends;
public:
  person* friends;
  addressbook(){
    friends = new person [maximumFriends];
    numberOfFriends = 0;
  };
  void listFriends();
  void addFriend(string n);
  void addFriend(string n, string a);
  person find(string query);
};

void addressbook::addFriend(string n, string a){
  friends[numberOfFriends].name = n;
  friends[numberOfFriends].address = a;
  numberOfFriends++;
}

void addressbook::listFriends(){
  for(int i = 0; i < numberOfFriends; i++){
    cout << friends[i].name << ":" << friends[i].address << "\n";
  }
}


person addressbook::find(string query){
  for(int i=0; i<numberOfFriends; i++){
    if(friends[i].name == query){
      return friends[i];
    }else{
      person no_one;
      return no_one;
    }
  }
}

int main(){
  addressbook abook;
  string name, address, query;
  person found;
  while(1){
    cout << "登録する名前を入力してください（終了するにはquitと入力してください）\n";
    cin >> name;
    if(name == "quit"){break;}
    cout << "登録する住所を入力してください\n";
    cin >> address;
    abook.addFriend(name,address);
  }

  cout << "\nリストを表示します\n";
  abook.listFriends();

  cout << "\n探したい人の名前を入れてください\n";
  cin >> query;
  found = abook.find(query);
  cout << "\n" << found.name << "の住所は" << found.address << "です。\n";
  delete[] abook.friends;
}
