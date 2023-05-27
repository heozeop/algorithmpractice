#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int VISITED = 10;
const int MAXSIZE = 10;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int mab[MAXSIZE][MAXSIZE] = {
    0,
};
int numOfZero = 0;
int tempOfZero = 0;
int n = 0, m = 0;
vector<pair<int, int>> virus;

void bfs(int row, int col, int tmMab[MAXSIZE][MAXSIZE]) {
  queue<pair<int, int>> q;

  q.push(pair<int, int>(row, col));

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int newRow = x + dx[i];
      int newCol = y + dy[i];

      if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
          mab[newRow][newCol] == 0 && tmMab[newRow][newCol] != VISITED) {
        tmMab[newRow][newCol] = VISITED;
        tempOfZero++;
        q.push(pair<int, int>(newRow, newCol));
      }
    }
  }
}

void setZeros() {
  int tmMab[MAXSIZE][MAXSIZE] = {
      0,
  };
  tempOfZero = 0;
  for (int l = 0; l < virus.size(); l++) {
    bfs(virus[l].first, virus[l].second, tmMab);
  }
}

int find() {
  int minZeros = 10000000;
  for (int i = 0; i < n * m; i++) {
    if (mab[i / m][i % m] == 0) {
      mab[i / m][i % m] = 1;
      for (int j = i + 1; j < n * m; j++) {
        if (mab[j / m][j % m] == 0) {
          mab[j / m][j % m] = 1;
          for (int k = j + 1; k < n * m; k++) {
            if (mab[k / m][k % m] == 0) {
              mab[k / m][k % m] = 1;

              setZeros();
              minZeros = min(minZeros, tempOfZero);

              mab[k / m][k % m] = 0;
            }
          }
          mab[j / m][j % m] = 0;
        }
      }
      mab[i / m][i % m] = 0;
    }
  }
  return numOfZero - minZeros - 3; //º®¼¼°³
}

int main(void) {

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int tm = 0;
      cin >> tm;
      mab[i][j] = tm;
      if (tm == 2) {
        virus.push_back(pair<int, int>(i, j));
      }
      if (tm == 0) {
        numOfZero++;
      }
    }
  }

  cout << find();
}