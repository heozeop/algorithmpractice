#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

const int EMPTY = -1;
const int MAX_N = 1000000;
int n, k;

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
  if (k <= n) {
    cout << n - k;
    return;
  }

  int seconds = 0;
  queue<pair<int,int>> q;
  vector<int> arr(MAX_N, EMPTY);

  q.push({n, 0});
  int cur, sec, nc;
  while(!q.empty()) {
    cur = q.front().first;
    sec = q.front().second;
    q.pop();

    if(cur == k) {
      seconds = sec;
      break;
    }

    arr[cur] = sec;
    
    // 2배
    nc = cur * 2;
    while(nc <= k && arr[nc] == EMPTY) {
      q.push({nc, sec});
      nc *= 2;
    }

    // -1
    nc = cur - 1;
    if (arr[nc] == EMPTY && nc >= 0) {
      q.push({nc, sec+1});
    }

    // +1
    nc = cur + 1;
    if (arr[nc] == EMPTY && nc <= k) {
      q.push({nc, sec+1});
    }
  }

  cout << seconds;

  return;
}
