#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> iii;
typedef vector<int> vi;

const int inf = 1<<30;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string line;
  vector<pair<string, int> > boot;
  vector<bool> seen(10e4, false);  

  while (getline(cin, line)) {
    stringstream ss(line);
    string s, val;
    ss >> s >> val;
    int num_val;
    
    num_val = stoi(val);
    boot.pb({s, num_val});
  }

  int idx = 0, ans = 0;
  string ins; int val;
  
  while (true) {
    if (seen[idx] == true) break;
    else seen[idx] = true;
    
    iii i = boot[idx];
    tie(ins, val) = i;
  
    if (ins == "acc") {
      ans += val; 
      idx++;
    } else if (ins == "jmp") {
      idx += val;
    } else {
      idx++;
    }
  }
  cout << ans << endl;

  return 0;
}