#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin >> t;
  // string mc[5][5];
  map<string, int> nm;

  string names[5] = {"rock", "paper", "scissors", "lizard", "spock"};
  string pnames[5] = {"pedra", "papel", "tesoura", "lagarto", "spock"};
  REP(i, 0, 4) nm[names[i]] = i;
  REP(i, 0, 4) nm[pnames[i]] = i;

  string mc[5][5] = {{"0", "2", "1", "1", "2"},
                     {"1", "0", "2", "2", "1"},
                     {"2", "1", "0", "1", "2"},
                     {"2", "1", "2", "0", "1"},
                     {"1", "2", "1", "2", "0"}};

  string a, b;
  while (t--) {
    cin >> a >> b;
    int aa = nm[a], bb = nm[b];
    string res = mc[aa][bb];

    if (res == "1") cout << "rajesh" << endl;
    else if (res == "2") cout << "sheldon" << endl;
    else cout << "empate" << endl;
  }
  return 0;
}

