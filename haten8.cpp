#include <iostream>
using namespace std;

class ex_account{
public:
  string account;
};

class ex_account_too_long : public ex_account{
public:
  ex_account_too_long(string str) { account = str; };
  string show() { return "アカウント '" + account + "' は長すぎです。\n"; };
};

class ex_account_too_short : public ex_account{
public:
  ex_account_too_short(string str) { account = str; };
  string show() { return "アカウント '" + account + "' は短すぎです。\n"; };
};

int main(){
  string account;
  int accountlenshort = 3;
  int accountlenlim = 6;
  cout << "希望アカウントを入力してください（英数字6文字以内）: ";
  cin >> account;

  try{
    if (account.length() > accountlenlim){
      ex_account_too_long ex2long(account);
      throw ex2long;
    }else if (account.length() < accountlenshort){
      ex_account_too_short ex2short(account);
      throw ex2short;
    }else{
      cout << "\n" << account << "さん、ようこそ！\n\n";
    }
  }

  catch (ex_account_too_long e){
    cout << "\nException: " << e.show() << "\n\n";
  }
  catch (ex_account_too_short e){
    cout << "\nException: " << e.show() << "\n\n";
  }
}
