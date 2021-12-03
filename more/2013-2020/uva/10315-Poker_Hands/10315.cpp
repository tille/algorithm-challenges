#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)

string hands[2][5]; // 0-black, 1-white
string line, cur;
int rank_val = 10, black, white;
char cards[14] = 
  {'2','3','4','5','6','7','8','9','T','J','Q','K','A','0'};
#define DEBUG false
#define K 10000000

int c_pot(int m, int n) {
  int res = 1;
  while (n--) res *= m;
  return res;
}

int card_val(char card) {
  if (card >= '2' && card <= '9') return (card - '0') - 1;
  else if (card == 'T') return 9;
  else if (card == 'J') return 10;
  else if (card == 'Q') return 11;
  else if (card == 'K') return 12;
  else if (card == 'A') return 13;
  else return -1;
}
char next_card(char card) {
  return cards[card_val(card)]; 
}

bool straigh_flush(int color) {
  if (DEBUG) cout << 9 << endl;
  bool valid = true;
  REP(i, 0, 3) {
    string curr = hands[color][i]; string nextt = hands[color][i + 1];
    // cout << cur << "-" << next << "-" << next_card(cur[0]) << endl;
    if (curr[1] != nextt[1] || next_card(curr[0]) != nextt[0]) {
      valid = false;
      break;
    }
  }
  if (valid) rank_val = (9 * K) + card_val(hands[color][4][0]);
  return valid;
}
bool four_of_a_kind(int color) {
  if (DEBUG) cout << 8 << endl;
  map<char, int> card_v;
  REP(i, 0, 4)
    card_v[ hands[color][i][0] ]++;
  map<char, int> :: iterator it;
  int a, b; char rr; a = b = 0;
  for (it = card_v.begin(); it != card_v.end(); ++it) { 
    if (it->second == 4) { a++; rr = it->first; }
    if (it->second == 1) { b++; }
  }
  if (a == 1 && b == 1) {
    rank_val = (8 * K) + card_val(rr);
    return true;
  }
  return false;
}
bool full_house(int color) {
  if (DEBUG) cout << 7 << endl;
  map<char, int> card_v;
  REP(i, 0, 4)
    card_v[ hands[color][i][0] ]++;
  map<char, int> :: iterator it;
  int a, b; char rr; a = b = 0;
  for (it = card_v.begin(); it != card_v.end(); ++it) { 
    if (it->second == 3) { a++; rr = it->first; }
    if (it->second == 2) { b++; }
  }
  if (a == 1 && b == 1) {
    rank_val = (7 * K) + card_val(rr);
    return true;
  }
  return false;
}
bool flush(int color) {
  if (DEBUG) cout << 6 << endl;
  bool valid = true;
  REP(i, 0, 3)
    if (hands[color][i][1] != hands[color][i + 1][1]) 
      valid = false;
  if (valid) {
    rank_val = 6 * K;
    REP(j, 0, 4)
      rank_val += card_val(hands[color][4 - j][0]) * c_pot(13, 5 - j);
  }
  return valid;
}
bool straight(int color) {
  if (DEBUG) cout << 5 << endl;
  bool valid = true;
  REP(i, 0, 3) {
    cur = hands[color][i]; string nextt = hands[color][i + 1];
    if (nextt[0] != next_card(cur[0])) 
      valid = false;
  }
  if (valid) rank_val = (5 * K) + card_val(hands[color][4][0]);
  return valid;
}
bool three_of_a_kind(int color) {
  if (DEBUG) cout << 4 << endl;
  map<char, int> card_v;
  REP(i, 0, 4)
    card_v[ hands[color][i][0] ]++;
  map<char, int> :: iterator it;
  int a, b; char rr; a = b = 0;
  vector<int> v;
  for (it = card_v.begin(); it != card_v.end(); ++it) { 
    if (it->second == 3) { a++; rr = card_val(it->first); }
    if (it->second == 1) { b++; v.push_back( card_val(it->first) ); }
  }
  if (a == 1 && b == 2) {
    sort(v.begin(), v.end());
    rank_val = 4 * K;
    rank_val += rr * c_pot(13, 5);
    REP(i, 0, 1)
      rank_val += v[1 - i] * c_pot(13, 4 - i);
    return true;
  }
  return false;
}
bool two_pairs(int color) {
  if (DEBUG) cout << 3 << endl;
  map<char, int> card_v;
  REP(i, 0, 4)
    card_v[ hands[color][i][0] ]++;
  int a, b; a = b = 0;
  map<char, int> :: iterator it;
  vector<int> v;
  int rr;

  for (it = card_v.begin(); it != card_v.end(); ++it) { 
    if (it->second == 2) { a++; v.push_back( card_val(it->first) ); }
    if (it->second == 1) { b++; rr = card_val( it->first ); }
  }
  if (a == 2 && b == 1) {
    sort(v.begin(), v.end());
    rank_val = 3 * K;
    REP(i, 0, 1)
      rank_val += v[1 - i] * c_pot(13, 5 - i);
    rank_val += rr * c_pot(13, 3);
    return true;
  }
  return false;
}
bool pair_hand(int color) {
  if (DEBUG) cout << 2 << endl;
  map<char, int> card_v;
  REP(i, 0, 4)
    card_v[ hands[color][i][0] ]++;
  int a, b, rr; a = b = 0;
  map<char, int> :: iterator it;
  vector<int> v;

  for (it = card_v.begin(); it != card_v.end(); ++it) { 
    if (it->second == 2) { a++; rr = card_val(it->first); }
    if (it->second == 1) { b++; v.push_back( card_val(it->first) ); }
  }
  if (b == 3 && a == 1) {
    sort(v.begin(), v.end());
    rank_val = 2 * K;
    rank_val += rr * c_pot(13, 5);
    REP(i, 0, 2)
      rank_val += v[2 - i] * c_pot(13, 4 - i);
    return true;
  }
  return false;
}
bool high_card(int color) {
  if (DEBUG) cout << 1 << endl;
  rank_val = 1 * K;
  REP(i, 0, 4)
    rank_val += card_val( hands[color][4 - i][0] ) * c_pot(13, 5 - i);
  return true;
}

bool my_function(string i, string j) {
  return card_val(i[0]) < card_val(j[0]);
}

int rankk(int color) {
  sort(hands[color], hands[color] + 5, my_function);

  if (straigh_flush(color)) return rank_val;
  else if (four_of_a_kind(color)) return rank_val;
  else if (full_house(color)) return rank_val;
  else if (flush(color)) return rank_val;
  else if (straight(color)) return rank_val;
  else if (three_of_a_kind(color)) return rank_val;
  else if (two_pairs(color)) return rank_val;
  else if (pair_hand(color)) return rank_val;
  else { high_card(color); return rank_val; }
}

int main() {
  while (getline(cin, line)) {
    if (line == "") break;
    stringstream ss(line);
    REP(i, 0, 1) REP(j, 0, 4)
       ss >> hands[i][j];
    black = rankk(0);
    if (DEBUG) cout << rank_val << endl;
    if (DEBUG) cout << "----" << endl;
    white = rankk(1);
    if (DEBUG) cout << rank_val << endl;
    if (black == white) printf("Tie.\n");
    else if(black > white) printf("Black wins.\n");
    else printf("White wins.\n");
  }
  return 0;
}
