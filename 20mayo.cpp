#include <iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> graph[17];
int visited[17];

void newGraph(){
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);
    graph[2].push_back(5);
    graph[2].push_back(6);
    graph[3].push_back(7);
    graph[3].push_back(8);
    graph[3].push_back(9);
    graph[4].push_back(10);
    graph[4].push_back(11);
    graph[4].push_back(1);
    graph[6].push_back(12);
    graph[6].push_back(13);
    graph[8].push_back(14);
    graph[14].push_back(15);
}

void bfs( int n ){
    memset( visited, 0, sizeof visited );
    queue<int> q;
    q.push(n);
    while( q.size() ){
        if( !visited[q.front()] ){
            cout << q.front() << endl;
            visited[q.front()] = 1;
            for( int i = 0; i < graph[q.front()].size(); ++i ){
                if( !visited[graph[q.front()][i]] ) q.push(graph[q.front()][i]);
            }
            q.pop();
        }
    }
}

int main(){
    newGraph();
    bfs(1);
    return 0;
}
