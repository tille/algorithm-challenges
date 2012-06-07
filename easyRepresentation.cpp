using namespace std;
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

typedef long long ll;

ll result = 0;
string s;

int buscarProximoCierre( int n ){
    stack<int> q;
    int ans;

    q.push(n);
    for( int i = n+1; q.size() ; ++i ){
        if( s[i] == '(' ) q.push(i);
        else{
            ans = i;
            q.pop();
        }
    }
    return ans;
}

// la altura es 1 mas lo que yo tengo adentro

int recursion( int left, int right, int color ){
    //cout << left << " " << right << " " << endl;
    int i = left;
    int ans = 1;
    while( i < right ){
        int cierre = buscarProximoCierre(i);

        int area = 1;
        if( (cierre-i) > 1 ){
            int altura = 1+recursion( i+1,cierre-1,((!color)?1:0) );
            area = (cierre-i)*(altura);
            ans = max(altura,ans);
        }

        if( color == 1 ) result += area;
        else result -= area;
        i = cierre + 1;
    }
    return ans;
}

int main(){
    freopen("in.txt","r",stdin);
    int t;
    cin >> t;
    while( t-- ){
        result = 0;
        cin >> s;
        recursion(0,s.size()-1,1);
        cout << result << endl;
    }
    return 0;
}
