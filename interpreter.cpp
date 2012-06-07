using namespace std;
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

typedef long long ll;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " es " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y, double tol = EPS)
{ return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

double round(double x){ return floor(x*100+0.5)/100; }

bool myfunction (int i,int j) { return (i>j); }

long long reverse_num( ll sourcenum ){
    ll temp = sourcenum;
    ll sum = 0;
    while ( temp ){
      sum *= 10;
      sum += temp%10;
      temp /= 10;
    }
    return sum;
}

int RAM[1003];
vector<string> Instr;

void solve(){
    int i = 0, cont = 0, test2 = 0;
    string temp = "";
    while(Instr[i][0] != '1'){
        if( !Instr[i].compare("000") ){ cont++; ++i; continue; }
        int test = 1;
        switch( Instr[i][0]-'0' ){
            case 2:
                RAM[Instr[i][1]-'0'] = Instr[i][2] - '0';
                break;
            case 3:
                RAM[Instr[i][1]-'0'] += Instr[i][2] - '0';
                RAM[Instr[i][1]-'0']%=1000;
                break;
            case 4:
                RAM[Instr[i][1]-'0'] *= Instr[i][2] - '0';
                RAM[Instr[i][1]-'0']%=1000;
                break;
            case 5:
                RAM[Instr[i][1]-'0'] = RAM[ Instr[i][2]-'0' ];
                RAM[Instr[i][1]-'0']%=1000;
                break;
            case 6:
                RAM[Instr[i][1]-'0'] += RAM[ Instr[i][2]-'0' ];
                RAM[Instr[i][1]-'0']%=1000;
                break;
            case 7:
                RAM[Instr[i][1]-'0'] *= RAM[ Instr[i][2]-'0' ];
                RAM[Instr[i][1]-'0']%=1000;
                break;
            case 8:
                RAM[Instr[i][1]-'0'] = toInt(Instr[RAM[Instr[i][2]-'0']]);
                break;
            case 9:
                temp = toStr(RAM[ Instr[i][1] - '0' ]);
                while( temp.size() < 3 ) temp = "0" + temp;
                //cout << RAM[Instr[i][2]-'0'] << " " << temp << " " << Instr.size() << endl;
                while( RAM[Instr[i][2]-'0'] > Instr.size()-1  ) Instr.push_back("000");
                Instr[RAM[Instr[i][2]-'0']] = temp;
                RAM[Instr[i][1]-'0']%=1000;
                break;
            case 0:
                test = 0;
                if(RAM[Instr[i][2]-'0']) i = RAM[Instr[i][1]-'0'];
                else ++i;
                break;
            default:
                test2 = 1;
                break;
        }
        cont++;
        if(test) ++i;
    }
    printf("%d\n",cont+1);
}


int main(){
    string n;
    int t;
    //freopen("tales.txt","r",stdin);
    //freopen("tales2.txt","w",stdout);
    scanf("%d",&t);
    getline(cin,n);
    getline(cin,n);
    for( int j = 0; j < t; ++j ){
        if( j ) cout << endl;
        while(getline(cin,n) && (n.size() == 3) ){
            Instr.push_back(n);
        }

        memset( RAM , 0, sizeof RAM );
        solve();
        Instr.clear();
    }
    return 0;
}
