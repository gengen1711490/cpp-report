#include <iostream>
#include <math.h>
using namespace std;

class site_loc;
class user_loc;

class user_loc{
private:
  double longitude;
  double latitude;

public:
  user_loc(double Lon, double Lat){
    longitude = Lon;
    latitude = Lat;
  };
  friend double distance(user_loc u, site_loc s);
};

class site_loc{
private:
  double longitude;
  double latitude;

public:
  site_loc(double Lon, double Lat){
    longitude = Lon;
    latitude = Lat;
  };
  friend double distance(user_loc ul, site_loc sl);
};

double distance(user_loc ul, site_loc sl){
  double dlo = ul.longitude - sl.longitude;
  double dla = ul.latitude - sl.latitude;
  return sqrt(pow(dlo * 40000 / 360, 2) + pow(dla * 40000 * cos(35.68 * 3.1416 / 180) / 360, 2));
};

int main(){
  user_loc user = user_loc(36.082510, 140.111709);
  site_loc chiba = site_loc(35.600915, 140.071537);
  cout << distance(user, chiba) << "km\n";
}
