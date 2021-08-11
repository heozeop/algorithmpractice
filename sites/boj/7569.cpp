#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 101;
const int FRESH = 0;
const int MEATURE = 1;
const int NONE = -1;

typedef struct _point {
  int x;
  int y;
  int z;
  int day;
} point;

const int directions[][3] = {
  {0, -1, 0},
  {0, 1, 0},
  {1, 0, 0},
  {-1, 0, 0},
  {0,0, 1},
  {0,0, -1},
};

queue<point> dailyTrace;
int box[MAX][MAX][MAX];
int numOfFreshes;
int lastDay;
int m, n, h;

bool isInsideBox(int x, int y, int z) {
  if(x < 0 || y < 0 || z < 0 || x >= m || y >= n || z >= h) {
    return false;
  }

  return true;
}

bool isFresh(int x, int y, int z) {
  if(box[z][y][x] == FRESH) {
    return true;
  }

  return false;
}

int bfs() {
  while(dailyTrace.size() > 0 && numOfFreshes > 0) {
    const point now = dailyTrace.front();
    dailyTrace.pop();
    lastDay = now.day;
    printf("x: %d, y: %d, z: %d, day: %d\n", now.x, now.y, now.z, now.day);

    for(auto i : directions) { 
      int nextX = now.x + i[0];
      int nextY = now.y + i[1];
      int nextZ = now.z + i[2];
      point nextPoint = {
          .x= nextX, 
          .y= nextY,
          .z = nextZ,
          .day= lastDay + 1
      };
      if(isInsideBox(nextX, nextY, nextZ) && isFresh(nextX, nextY, nextZ)) {
        box[nextZ][nextY][nextX] = MEATURE;
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
  cin >> m >> n >> h;
  for(int i = 0; i < h; ++i) {
    for(int j = 0; j < n; ++j) {
      for(int k = 0; k < m; ++k) {
        cin >> box[i][j][k];
        if(box[i][j][k] == FRESH) {
          ++numOfFreshes;
          continue;
        }

        point nextPoint = {
            .x= k, 
            .y= j,
            .z= i,
            .day= 0
        };

        if(box[i][j][k] == MEATURE) {
          dailyTrace.push(nextPoint);
        }
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