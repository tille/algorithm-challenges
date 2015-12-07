#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef set<int> si; 
typedef map<string, int> msi;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) \
  for (msi::iterator it = (c).begin(); it != (c).end(); it++)

string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"}; 
string values[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
string cards[55], sol[55];
string line;
char c;
int suffles[105][55];
int idx, t, n, suffle_idx;

int main() {
  scanf("%d", &t);
  while (t--) {
    idx = 1;
    REP(i, 0, 3) REP(j, 0, 12)
      cards[idx++] = values[j] + " of " + suits[i];

    scanf("%d", &n);
    REP(i, 1, n) REP(j, 1, 52) scanf("%d", &suffles[i][j]);

    getline(cin, line);
    while (getline(cin, line)) {
      if (line == "") break;
      stringstream ss(line); ss >> suffle_idx;
      REP(i, 1, 52) sol[i] = cards[ suffles[suffle_idx][i] ];
      REP(i, 1, 52) cards[i] = sol[i];
    }
    REP(i, 1, 52) printf("%s\n", sol[i].c_str() );
    if (t) printf("\n");
  }
  return 0;
}
