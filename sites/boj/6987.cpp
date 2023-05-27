#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

const int team1[15] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
const int team2[15] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5};

const int WIN = 0;
const int DREW = 1;
const int LOSE = 2;

int result[6][3];
int report[4][6][3];
int answer[4];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      for (int k = 0; k < 3; k++) {
        cin >> report[i][j][k];
      }
    }
  }
}

void dfs(int match) {
  if (match == 15) {
    for (int i = 0; i < 4; i++) {
      if (answer[i]) {
        continue;
      }
      bool diffFlag = false;

      for (int j = 0; j < 6; j++) {
        for (int k = 0; k < 3; k++) {
          if (report[i][j][k] != result[j][k]) {
            diffFlag = true;
            break;
          }
        }
        if (diffFlag) {
          break;
        }
      }

      if (!diffFlag) {
        answer[i] = 1;
      }
    }

    return;
  }

  int t1 = team1[match], t2 = team2[match];

  result[t1][WIN]++;
  result[t2][LOSE]++;
  dfs(match + 1);
  result[t1][WIN]--;
  result[t2][LOSE]--;

  result[t1][DREW]++;
  result[t2][DREW]++;
  dfs(match + 1);
  result[t1][DREW]--;
  result[t2][DREW]--;

  result[t1][LOSE]++;
  result[t2][WIN]++;
  dfs(match + 1);
  result[t1][LOSE]--;
  result[t2][WIN]--;
}

void solve() {
  dfs(0);

  for (int i = 0; i < 4; i++) {
    cout << answer[i] << " ";
  }

  return;
}
