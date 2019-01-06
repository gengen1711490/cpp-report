#include <stdio.h>
#include <iostream>
using namespace std;


class hm{
public:
  int Mi;
  hm();
  int hour;
  int minute;
  int inMinute();
  int timeInminute;
};

hm::hm(){
  int h;
  while (Mi >= 60) {
    Mi -= 60;
    h ++;
  };
  hour = h;
  minute = Mi;
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

class transTicket : public ticket, hm{
public:
  string origin;
  string destination;
  hm departureTime;
  hm arrivalTime;
  transTicket(): ticket(){};
};

int main(){
  int ticketNum;
  cout << "j1チケットを何枚購入しますか？ ";
  cin >> ticketNum;
  cout << "\n";
  transTicket* tickets = new transTicket [ticketNum];
  for(int i = 0; i < ticketNum; i++){
    tickets[i].id = i+1;
    cout << i+1 << "j2人目の利用者の名前を入力してください: ";
    cin >> tickets[i].user->name;
    cout << "  出発地を入力してください: ";
    cin >> tickets[i].origin;
    cout << "  出発時刻を入力してください（例：00:00）: ";
    scanf("%d:%d", &(tickets[i].departureTime.hour), &(tickets[i].departureTime.minute));
    cout << "  到着地を入力してください: ";
    cin >> tickets[i].destination;
    cout << "  到着時刻を入力してください（例：00:00）: ";
    scanf("%d:%d", &(tickets[i].arrivalTime.hour), &(tickets[i].arrivalTime.minute));
  }
  cout << "\n\nチケット利用者一覧：\n";
  for(int i = 0; i < ticketNum; i++){
    transTicket t = tickets[i];
    cout << " " << t.id << " : " << t.user->name << "  " ;
    cout << t.origin << "  " << t.departureTime.hour << " : " << t.departureTime.minute;
    cout << " (" << t.departureTime.inMinute() << " )";
    cout << " => " << t.destination << "  " << t.arrivalTime.hour << " : " << t.arrivalTime.minute ;
    cout << " (" << t.arrivalTime.inMinute() << " )";
    cout << "\n";
  }
  cout << "\n";
}
