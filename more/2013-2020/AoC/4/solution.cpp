#include <bits/stdc++.h>

using namespace std;

bool have_cid(vector<string> &v) {
  for (auto i : v) {
    if (i == "cid") {
      return true;
    }
  }
  return false;
}

bool isNumber(string str) {
  for (auto i : str) {
    if ( !isdigit(i) ) {
      return false;
    }
  }
  return true;
}

bool is_valid_char(char i) {
  return (i - 'a') >= 0 && (i - 'a') <= 5;
}

bool valid_byr(string data) {
  int valid = 0;
  valid += isNumber(data);
  valid += data.size() == 4; 
  valid += stoi(data) >= 1920 && stoi(data) <= 2002;
  return valid == 3;
}

bool valid_iyr(string data) {
  int valid = 0;
  valid += isNumber(data);
  valid += data.size() == 4; 
  valid += stoi(data) >= 2010 && stoi(data) <= 2020;
  return valid == 3;
}

bool valid_eyr(string data) {
  int valid = 0;
  valid += isNumber(data);
  valid += data.size() == 4; 
  valid += stoi(data) >= 2020 && stoi(data) <= 2030;
  return valid == 3;
}

bool valid_hcl(string data) {
  int valid = 0;
  valid += data.size() == 7;
  valid += data[0] == '#';

  string val = data.substr(1, 6);
  for (auto i : val)
    valid += is_valid_char(i) or isdigit(i);

  return valid == 8;
}

bool valid_hgt(string data) {
  int valid = 0;
  string num = data.substr(0, data.size() - 2);

  if (data.size() > 2 && isNumber(num)) {
    if (data.substr(data.size() - 2) == "cm") {
      valid += stoi(num) >= 150 && stoi(num) <=193;     
    } else if (data.substr(data.size() - 2) == "in") {
      valid += stoi(num) >= 59 && stoi(num) <=76;
    }
  }
  return valid == 1;
}

bool valid_ecl(string data) {
  string arr[] = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
  
  for (auto i : arr)
    if (i == data)
      return true;

  return false;
}

bool valid_pid(string data) {
  int valid = 0;
  valid += data.size() == 9;
  valid += isNumber(data);
  return valid == 2;
}

bool valid_data(vector<string> &v, vector<string> &d) {
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == "byr") {

      if ( !valid_byr(d[i]) ) {
        return false;
      }

    } else if (v[i] == "iyr") {

      if ( !valid_iyr(d[i]) ) {
        return false;
      }

    } else if (v[i] == "eyr") {

      if ( !valid_eyr(d[i]) ) {
        return false;
      }

    } else if (v[i] == "hgt") {

      if ( !valid_hgt(d[i]) ) {
        return false;
      }

    } else if (v[i] == "hcl") {

      if ( !valid_hcl(d[i]) ) {
        return false;
      }

    } else if (v[i] == "ecl") {

      if ( !valid_ecl(d[i]) ) {
        return false;
      }

    } else if (v[i] == "pid") {

      if ( !valid_pid(d[i]) ) {
        return false;
      }

    }
  }
  return true;
}

int main() {
  string line;
  vector<string> v;
  vector<string> d;
  int valid = 0;

  while (getline(cin, line)) {
    stringstream ss(line);
    if (line != "") {
      string data;
      while (ss >> data) {
        v.push_back(data.substr(0,data.find(":")));
        d.push_back(data.substr(data.find(":") + 1));
      }
    } else {
      if (v.size() == 8 && valid_data(v, d)) {
        valid++;
      } else if (v.size() == 7) {
        if ( !have_cid(v) && valid_data(v, d) ) {
          valid++;
        }
      }
      v.clear();
      d.clear();
    }
  }

  if (v.size() == 8 && valid_data(v, d)) {
    valid++;
  } else if (v.size() == 7) {
    if ( !have_cid(v) && valid_data(v, d) ) {
      valid++;
    }
  }

  cout << valid << endl;
  return 0;
}