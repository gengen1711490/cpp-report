#include <iostream>
using namespace std;

class movie{
public:
  string title;
  movie(string T){title = T;}
};

class copyprotection{
public:
    string code;
    copyprotection(string C){code = C;}
};

class protectedMovie : public movie, public copyprotection{
public:
    protectedMovie(string T, string C) : movie(T),  copyprotection(C){};
};

int main(){
    protectedMovie protectedMovie_a("movie_xmen", "1234");
    cout << protectedMovie_a.title << ":" << protectedMovie_a.code << "\n";
};
