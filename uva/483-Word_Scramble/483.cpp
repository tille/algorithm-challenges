#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  string str, line;

  while ( getline(cin, line) ) {
    vector<string> words;
    stringstream ss(line);

    while ( ss >> str ) words.push_back(str);

    for (int i=0;i<words.size(); ++i) {
      if (i!=0) cout << " ";
      cout << string(words[i].rbegin(),words[i].rend());
    }
    cout << endl;
  }
  return 0;
}
