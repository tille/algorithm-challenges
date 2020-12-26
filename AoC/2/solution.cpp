#include <bits/stdc++.h>

using namespace std;

int main() {
  string line, policy, letteri, pwd;
  int valid = 0;

  while (getline(cin, line)) {
    stringstream ss(line);

    ss >> policy;
    ss >> letteri;
    ss >> pwd;

    int tt = policy.find('-');
    string mini_str = policy.substr(0, tt);
    string maxi_str = policy.substr(tt+1);

    int mini = stoi(mini_str);
    int maxi = stoi(maxi_str);

    char letter = letteri[0];

    int times = count(pwd.begin(), pwd.end(), letter);

    if (times >= mini && times <= maxi) {
      valid++;
    }
  }
  cout << valid << endl;

  return 0;
}