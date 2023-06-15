#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 200001;

int n, k;
bool visited[MAX_N];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> k;
  return;
}

void solve() {
  queue<pair<int, int>> q;
  q.push({0, n});
  visited[n] = true;

  int fastestTime = INT_MAX;
  int timeInSec, currentPos;
  int methodCount = 0;
  while (!q.empty()) {
    timeInSec = q.front().first;
    currentPos = q.front().second;
    q.pop();

    if (timeInSec > fastestTime) {
      continue;
    }

    if (currentPos == k) {
      fastestTime = timeInSec;
      methodCount += 1;
      continue;
    }
    visited[currentPos] = true;

    int nextPos = currentPos - 1;
    if (nextPos >= 0 && !visited[nextPos]) {
      q.push({timeInSec + 1, nextPos});
    }

    nextPos = currentPos + 1;
    if (nextPos <= 2 * k && !visited[nextPos]) {
      q.push({timeInSec + 1, nextPos});
    }

    nextPos = currentPos * 2;
    if (nextPos <= 2 * k && !visited[nextPos]) {
      q.push({timeInSec + 1, nextPos});
    }
  }

  cout << fastestTime << "\n" << methodCount;

  return;
}
