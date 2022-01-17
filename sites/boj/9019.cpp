#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int VALUE_LIMIT = 10000;

int T, A, B;
int dp[VALUE_LIMIT];

void solve();
void init();

int main(void) {
  cin >> T;
  while(T--) {
    cin >> A >> B;
    init();
    solve();
  }
  return 0;
}

void init() {
  fill(&dp[0], &dp[VALUE_LIMIT - 1] + 1, VALUE_LIMIT);
}

int calcD(int n) {
  return n * 2 % VALUE_LIMIT;
}

int calcS(int n) {
  if(n == 0) {
    return 9999;
  }
  return n - 1;
}

int calcL(int n) {
  return (n % 1000) * 10 + n / 1000;
}

int calcR(int n) {
  return (n % 10) * 1000 + n / 10;
}

string gogogo() {
  queue<pair<int, string> > q;
  q.push(make_pair(A, ""));
  dp[A] = 0;

  while(!q.empty()) {
    int curVal = q.front().first;
    string currentPath = q.front().second;
    int currentStepCount = dp[curVal];
    q.pop();

    if(curVal == B) {
      return currentPath;
    }

    int afterD = calcD(curVal), afterS = calcS(curVal), afterL = calcL(curVal), afterR = calcR(curVal);
    if(dp[afterD] > currentStepCount + 1) {
      dp[afterD] = currentStepCount + 1;
      q.push(make_pair(afterD, currentPath + "D"));
    }
    if(dp[afterS] > currentStepCount + 1) {
      dp[afterS] = currentStepCount + 1;
      q.push(make_pair(afterS, currentPath + "S"));
    }
    if(dp[afterL] > currentStepCount + 1) {
      dp[afterL] = currentStepCount + 1;
      q.push(make_pair(afterL, currentPath + "L"));
    }
    if(dp[afterR] > currentStepCount + 1) {
      dp[afterR] = currentStepCount + 1;
      q.push(make_pair(afterR, currentPath + "R"));
    }
  }
  return "";
}

void solve() {
  string minPath = gogogo();
  cout << minPath << endl;
  return;
}