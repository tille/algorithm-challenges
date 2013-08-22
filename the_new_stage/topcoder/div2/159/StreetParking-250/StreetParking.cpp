#include <iostream>
#include <string>

using namespace std;

class StreetParking{
public:
  int freeParks(string street){
    string free = street;
    int cont = 0;
    for( int i = 0; i < street.size(); ++i ){
      if( street[i] == 'B' or street[i] == 'S' or street[i] == 'D' ) continue;
      if( i != (street.size()-1) && street[i+1] == 'S' ) continue;
      if( i != 0 && street[i-1] == 'S' ) continue;
      if( i != (street.size()-1) && street[i+1] == 'B' ) continue;
      if( i < street.size()-2 && street[i+2] == 'B' ) continue;
      cont++;
    }
    return cont;
  }
};