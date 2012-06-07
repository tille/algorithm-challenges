// Andrés Mejía
using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

////////////// Prewritten code follows. Look down for solution. ////////////////
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
////////////////////////// Solution starts below. //////////////////////////////
vector <string> words;
vector <string> puzzle;

int main(){
    int h, w;
    cin >> h >> w;
    words.clear();
    puzzle.clear();
        
    for (int i = 0; i < h; i++){
        string line; cin >> line;
        puzzle.push_back(line);
    }
    
    // Find horizontal words
    for (int i = 0; i < h; i++){
        string line = puzzle[i];
        for (int j = 0; j < w; j++){
            string word = "";
            //D(i);D(j);
            while (j < w and line[j] != '#'){
                word += line[j];
                j++;
            }
            //if (j < w) D(line[j]);
            //D(word.size());
            if (word.size() > 1){
                words.push_back(word);
                //D(word);
            }
        }
    }
    
    // Find vertical words
    for (int j = 0; j < w; j++){
        string line = "";
        for (int i = 0; i < h; i++){
            line += puzzle[i][j];
        }
        //D(line);
        for (int i = 0; i < h; i++){
            string word = "";
            while (i < h and line[i] != '#'){
                word += line[i];
                i++;
            }
            if (word.size() > 1){
                words.push_back(word);
                //D(word);
            }
        }
    }
    
    sort(words.begin(), words.end());
    cout << words[0] << endl;
    return 0;
}










