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

vector<pair<string, int> > boot;
vi arr;
int ans;

bool run(vector<iii> &boot_c) {
  vector<bool> seen(10e4, false);
  int idx = 0, val; 
  string ins; 
  ans = 0;
  
  while (true) {
    if (seen[idx] == true || idx < 0 || idx > boot.size() - 1) break;
    else seen[idx] = true;

    iii i = boot_c[idx];
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
  if (idx == boot.size()) return true;
  else return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string line;

  while (getline(cin, line)) {
    stringstream ss(line);
    string s, val;
    ss >> s >> val;
    int num_val;
    
    num_val = stoi(val);
    boot.pb({s, num_val});
    if (s == "nop" || s == "jmp") {
      arr.pb(boot.size() - 1);
    }
  } 

  for (auto i: arr) {
    if (boot[i].first == "nop") {
      boot[i].first = "jmp";
    } else if (boot[i].first == "jmp") {
      boot[i].first = "nop";
    }
    
    if (run(boot)) {
      break;
    }
    
    if (boot[i].first == "nop") {
      boot[i].first = "jmp";
    } else if (boot[i].first == "jmp") {
      boot[i].first = "nop";
    }
  }
  cout << ans << endl;

  return 0;
}