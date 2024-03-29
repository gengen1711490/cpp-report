#include <iostream>
using namespace std;

class person{
protected:
  string name;
public:
  person(){};
  void setName(string n){name = n;};
  virtual void requestData(){};
  virtual void showData(){};
};

class par_node{
public:
  person* participant;
  par_node* next;
};

class member : public person{
  int memberid;
public:
  void requestData(){
    cout << "会員番号を入力してください。\n";
    cin >> memberid;
  };
  void showData(){
    cout << name << "　会員     会員番号: " << memberid << "\n";
  };
};

class stmember : public member{
  int grade;
  int memberid;
public:
  void requestData(){
    cout << "学年を入力してください。\n";
    cin >> grade;
    cout << "会員番号を入力してください。\n";
    cin >> memberid;
  };
  void showData(){
    cout << name << "　学生会員 学年: " << grade << "  会員番号: " << memberid << "\n";
  };
};


class nonmember : public person {
  string email;
  string phone;
public:
  void requestData(){
    cout << "メールアドレスを入力してください。\n";
    cin >> email;
    cout << "電話番号を入力してください。\n ";
    cin >> phone;
  };
  void showData(){
    cout << name << "　非会員   メールアドレス: " << email << "  電話番号:" << phone << "\n";
  };
};

int main(){
  int i;
  string name, mtype;
  par_node* p = new par_node;
  par_node* q = p;

  while(1){
    cout << "名前を入力してください。（終了する場合は quit と入力してください）\n";
    cin >> name;
    if(name == "quit"){break;}
    cout << "会員ですか？(y/n) \n";
    cin >> mtype;
    if(mtype == "y"){
      q->participant = new member;
      cout << "学生ですか？(y/n) \n";
      cin >> mtype;
      if(mtype == "y"){
        q->participant = new stmember;
      }else{
        q->participant = new member;
      }
    }else{
      q->participant = new nonmember;
    }
    q->participant->setName(name);
    q->participant->requestData();
    q->next = new par_node;
    q = q->next;
    i++;
  }

  cout << "\n参加者一覧：\n";
  q = p;
  while (i > 0){
    q->participant->showData();
    q = q->next;
    i--;
  }
  cout << "\n";
}
