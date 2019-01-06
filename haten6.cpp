#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(){
    string word;
    cout << "任意の言葉を入力してください。： ";
    cin >> word;
     // ファイル書き出し
    word = word + ".backup";
    ofstream fout(word);
    if(!fout){cout << "出力ファイルが開けません"; return 1;}
    for(int i = 0; i < 5; i++){
        fout << i << "\n";
    }
    fout.close();

    // ファイル読み込み
    ifstream fin(word);
    if(!fin){cout << "入力ファイルが開けません"; return 1;}
    string str;
    int i;
    while(!fin.eof()){
        fin >> str;
        cout << "line " << i << ": " << str << "\n";
        i++;
    }
    fin.close();
    return 0;
}
