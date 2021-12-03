#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
  int t;
  string tmp, line;
  map<string, int> trees;

  cin >> t;
  getline(cin, tmp);
  getline(cin, tmp);

  while (t--) {
    trees.clear();
    int total = 0;

    while (getline(cin, line) && line.size() > 0) {
      trees[line]++;
      total++;
    }

    map <string, int> :: iterator it;

    for (it = trees.begin(); it != trees.end(); it++) {
      double percentage = 100.0 * (*it).second / total;
      printf("%s %.4lf\n", (*it).first.c_str(), percentage);
    }

    puts("");
  }
  return 0;
}
