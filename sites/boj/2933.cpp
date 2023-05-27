#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void input();
void solve();

typedef pair<int, int> pii;
typedef pair<bool, int> pbi;

const char MINERAL = 'x';
const char EMPTY_SPACE = '.';
const int direction[4][4] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

int r, c, n;
char caveMap[101][101];
bool visit[101][101];
int throwHeight[101];

pbi throwStick(int height, int playerIdx);
int countFallAmount(int row, int col);
pbi getFallInfo(int row, int col);
void fallDown(int row, int col, int amount);

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  input();
  solve();
  return 0;
}

void input() {
  cin >> r >> c;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> caveMap[i][j];
    }
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> throwHeight[i];
  }

  return;
}

pbi throwStick(int height, int playerIdx) {
  pbi answer;
  answer.first = false;
  int startCol = 1, endCol = c;
  int checkDirection = 1;

  if (playerIdx % 2 == 0) {
    startCol = c;
    endCol = 1;
    checkDirection = -1;
  }

  while (startCol != endCol) {
    if (caveMap[height][startCol] == MINERAL) {
      caveMap[height][startCol] = EMPTY_SPACE;
      answer.first = true;
      answer.second = startCol;
      break;
    }

    startCol += checkDirection;
  }

  return answer;
}

int countFallAmount(int row, int col) {
  int fallCount = 0;
  while (row > 0 && caveMap[row][col] == MINERAL) {
    row++;
  }
  while (row > 0 && caveMap[row][col] == EMPTY_SPACE) {
    fallCount++;
    row++;
  }
  return fallCount;
}

pbi getFallInfo(int row, int col) {
  pbi answer;

  if (caveMap[row][col] == EMPTY_SPACE) {
    return {true, 0};
  }
  answer.first = false;
  answer.second = countFallAmount(row + 1, col);

  memset(visit, false, sizeof(visit));
  vector<bool> counting(c, true);

  queue<pii> q;
  q.push({row, col});

  while (!q.empty()) {
    pii curP = q.front();
    q.pop();
    visit[curP.first][curP.second] = true;
    if (curP.first == r) {
      answer.first = true;
      break;
    }

    if (counting[col]) {
      answer.second =
          min(answer.second, countFallAmount(curP.first, curP.second));
      counting[col] = false;
    }

    for (int i = 0; i < 4; i++) {
      int nextR = curP.first + direction[i][0],
          nextC = curP.second + direction[i][1];
      if (visit[nextR][nextC])
        continue;

      if (caveMap[nextR][nextC] == MINERAL) {
        q.push({nextR, nextC});
      }
    }
  }

  return answer;
}

void fallDown(int row, int col, int amount) {
  memset(visit, false, sizeof(bool) * (r + 1) * (c + 1));
  queue<pii> q;
  q.push({row, col});

  while (!q.empty()) {
    pii curP = q.front();
    q.pop();
    visit[curP.first][curP.second] = true;

    caveMap[curP.first][curP.second] = EMPTY_SPACE;
    caveMap[curP.first + amount][curP.second] = MINERAL;
    visit[curP.first + amount][curP.second] = true;

    for (int i = 0; i < 4; i++) {
      int nextR = curP.first + direction[i][0],
          nextC = curP.second + direction[i][1];
      if (visit[nextR][nextC])
        continue;

      if (caveMap[nextR][nextC] == MINERAL) {
        q.push({nextR, nextC});
      }
    }
  }
}

void printing() {
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cout << caveMap[i][j] << " ";
    }
    cout << "\n";
  }
}

void solve() {
  for (int i = 1; i <= n; i++) {
    int row = (r - throwHeight[i] + 1);
    auto pb = throwStick(row, i % 2);
    int col = pb.second;

    if (!pb.first) {
      continue;
    }

    auto horizontalPos = getFallInfo(row, col + (i % 2 == 0 ? -1 : 1));
    if (!horizontalPos.first) {
      fallDown(row, col + (i % 2 == 0 ? -1 : 1), horizontalPos.second);
    }
    auto verticalPos = getFallInfo(row - 1, col);
    if (!verticalPos.first) {
      fallDown(row - 1, col, verticalPos.second);
    }
  }
  printing();
  return;
}
