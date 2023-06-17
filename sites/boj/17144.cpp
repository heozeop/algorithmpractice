#include <algorithm>
#include <condition_variable>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

const int DIRECTION[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};
const int MAX_SIZE = 1000;
const int AIR_CONDITIONER = -1;
const int EMPTY = 0;

int r, c, t;
int room[MAX_SIZE][MAX_SIZE];
int spread[MAX_SIZE][MAX_SIZE];

int upperSideAirConditioner, lowerSideAirConditioner;

void input();
void solve();

void spreadDust();
void spreadDustOnPoint();
void conditioningAir();
int checkTheAmountOfDust();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> r >> c >> t;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> room[i][j];
    }
  }

  for (int i = 0; i < r; ++i) {
    if (room[i][0] != AIR_CONDITIONER) {
      continue;
    }

    if (upperSideAirConditioner == 0) {
      upperSideAirConditioner = i;
    } else {
      lowerSideAirConditioner = i;
      break;
    }
  }

  return;
}

void solve() {
  while (t--) {
    spreadDust();
    conditioningAir();
  }

  cout << checkTheAmountOfDust();
  return;
}

bool isInRoom(int x, int y) { return x >= 0 && y >= 0 && x < r && y < c; }

bool isAirConditioner(int x, int y) { return room[x][y] == AIR_CONDITIONER; }

bool isRoomEmpty(int x, int y) { return room[x][y] == EMPTY; }

void mergeAndInitDust() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (!spread[i][j]) {
        continue;
      }

      room[i][j] += spread[i][j];
      spread[i][j] = 0;
    }
  }
}

void spreadDust() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (isAirConditioner(i, j)) {
        continue;
      }

      if (isRoomEmpty(i, j)) {
        continue;
      }

      int amountToSpread = (int)(room[i][j] / 5);
      int spreadCount = 0;

      int nx, ny;
      for (int k = 0; k < 4; ++k) {
        nx = i + DIRECTION[k][0];
        ny = j + DIRECTION[k][1];

        if (!isInRoom(nx, ny)) {
          continue;
        }

        if (isAirConditioner(nx, ny)) {
          continue;
        }

        spreadCount += 1;
        spread[nx][ny] += amountToSpread;
      }

      room[i][j] -= spreadCount * amountToSpread;
    }
  }

  mergeAndInitDust();
}

void conditioningAir() {
  // 위쪽거
  for (int i = upperSideAirConditioner - 1; i > 0; --i) {
    room[i][0] = room[i - 1][0];
  }
  for (int i = 0; i < c - 1; ++i) {
    room[0][i] = room[0][i + 1];
  }
  for (int i = 0; i < upperSideAirConditioner; ++i) {
    room[i][c - 1] = room[i + 1][c - 1];
  }
  for (int i = c - 1; i > 1; --i) {
    room[upperSideAirConditioner][i] = room[upperSideAirConditioner][i - 1];
  }
  room[upperSideAirConditioner][1] = 0;

  // 아래거
  for (int i = lowerSideAirConditioner + 1; i < r - 1; ++i) {
    room[i][0] = room[i + 1][0];
  }
  for (int i = 0; i < c - 1; ++i) {
    room[r - 1][i] = room[r - 1][i + 1];
  }
  for (int i = r - 1; i > lowerSideAirConditioner; --i) {
    room[i][c - 1] = room[i - 1][c - 1];
  }
  for (int i = c - 1; i > 1; --i) {
    room[lowerSideAirConditioner][i] = room[lowerSideAirConditioner][i - 1];
  }
  room[lowerSideAirConditioner][1] = 0;
}

int checkTheAmountOfDust() {
  int amountOfDust = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (room[i][j] <= 0) {
        continue;
      }

      amountOfDust += room[i][j];
    }
  }

  return amountOfDust;
}
