#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
// another nice implementation https://gist.github.com/orendon/24628b77b6adddbd983bc0eca4a8418d

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 1<<30;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string s;
  int y = 0, x = 0, direction = 90;
  
  while (cin >> s) {
    char d = s[0];
    int num = stoi(s.substr(1, s.size()-1));

    if (d == 'N') y += num;
    if (d == 'S') y -= num;
    if (d == 'E') x += num;
    if (d == 'W') x -= num;

    if (d == 'R') direction = (direction + num) % 360;
    if (d == 'L') direction = ((direction - num) + 360) % 360;
    if (d == 'F') {
      if (direction == 0) y += num;
      if (direction == 180) y -= num;
      if (direction == 90) x += num;
      if (direction == 270) x -= num;
    }
  }

  cout << abs(x) + abs(y) << endl;
  return 0;
}