#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<fstream>
#include<sstream>
#include<iterator>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<vector>

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

vector<string> tales;
int nums[300];
int n, Nwords, num, num2;
string alfabeto, word3;

int verify(string word, string word2){
    int menor = (word.size() < word2.size())? word.size() : word2.size();
    for( int i = 0; i < menor; ++i ){
        if( nums[ int(word[i]) ] > nums[ int(word2[i]) ] ) return 0;
        else if( nums[int(word[i])]  < nums[ int(word2[i]) ] ) return 1;
    }
    if( word.size() > word2.size() ) return 2;
    else return 3;
}

bool myfunction( string a , string b){
    int result = verify( a , b );
    if( !result || result == 2 ) return false;
    else return true;
}

int main(){

    scanf("%d",&n);

    for( int k = 0; k < n; ++k ){

        memset( nums, 0, sizeof nums );
        cin >> alfabeto;
        for( int i = 1; i <= alfabeto.size(); ++i ){
            int temp = alfabeto[i-1];
            nums[ temp ] = i;
        }

        cin >> num;
        while( num-- ){
            cin >> word3;
            tales.push_back(word3);
        }
        sort( tales.begin(), tales.end(), myfunction);
        for( int i = 0; i < tales.size(); ++i ) cout << tales[i] << endl;
        if( k != n-1 ) cout << endl;
        tales.clear();

    }
    return 0;
}
