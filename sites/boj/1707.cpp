#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_VERTEX = 20001;
const int NOT_VISITED = 0;
const int TEAM_A = 1, TEAM_B = 2;

vector<int> graph[MAX_VERTEX];
int visited[MAX_VERTEX];
int testcases, v, e;

void reset(int v) {
  for (int i = 1; i <= v; ++i) {
    graph[i].clear();
  }
  memset(visited, NOT_VISITED, sizeof(visited));
}

void setVertices(int from, int to) {
  graph[from].push_back(to);
  graph[to].push_back(from);
}

int getNextTeam(int currentTeam) {
  switch (visited[currentTeam]) {
  case TEAM_A:
    return TEAM_B;
  case TEAM_B:
    return TEAM_A;
  default:
    return NOT_VISITED;
  }
}

void bfs(int start) {
  queue<int> temperal;
  int currentTeamName = TEAM_A;

  visited[start] = currentTeamName;
  temperal.push(start);

  while (!temperal.empty()) {
    int currentVertex = temperal.front();
    temperal.pop();
    int nextTeam = getNextTeam(currentVertex);

    for (int i : graph[currentVertex]) {
      if (visited[i] == NOT_VISITED) {
        visited[i] = nextTeam;
        temperal.push(i);
      }
    }
  }
}

void runBFS(int v) {
  for (int i = 1; i <= v; ++i) {
    if (!visited[i]) {
      bfs(i);
    }
  }
}

bool isBiperate(int v) {
  for (int i = 1; i <= v; ++i) {
    for (int next : graph[i]) {
      if (visited[i] == visited[next]) {
        return false;
      }
    }
  }

  return true;
}

void printBiperate(bool isBiperate) {
  if (isBiperate) {
    cout << "YES" << endl;
    return;
  }

  cout << "NO" << endl;
  return;
}

int main(void) {
  cin >> testcases;
  while (testcases--) {
    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
      int temp1, temp2;
      cin >> temp1 >> temp2;
      setVertices(temp1, temp2);
    }

    runBFS(v);

    printBiperate(isBiperate(v));

    reset(v);
  }
  return 0;
}