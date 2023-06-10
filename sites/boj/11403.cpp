#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

const int VISITED = 1;
const int MAX_N = 100;

int START_IDX, END_IDX;

int n;
int directedGraph[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

void input();
void solve();
void dfs(int from, int to);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  START_IDX = 0;
  END_IDX = n;

  for (int i = START_IDX; i < END_IDX; ++i) {
    for (int j = START_IDX; j < END_IDX; ++j) {
      cin >> directedGraph[i][j];
    }
  }
  return;
}

void solve() {
  for (int i = START_IDX; i < END_IDX; ++i) {
    for (int j = START_IDX; j < END_IDX; ++j) {
      if (i == j) {
        continue;
      }

      if (!directedGraph[i][j]) {
        continue;
      }

      dfs(i, j);
    }
  }

  for (int i = START_IDX; i < END_IDX; ++i) {
    for (int j = START_IDX; j < END_IDX; ++j) {
      cout << visited[i][j] << " ";
    }
    cout << '\n';
  }

  return;
}

void dfs(int from, int to) {
  if (visited[from][to] == VISITED) {
    return;
  }

  visited[from][to] = VISITED;

  for (int i = START_IDX; i < END_IDX; ++i) {
    if (!directedGraph[to][i]) {
      continue;
    }

    dfs(from, i);
  }
}
