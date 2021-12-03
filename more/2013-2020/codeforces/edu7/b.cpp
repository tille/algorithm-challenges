#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; 

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define TRmsi(c, it) for (msi::iterator it = (c).begin(); it != (c).end(); it++)

int nums[2];

void reading() {
  nums[0] = nums[1] = 0;
  char c; int i = 0;
  while (1) {
    c = getchar();
    if (c == '\n') break;
    if (c == ':') i++;
    else {
      nums[i] = nums[i] * 10 + (c - '0');
    }
  }
}

int main() {
  int a;
  reading(); 
  cin >> a;
  nums[0] = (nums[0] + (a/60)) % 24;
  int temp = (nums[1] + (a%60));
  if (temp/60) nums[0] = (nums[0] + 1) % 24;
  nums[1] = temp % 60;

  printf("%02d:%02d\n", nums[0], nums[1]);
  return 0;
}

