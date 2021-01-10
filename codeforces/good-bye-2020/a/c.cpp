#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 1<<30;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

string reverse(string str) 
{ 
  string tales = str;
   for (int j=0, i=str.length()-1; i>=0; i--,j++) 
      tales[j] = str[i];

  return tales;  
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  while(t--){
    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;
    REP(i,1,n-1) {
      int a = (s[i] == s[i-1]);
      int b = (i > 1 && s[i] == s[i-2]);
      if (a || b) {
        ans++;
        s[i] = '?';
      }
    }
    cout << ans << endl;
  }

  return 0;
}