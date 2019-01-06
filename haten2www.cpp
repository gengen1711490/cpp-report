//hmの使い方がわからない
#include <stdio.h>
#include <iostream>
using namespace std;


class hm{
public:
  int Mi;
  hm(int tI);
  int hour;
  int minute;
  int inMinute();
  int timeInminute;
  int a_hour;
  int a_minute;
};

hm::hm(int tI){
  int h = 0;
  while (tI >= 60) {
    tI = tI-60;
    h ++;
  };
  a_hour = h;
  a_minute = tI;
};

int hm::inMinute(){
  timeInminute = hour*60 + minute;
  return timeInminute;
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
  hm* departureTime;
  hm* arrivalTime;
//  int *sum_departureTime = departureTime->inMinute();
//  int *sum_arrivalTime = arrivalTime->inMinute();
//  cout << departureTime->inMinute() << '\n';

  trainTicket(): transTicket(){
    departureTime = new hm();
    arrivalTime = new hm();
  };
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
    cout << "  出発時刻を入力してください（例：00:00）: ";
    scanf("%d:%d", &(tickets[i].departureTime->hour), &(tickets[i].departureTime->minute));
    cout << "  到着地を入力してください: ";
    cin >> tickets[i].destination;
    cout << "  到着時刻を入力してください（例：00:00）: ";
    scanf("%d:%d", &(tickets[i].arrivalTime->hour), &(tickets[i].arrivalTime->minute));
  }
  cout << "\n\nチケット利用者一覧：\n";
  for(int i = 0; i < ticketNum; i++){
    trainTicket t = tickets[i];

    cout << " " << t.id << " : " << t.user->name << "  " ;
    cout << t.origin << "  " << t.departureTime -> a_hour << " : " << t.departureTime -> a_minute;
    cout << " (" << t.departureTime->inMinute() << " )";
    cout << " => " << t.destination << "  " << t.arrivalTime -> a_hour << " : " << t.arrivalTime -> a_minute ;
    cout << " (" << t.arrivalTime->inMinute() << " )";
    cout << "\n";
  }
  cout << "\n";
}
