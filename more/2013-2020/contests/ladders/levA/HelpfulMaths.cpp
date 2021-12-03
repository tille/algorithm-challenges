#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

priority_queue<int, vector<int>, greater<int> > q;
int num;

void reading() {
  char c;
  while (1) {
    c = getchar();
    if (c == '\n') break;
    if(isdigit(c)) q.push(c - '0'); 
  }
}

int main() {
  reading();
  while (q.size()) {
    num = q.top();
    q.pop();
    cout << num;
    if (q.size()) cout << "+";
  }
  puts("");
  return 0;
}

