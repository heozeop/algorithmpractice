#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

class point {
public:
  int x, y;
  point(int x, int y) : x(x), y(y) {}
};

const int KNIGHT_MOVE[][2] = {{-1, 2}, {1, 2},   {2, 1},   {2, -1},
                              {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}};

const int MAX = 301;
const int NOT_VISITED = -1;

int boardSize, testcase;
int currentX, currentY;
int targetX, targetY;
int dp[MAX][MAX];
// 판 초기화 하는거 필요
void initiateBoard() {
  cin >> boardSize >> currentX >> currentY >> targetX >> targetY;

  for (int i = 0; i < boardSize; ++i) {
    for (int j = 0; j < boardSize; ++j) {
      dp[i][j] = NOT_VISITED;
    }
  }
  dp[currentX][currentY] = 0;
}
// 판 내부 인거 확인
bool isInsideBoard(int x, int y) {
  if (x < 0 || y < 0 || x >= boardSize || y >= boardSize) {
    return false;
  }

  return true;
}

bool isFirstVisit(int x, int y) { return dp[x][y] == NOT_VISITED; }

bool isOnTarget(int x, int y) { return x == targetX && y == targetY; }

// 판 최초 방문 리턴
int bfs() {
  queue<point> points;
  points.push(point(currentX, currentY));
  while (points.size() > 0) {
    point prevPoint = points.front();
    points.pop();

    if (isOnTarget(prevPoint.x, prevPoint.y)) {
      return dp[prevPoint.x][prevPoint.y];
    }

    for (auto i : KNIGHT_MOVE) {
      int nextX = prevPoint.x + i[0];
      int nextY = prevPoint.y + i[1];

      if (!isInsideBoard(nextX, nextY) || !isFirstVisit(nextX, nextY)) {
        continue;
      }

      dp[nextX][nextY] = dp[prevPoint.x][prevPoint.y] + 1;
      points.push(point(nextX, nextY));
    }
  }

  return -1;
}

int main(void) {
  cin >> testcase;

  while (testcase-- > 0) {
    initiateBoard();
    cout << bfs() << endl;
  }
}