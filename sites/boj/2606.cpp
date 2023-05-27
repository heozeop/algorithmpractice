#include <iostream>
#include <queue>

using namespace std;

const int MAX = 101;
const int CONNECTED = 10;
const int VISITED = 1;

int n, numOfConnections;
int connections[MAX][MAX];
int visited[MAX];

void getVariables() {
  cin >> n >> numOfConnections;

  for (int i = 1; i <= numOfConnections; ++i) {
    int from, to;
    cin >> from >> to;
    connections[from][to] = CONNECTED;
    connections[to][from] = CONNECTED;
  }
}

void printConnectedWithOne() {
  queue<int> links;
  links.push(1);
  visited[1] = VISITED;
  int count = 0;
  while (links.size() > 0) {
    int from = links.front();
    links.pop();
    for (int i = 1; i <= n; ++i) {
      const int isConnected = connections[from][i] == CONNECTED;
      const int isVisited = visited[i] == VISITED;

      if (isConnected && !isVisited) {
        count += 1;
        links.push(i);
        visited[i] = VISITED;
      }
    }
  }

  cout << count << endl;
}

int main(void) {
  getVariables();
  printConnectedWithOne();
}