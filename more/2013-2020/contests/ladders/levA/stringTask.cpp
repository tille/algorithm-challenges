#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

string str;

void reading() {
  char c;
  while(1) {
    c = getchar();
    if (c == '\n') break;
    c = tolower(c);
    if (c == 'a' or c == 'o' or c == 'y' or c == 'e' or c == 'u' or c == 'i') {
    } else {
      str += '.'; str += c;
    }
  }
}

int main() {
  reading();
  cout << str << "\n";
  return 0;
}

