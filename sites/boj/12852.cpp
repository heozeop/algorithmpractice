#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int VALUE_LIMIT = 1000000 + 2;
const char DVIDER = ' ';

int n;
int minCalc[VALUE_LIMIT];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  fill(&minCalc[1], &minCalc[n + 1], VALUE_LIMIT);
}

bool isPushable(int val, int prevVal) {
  return val < n && prevVal < n && minCalc[val] > minCalc[prevVal] + 1;
}

bool isMinValue(int val) { return val == n; }

string getNextPath(int val, string path) {
  return to_string(val) + DVIDER + path;
}

string bfs() {
  queue<pair<int, string>> q;
  q.push(make_pair(1, "1"));
  minCalc[1] = 0;
  while (!q.empty()) {
    int val = q.front().first;
    string path = q.front().second;
    q.pop();

    int firstOperation = val * 3;
    int secondOperation = val * 2;
    int thirdOperation = val + 1;

    if (isMinValue(firstOperation)) {
      minCalc[n] = minCalc[val] + 1;
      return getNextPath(firstOperation, path);
    }
    if (isMinValue(secondOperation)) {
      minCalc[n] = minCalc[val] + 1;
      return getNextPath(secondOperation, path);
    }
    if (isMinValue(thirdOperation)) {
      minCalc[n] = minCalc[val] + 1;
      return getNextPath(thirdOperation, path);
    }

    if (isPushable(firstOperation, val)) {
      minCalc[firstOperation] = minCalc[val] + 1;
      q.push(make_pair(firstOperation, getNextPath(firstOperation, path)));
    }

    if (isPushable(secondOperation, val)) {
      minCalc[secondOperation] = minCalc[val] + 1;
      q.push(make_pair(secondOperation, getNextPath(secondOperation, path)));
    }

    if (isPushable(thirdOperation, val)) {
      minCalc[thirdOperation] = minCalc[val] + 1;
      q.push(make_pair(thirdOperation, getNextPath(thirdOperation, path)));
    }
  }
  return "1";
}

void solve() {
  string result = bfs();
  cout << minCalc[n] << endl << result;
}