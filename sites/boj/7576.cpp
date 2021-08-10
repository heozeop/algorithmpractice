#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 1001;
const int FRESH = 0;
const int MEATURE = 1;
const int NONE = -1;

typedef struct _point {
  int x;
  int y;
  int day;
} point;

const int directions[][4] = {
  {0, -1},
  {1, 0},
  {0, 1},
  {-1, 0}
};

queue<point> dailyTrace;
int box[MAX][MAX];
int numOfFreshes;
int lastDay;
int m, n;

bool isInsideBox(int x, int y) {
  if(x < 0 || y < 0 || x >= m || y >= n) {
    return false;
  }

  return true;
}

bool isFresh(int x, int y) {
  if(box[y][x] == FRESH) {
    return true;
  }

  return false;
}

int bfs() {
  while(dailyTrace.size() > 0 && numOfFreshes > 0) {
    const point now = dailyTrace.front();
    dailyTrace.pop();
    lastDay = now.day;

    for(auto i : directions) { 
      int nextX = now.x + i[0];
      int nextY = now.y + i[1];
      point nextPoint = {
          .x= nextX, 
          .y= nextY,
          .day= lastDay + 1
      };
      if(isInsideBox(nextX, nextY) && isFresh(nextX, nextY)) {
        box[nextY][nextX] = MEATURE;
        dailyTrace.push(nextPoint);
        --numOfFreshes;
      }
    }
  }

  if(numOfFreshes > 0) {
    return -1;
  }

  return lastDay + 1;
}

int main(void) {
  // init 
  cin >> m >> n;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> box[i][j];
      if(box[i][j] == FRESH) {
        ++numOfFreshes;
      }

      point nextPoint = {
          .x= j, 
          .y= i,
          .day= 0
      };

      if(box[i][j] == MEATURE) {
        dailyTrace.push(nextPoint);
      }
    }
  }
  if(numOfFreshes == 0) {
    cout << 0 << endl;
    return 0;
  }

  if(dailyTrace.size() < 1) {
    cout << -1 << endl;
    return 0;
  }

  cout << bfs() << endl;
  return 0;
}