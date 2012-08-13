#include <iostream>
#include <string>

using namespace std;

int main() {
  int num_banks;
  string input;
  cin >> num_banks >> input;
  int * bank_sizes = new int[input.size() + 1];
  bank_sizes[0] = num_banks;
  int min_bank = 0;
  int next_bank = 0;
  for (string::iterator it = input.begin(); it < input.end(); ++it) {
    if ((*it) == '1' || bank_sizes[min_bank] >= 2) { // increment a minimum bank
      --bank_sizes[min_bank];
      ++bank_sizes[min_bank + 1];
      if (bank_sizes[min_bank] == 0) {
        ++min_bank;
      } else if (bank_sizes[min_bank] == 1 && min_bank == next_bank) {
        ++next_bank;
      }
    } else { // increment a next to minimum bank
      --bank_sizes[next_bank];
      ++bank_sizes[next_bank + 1];
      if (bank_sizes[next_bank] == 0) {
        ++next_bank;
      }
    }
  }
  cout << min_bank << " " << next_bank;
  return 0;
}
