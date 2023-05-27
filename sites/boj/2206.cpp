#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1001;
const int WALL = 1;
const int ROAD = 0;

typedef struct _move {
  int x;
  int y;
  int breakable;
} moving;

const int DIRECTIONS[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int m, n;
char map[MAX][MAX];
int visitMap[MAX][MAX][2] = {
    0,
};

bool isInside(int check, int min, int max) {
  if (check < min || check >= max) {
    return false;
  }

  return true;
}

int bfs() {
  queue<moving> tries;
  moving start = {
      .x = 0,
      .y = 0,
      .breakable = 0,
  };
  visitMap[0][0][0] = 1;

  tries.push(start);

  while (!tries.empty()) {
    auto prev = tries.front();
    tries.pop();

    if (prev.x == m - 1 && prev.y == n - 1) {
      return max(visitMap[prev.y][prev.x][0], visitMap[prev.y][prev.x][1]);
    }

    for (auto i : DIRECTIONS) {
      int nextX = prev.x + i[0];
      int nextY = prev.y + i[1];
      int nextBreakable = prev.breakable;

      if (!isInside(nextX, 0, m) || !isInside(nextY, 0, n)) {
        continue;
      }

      if (map[nextY][nextX] == WALL) {
        if (prev.breakable == 1) {
          continue;
        }
        nextBreakable = 1;
      }

      if (visitMap[nextY][nextX][nextBreakable] != 0) {
        continue;
      }

      moving nextMoving = {
          .x = nextX,
          .y = nextY,
          .breakable = nextBreakable,
      };

      visitMap[nextY][nextX][nextBreakable] =
          visitMap[prev.y][prev.x][prev.breakable] + 1;
      tries.push(nextMoving);
    }
  }

  return -1;
}

int main(void) {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d", &map[i][j]);
    }
  }
  cout << bfs() << endl;
}