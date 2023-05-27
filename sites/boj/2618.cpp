#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
const int POINT_NUM_LIMIT = 1000 + 1;
const int A_CAR = 1;
const int B_CAR = 2;

int n, w;
int dp[POINT_NUM_LIMIT][POINT_NUM_LIMIT];
pair<int, int> points[POINT_NUM_LIMIT];
pair<int, int> aP, bP;
int movement[POINT_NUM_LIMIT][POINT_NUM_LIMIT];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> w;
  for (int i = 1; i <= w; ++i) {
    cin >> points[i].first >> points[i].second;
  }
  aP = make_pair(1, 1);
  bP = make_pair(n, n);
}

int calcDistance(pair<int, int> one, pair<int, int> two) {
  return abs(one.first - two.first) + abs(one.second - two.second);
}

int dfs(int a, int b, int c) {
  if (a >= w || b >= w) {
    dp[a][b] = c;
    return c;
  }

  if (dp[a][b]) {
    return dp[a][b] + c;
  }

  int moveA, moveB, moveACost, moveBCost;

  int nextPoint = max(a, b) + 1;
  if (a == 0) {
    moveACost = calcDistance(aP, points[nextPoint]);
  } else {
    moveACost = calcDistance(points[a], points[nextPoint]);
  }

  if (b == 0) {
    moveBCost = calcDistance(bP, points[nextPoint]);
  } else {
    moveBCost = calcDistance(points[b], points[nextPoint]);
  }
  moveA = dfs(nextPoint, b, c + moveACost);
  moveB = dfs(a, nextPoint, c + moveBCost);

  dp[a][b] = min(moveA, moveB) - c;
  if (moveA < moveB) {
    movement[a][b] = A_CAR;
  } else {
    movement[a][b] = B_CAR;
  }

  return dp[a][b] + c;
}

void printPath() {
  int a, b;
  a = b = 0;
  while (a < w && b < w) {
    int nextPoint = max(a, b) + 1;
    cout << movement[a][b] << endl;
    if (movement[a][b] == B_CAR) {
      b = nextPoint;
    } else {
      a = nextPoint;
    }
  }
}

void solve() {
  cout << dfs(0, 0, 0) << endl;
  printPath();
}
