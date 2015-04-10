#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXS = 100005; // Max number of states

struct Trie {
  int g[MAXS][26];
  int stateCount;

  Trie() {
    clear();
  }

  void clear() {
    memset(g[0], -1, sizeof g[0]);
    stateCount = 1;
  }

  void add(char * s) {
    int state = 0; // root
    for (; *s; s++) {
      int next = (*s - 'a');
      if (g[state][next] == -1) { // Add new state
        g[state][next] = stateCount;
        memset(g[stateCount], -1, sizeof g[stateCount]);
        stateCount++;
      }
      state = g[state][next];
    }
  }

  void add(const string &s) {
    add(s.c_str());
  }
};


int main() {
  static Trie t;
  t.add("bang");
  t.add("bing");
  t.add("bong");
  t.add("bon");
  t.add("bo");
  t.add("b");
  printf("There are %d non-empty prefixes in total.\n", t.stateCount - 1);
}