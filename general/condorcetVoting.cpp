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

class CondorcetVoting{
public:
    int winner(vector<string> votes){

        int result[100];
        memset(result,0,sizeof result);
        for( int i = 0; i < votes[0].size(); ++i ){
            for( int k = 0; k < votes[0].size(); ++k ){
                if( i == k ) continue;
                int r1 = 0, r2 = 0;
                for( int j = 0; j < votes.size(); ++j ){
                    if( int(votes[j][i]) < int(votes[j][k]) ) r1++;
                    else if ( int(votes[j][i]) > int(votes[j][k]) ) r2++;
                }
                if( r1 > r2 ) result[i]++;
            }
        }

        int maximun = 0;
        for( int i = 1; i < votes[0].size(); ++i )
            if( result[i] > result[maximun] ) maximun = i;

        int salir = 1;
        if( result[maximun] != votes[0].size()-1 ) salir = 0; // Debe haber un candidato que le gane a todos los demas
        for( int i = 0; i < votes[0].size() and salir; ++i )
            if( result[i] == result[maximun] and i!=maximun ) salir = 0;

        return (!salir?-1:maximun);
    }
};

int main(){
    CondorcetVoting c;
    vector<string> votes;
    votes.push_back("adbb");
    votes.push_back("adbb");
    votes.push_back("adbb");
    votes.push_back("edee");
    votes.push_back("edbb");
    votes.push_back("edbb");

    cout << c.winner(votes);
    return 0;
}
