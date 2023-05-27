#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int ODD = 1;
const int EVEN = 0;
const int MAXSIZE = 500001;
const int NOTVISITED = -1;

int sReach[2][MAXSIZE] = {
    0,
};
queue<pair<int, int>> q;

int minEven = MAXSIZE, minOdd = MAXSIZE;

void setTime(int s, int time, int type) {

  if (sReach[type][s] == NOTVISITED) {
    sReach[type][s] = time;
    q.push(pair<int, int>(s, time));
  }
}

void bfs(int s) {
  memset(sReach, -1, sizeof(int) * MAXSIZE * 2);
  if (q.empty()) {
    q.push(pair<int, int>(s, 0));
    sReach[0][s] = 0;
  }
  while (!q.empty()) {
    int now = q.front().first;
    int nextTime = q.front().second + 1;
    q.pop();

    int type = EVEN;
    if (nextTime % 2 == ODD) {
      type = ODD;
    }

    if (now * 2 < MAXSIZE) {
      setTime(now * 2, nextTime, type);
    }

    if (now + 1 < MAXSIZE) {
      setTime(now + 1, nextTime, type);
    }

    if (now - 1 >= 0) {
      setTime(now - 1, nextTime, type);
    }
  }
  return;
}

void setMin(int k) {
  for (int i = k, t = 0; i < MAXSIZE; i = i + t) {
    if (sReach[EVEN][i] != NOTVISITED) {
      if (sReach[EVEN][i] <= t && (t - sReach[EVEN][i]) % 2 == 0) {
        minEven = min(minEven, t);
      }
    }

    if (sReach[ODD][i] != NOTVISITED) {
      if (sReach[ODD][i] <= t && (t - sReach[ODD][i]) % 2 == 0) {
        minOdd = min(minOdd, t);
      }
    }

    if (sReach[ODD][i] == t || sReach[ODD][i] == t) {
      break;
    }

    ++t;
  }
}

int solve(int s, int k) {

  bfs(s);

  setMin(k);

  int ans = min(minOdd, minEven);

  if (ans == MAXSIZE) {
    return -1;
  }

  return ans;
}

int main(void) {
  int s = 0, k = 0;
  cin >> s >> k;

  cout << solve(s, k);
  return 0;
}