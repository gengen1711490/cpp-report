#include <iostream>
using namespace std;

class hm{
public:
  int hour;
  int minute;
};

class person{
public:
  string name;
};

class ticket{
public:
  int id;
  person* user;
  ticket(){user = new person;}
};

class transTicket : public ticket{
public:
  string origin;
  string destination;
  transTicket(): ticket(){};
};

class trainTicket : public transTicket{
public:
  hm departureTime;
  hm arrivalTime;
  trainTicket(): transTicket(){};
};

int main(){
  int ticketNum;
  cout << "チケットを何枚購入しますか？ ";
  cin >> ticketNum;
  cout << "\n";
  trainTicket* tickets = new trainTicket [ticketNum];
  for(int i = 0; i < ticketNum; i++){
    tickets[i].id = i+1;
    cout << i+1 << "人目の利用者の名前を入力してください: ";
    cin >> tickets[i].user->name;
    cout << "  出発地を入力してください: ";
    cin >> tickets[i].origin;
    cout << "  到着地を入力してください: ";
    cin >> tickets[i].destination;
  }
  cout << "\n\nチケット利用者一覧：\n";
  for(int i = 0; i < ticketNum; i++){
    trainTicket t = tickets[i];
    cout << " " << t.id << " : " << t.user->name << "  " << t.origin << " => " << t.destination << "\n";
    cout << "\n";
  }
  cout << "\n";
}
