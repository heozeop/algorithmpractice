#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int INDEX_LIMIT = 100000 + 1;

int n, k;
// i번째 인덱스에 도달하는 가장 짧은 길
map<int, int> dp;
string shortestPath;

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

bool setOrNone(int key, int val) {
  bool needInsert = false;
  map<int, int>::iterator iter = dp.find(key);
  if (iter == dp.end()) {
    dp[key] = val + 1;
    needInsert = true;
  }
  return needInsert;
}

string getNextPath(string prevPath, int nextIndex) {
  return prevPath + " " + to_string(nextIndex);
}

void setDp() {
  queue<pair<int, string>> q;
  dp[n] = 1;
  q.push(make_pair(n, to_string(n)));
  while (!q.empty()) {
    int currentPosition = q.front().first;
    string path = q.front().second;
    q.pop();

    if (currentPosition == k) {
      shortestPath = path;
      break;
    }

    if (currentPosition < 0 || currentPosition > k + n) {
      continue;
    }

    if (setOrNone(currentPosition + 1, dp[currentPosition])) {
      q.push(make_pair(currentPosition + 1,
                       getNextPath(path, currentPosition + 1)));
    }
    if (currentPosition > 0 &&
        setOrNone(currentPosition - 1, dp[currentPosition])) {
      q.push(make_pair(currentPosition - 1,
                       getNextPath(path, currentPosition - 1)));
    }
    if (setOrNone(currentPosition * 2, dp[currentPosition])) {
      q.push(make_pair(currentPosition * 2,
                       getNextPath(path, currentPosition * 2)));
    }
  }
  return;
}

void solve() {
  if (k < n) {
    cout << n - k << endl;
    for (int i = n; i >= k; --i) {
      printf("%d ", i);
    }
    return;
  }

  setDp();
  cout << dp[k] - 1 << endl << shortestPath;

  return;
}