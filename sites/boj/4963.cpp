#include <iostream>
using namespace std;

int map[100][100];

const int LAND = 1;
const int DEFAULTID = 10;

const int DIRECTION[8][2] = {
    {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1},
};

int w, h, n;

bool findIsland(int x, int y, int id) {
  if (map[x][y] != LAND || h <= x || w <= y || x < 0 || y < 0) {
    return false;
  } else if (map[x][y] == LAND) {
    map[x][y] = id;
  }

  for (int i = 0; i < 8; i++) {
    int row = x + DIRECTION[i][0];
    int col = y + DIRECTION[i][1];
    if (map[row][col] == LAND) {
      findIsland(row, col, id);
    }
  }
  return true;
}

int main(void) {
  while (1) {
    cin >> w >> h;

    if (w == 0 && h == 0)
      return 0;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> map[i][j];
      }
    }

    int numOfIsland = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (findIsland(i, j, numOfIsland + DEFAULTID)) {
          numOfIsland++;
        }
      }
    }
    cout << numOfIsland << '\n';
  }
}