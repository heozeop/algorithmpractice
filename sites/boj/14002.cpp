#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int VALUE_LIMIT = 1000000000 + 1;
const int INDEX_LIMIT = 1000000 + 1;

int n;
int numArray[INDEX_LIMIT];
int numIndexPath[INDEX_LIMIT];
vector<int> dp;
bool needRefresh;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> numArray[i];
  }
}

int search(int val) {
  int startIndex = 0, endIndex = dp.size() - 1;
  int middleIndex;
  while (startIndex < endIndex) {
    middleIndex = (startIndex + endIndex) / 2;

    if (val <= dp[middleIndex]) {
      endIndex = middleIndex;
    } else {
      startIndex = middleIndex + 1;
    }
  }
  return startIndex;
}

void refreshPath() {
  for (int i = 1; i <= dp.size(); ++i) {
    numIndexPath[i] = dp[i - 1];
  }
}

void setDP() {
  int location = 0;
  needRefresh = false;
  dp.push_back(numArray[1]);
  for (int i = 2; i <= n; ++i) {
    int currentNum = numArray[i];
    if (currentNum > dp.back()) {
      dp.push_back(currentNum);
      if (needRefresh) {
        refreshPath();
        needRefresh = false;
      } else {
        numIndexPath[dp.size()] = currentNum;
      }
    } else {
      location = search(currentNum);
      dp[location] = currentNum;
      needRefresh = true;
    }
  }
}

void solve() {
  setDP();
  cout << dp.size() << endl;
  for (int i = 1; i <= dp.size(); ++i) {
    printf("%d ", numIndexPath[i]);
  }
}