#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl


typedef long long ll;
ll digits;
string num;
char array[200][200];
bool salir1 = false;

void cero( int pos ){
    int posi2 = pos+1+digits;
    int posi3 = 1+digits;
    int posi4 = posi3+1+digits;
    for ( int i = pos+1; i< posi2; ++i ){
        array[0][i] = '-';
        array[posi4][i] = '-';
    }
    for ( int j = 1; j< posi3; ++j ){
        array[j][pos] = '|';
        array[j][posi2] = '|';
    }
    for ( int j2 = posi3+1; j2< posi4; ++j2 ){
        array[j2][pos] = '|';
        array[j2][posi2] = '|';
    }
}

void one( int pos ){
    int posi = pos + ((digits+2)-1);
    int posi2 = 1+digits;
    int posi3 = (posi2+1) + digits;
    for ( int i = 1; i< posi2; ++i ) array[i][posi] = '|';
    for ( int j = posi2+1; j< posi3; ++j ) array[j][posi] = '|';
}

void two( int pos ){
    int posi = pos+1+digits;
    int posi2 = 1+digits;
    int posi3 = posi2+1+digits;
    for ( int j = pos+1; j< pos+1+digits; ++j ){
        array[0][j] = '-';
        array[posi2][j] = '-';
        array[posi3][j] = '-';
    }
    for ( int i = 1; i< posi2; ++i ) array[i][posi] = '|';
    for ( int j2 = posi2+1; j2< posi3; ++j2 ) array[j2][pos] = '|';
}

void three( int pos ){
    pos++;
    int posi = pos+digits;
    int posi2 = 1+digits;
    int posi3 = posi2+1+digits;
    for ( int i = pos; i< pos+digits; ++i ){
        array[0][i] = '-';
        array[posi2][i] = '-';
        array[posi3][i] = '-';
    }
    for ( int j = 1; j< posi2; ++j ) array[j][posi] = '|';
    for ( int j2 = posi2+1; j2< posi3; ++j2 ) array[j2][posi] = '|';

}

void four( int pos ){
    int posi = 1+digits;
    int pos2 = pos+1+digits;
    int pos3 = posi+1+digits;
    for ( int i = 1; i< posi; ++i ){
        array[i][pos] = '|';
        array[i][pos2] = '|';
    }
    for ( int j = pos+1; j< pos2; ++j ) {
        array[posi][j] = '-';
    }
    for ( int i2 = posi+1; i2< pos3; ++i2 ) {
        array[i2][pos2] = '|';
    }
}

void five( int pos ){
    int posi = pos+1+digits;
    int posi2 = 1+digits;
    int posi3 = posi2+1+digits;
    for ( int j = pos+1; j< pos+1+digits; ++j ){
        array[0][j] = '-';
        array[posi2][j] = '-';
        array[posi3][j] = '-';
    }
    for ( int i = 1; i< posi2; ++i ) array[i][pos] = '|';
    for ( int j2 = posi2+1; j2< posi3; ++j2 ) array[j2][posi] = '|';
}

void six( int pos ){
    int posi2 = pos+1+digits;
    int posi3 = 1+digits;
    int posi4 = posi3+1+digits;
    for ( int i = pos+1; i< posi2; ++i ){
        array[0][i] = '-';
        array[posi4][i] = '-';
        array[posi3][i] = '-';
    }
    for ( int j = 1; j< posi3; ++j ){
        array[j][pos] = '|';
        //array[j][posi2] = '|';
    }
    for ( int j2 = posi3+1; j2< posi4; ++j2 ){
        array[j2][pos] = '|';
        array[j2][posi2] = '|';
    }
}

void seven( int pos ){
    int posi = pos + ((digits+2)-1);
    int pos4 = pos+1+digits;
    int posi2 = 1+digits;
    int posi3 = (posi2+1) + digits;
    for ( int i = 1; i< posi2; ++i ) array[i][posi] = '|';
    for ( int j = posi2+1; j< posi3; ++j ) array[j][posi] = '|';
    for ( int i2 = pos+1; i2< pos4; ++i2 ) array[0][i2] = '-';
}

void eight( int pos ){
    int posi2 = pos+1+digits;
    int posi3 = 1+digits;
    int posi4 = posi3+1+digits;
    for ( int i = pos+1; i< posi2; ++i ){
        array[0][i] = '-';
        array[posi4][i] = '-';
        array[posi3][i] = '-';
    }
    for ( int j = 1; j< posi3; ++j ){
        array[j][pos] = '|';
        array[j][posi2] = '|';
    }
    for ( int j2 = posi3+1; j2< posi4; ++j2 ){
        array[j2][pos] = '|';
        array[j2][posi2] = '|';
    }
}

void nine( int pos ){
    int posi2 = pos+1+digits;
    int posi3 = 1+digits;
    int posi4 = posi3+1+digits;
    for ( int i = pos+1; i< posi2; ++i ){
        array[0][i] = '-';
        array[posi4][i] = '-';
        array[posi3][i] = '-';
    }
    for ( int j = 1; j< posi3; ++j ){
        array[j][pos] = '|';
        array[j][posi2] = '|';
    }
    for ( int j2 = posi3+1; j2< posi4; ++j2 ){
        //array[j2][pos] = '|';
        array[j2][posi2] = '|';
    }
}

int main(){
  while( cin >> digits >> num && ( digits!=0 || num[0]!='0' ) ){
    if( salir1 ) cout << endl;
    memset(array,' ', sizeof(array));

    for ( int i = 0; i< num.size(); ++i ) {
        int tales = ((digits+2)*i)+i;
        if( num[i] == '0' ) cero( tales );
        else if( num[i] == '1' ) one( tales );
        else if( num[i] == '2' ) two( tales );
        else if( num[i] == '3' ) three( tales );
        else if( num[i] == '4' ) four( tales );
        else if( num[i] == '5' ) five( tales );
        else if( num[i] == '6' ) six( tales );
        else if( num[i] == '7' ) seven( tales );
        else if( num[i] == '8' ) eight( tales );
        else if( num[i] == '9' ) nine( tales );
    }

    for ( int r = 0; r<2*digits+3 ; ++r ) {
        for ( int j = 0; j < ((digits+2)*(num.size())+(num.size()))-1; ++j ) {
            cout << array[r][j];
        }
        printf(" ");
        cout << endl;
    }
    salir1 = true;

  }
  return 0;
}
