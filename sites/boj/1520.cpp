#include <iostream>

using namespace std;

const int MAX = 501;
const int NOT_VISITED = -1;
const int DIRECTION[][2] = {
  {-1, 0},
  {0, 1},
  {1, 0},
  {0, -1}
};

int map[MAX][MAX];
int dp[MAX][MAX];
int n,m;

bool isOutOfBoundary(int row, int col) {
  const bool isLowerBounded = row <= 0 || col <= 0;
  const bool isHigherBounded = row > m || col > n;

  if(isLowerBounded || isHigherBounded) {
    return true;
  }

  return false;
}

bool isVisited(int row, int col) {
  return dp[row][col] != NOT_VISITED;
}

bool isReached(int row, int col) {
  return row == m && col == n;
}

int getPositionValue(int row, int col) {
  return map[row][col];
}

int countPath(int row, int col) {
  if(isOutOfBoundary(row, col)) {
    return 0;
  }

  if(isReached(row, col)) {
    return 1;
  }

  if(isVisited(row, col)) {
    return dp[row][col];
  }

  dp[row][col] = 0;
  const int currentVal = getPositionValue(row, col);
  for(int i = 0; i < 4; i += 1) {
    const int nextRow = row+DIRECTION[i][0];
    const int nextCol = col + DIRECTION[i][1];
    if(isOutOfBoundary(nextRow, nextCol)) {
      continue;
    }

    const int nextVal = getPositionValue(nextRow, nextCol);
    if(currentVal > nextVal) {
      dp[row][col] += countPath(nextRow, nextCol);
    }
  }

  return dp[row][col];
}

int main(void) {
  cin >> m >> n;
  for(int i = 1; i <= m; i += 1) {
    for(int j = 1; j <= n; j+=1) {
      cin >> map[i][j];
      dp[i][j] = NOT_VISITED;
    }
  }

  cout << countPath(1,1) << endl;

  return 0;
}
