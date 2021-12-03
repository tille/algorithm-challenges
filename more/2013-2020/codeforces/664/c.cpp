#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

string s;
int ini, range_end, t;
ii range[10];

// ranges
// 1 - 1989 1998
// 2 - 1999 2098
// 3 - 2099 3098
// 4 - 3099 13098
// 5 - 13099 113098
// 6 - 113099 1113098
// 7 - 1113099 11113098
// 8 - 11113099 111113098
// 9 - 111113099 1111113098

string rest[9] = {"199", "20", "3", "1", "1", "1", "1", "1", "1"};
string rest_non[9] = {"198", "19", "2", "", "", "", "", "", ""}; 

int cpot(ll n, ll e) {
  int res = 1;
  while (e--) res *= n;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  ini = 1989;
  REP(i, 1, 9) {
    range_end = ini + cpot(10, i);
    range[i] = make_pair(ini, range_end - 1);
    ini = range_end;
  }

  cin >> t;
  while (t--) {
    cin >> s;

    int it = 0;
    while (s[it] != '\'') it++;
    string s_num = s.substr(it + 1, s.size() - it - 1);

    string end_chars = s.substr( ? , s_num.size() - 1);

    if (end_chars == string(end_chars.size(), '9') or end_chars == string(end_chars.size(), '0')
      ans = res_non[s_num.size()] + s_num;
    else
      ans = res[s.num.size()] + s_num;

    cout << ans << endl;
  }
   
  return 0;
}

