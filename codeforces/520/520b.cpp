#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define long long ll

int visited[20000];

int bfs(int init, int end) {
  queue<int> q;
  int number, counter;
  
  q.push(init);
  q.push(0);

  while( q.size() ) {
    number = q.front();
    q.pop();
    counter = q.front();
    q.pop();

    if( !visited[number] ) visited[number] = 1;

    if( number == end ) {
      return counter;
    } else {
      int next = number * 2;
      int previous = number - 1;
      
      if( next == end ) return counter + 1;
      if( previous == end ) return counter + 1;
      if( next < 20000 && !visited[next] ) { 
        q.push(next);
        q.push(counter + 1);
      }
      if( previous > 0 && !visited[previous] ) { 
        q.push(previous);
        q.push(counter + 1);
      }
    }
  }
}


int main() {
  int n, m, result;
  
  memset( visited, 0, sizeof visited );

  cin >> n >> m;
  
  result = bfs(n, m);

  cout << result << endl;
  return 0;
}
