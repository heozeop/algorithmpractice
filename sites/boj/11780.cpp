#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
const int CITY_NUM_LIMIT = 100 + 1;

int cityMap[CITY_NUM_LIMIT][CITY_NUM_LIMIT];
int middlePath[CITY_NUM_LIMIT][CITY_NUM_LIMIT];
int n, m;
vector<int> path;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  fill(&cityMap[0][0], &cityMap[n][n] + 1, INF);
  int x, y, z;
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", &x, &y, &z);
    if (cityMap[x][y] > z) {
      cityMap[x][y] = z;
    }
  }
}

void floydWarshall() {
  for (int i = 1; i <= n; ++i) {
    for (int from = 1; from <= n; ++from) {
      for (int to = 1; to <= n; ++to) {
        if (from == to)
          continue;
        if (cityMap[from][to] > cityMap[from][i] + cityMap[i][to]) {
          cityMap[from][to] = cityMap[from][i] + cityMap[i][to];
          middlePath[from][to] = i;
        }
      }
    }
  }
}

void findPath(int start, int end) {
  if (middlePath[start][end] == 0) {
    path.push_back(start);
    path.push_back(end);
    return;
  }
  findPath(start, middlePath[start][end]);
  path.pop_back();
  findPath(middlePath[start][end], end);
}

void solve() {
  floydWarshall();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (cityMap[i][j] == INF) {
        printf("0 ");
      } else {
        printf("%d ", cityMap[i][j]);
      }
    }
    cout << '\n';
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (cityMap[i][j] == INF) {
        printf("0\n");
        continue;
      }
      path.clear();
      findPath(i, j);
      printf("%d ", path.size());
      for (int k = 0; k < path.size(); ++k) {
        printf("%d ", path[k]);
      }
      printf("\n");
    }
  }
}