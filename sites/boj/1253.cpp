#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int n;
int arr[2000];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  return;
}

void solve() {
  if (n < 2) {
    cout << 0;
    return;
  }

  map<int, int> arrMap;
  for (int i = 0; i < n; ++i) {
    if (arrMap.find(arr[i]) == arrMap.end()) {
      arrMap.insert({arr[i], 1});
    } else {
      arrMap[arr[i]] += 1;
    }
  }

  set<int> goodCandidates;

  int candidate, sameCount;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      candidate = arr[i] + arr[j];

      sameCount = 0;
      if (candidate == arr[i]) {
        sameCount += 1;
      }

      if (candidate == arr[j]) {
        sameCount += 1;
      }

      // 이거는 과하다. 0.0.0 막는건데 1개만 있어도 된다.
      if (arrMap.find(candidate)->second <= sameCount) {
        continue;
      }

      auto iter = goodCandidates.find(candidate);

      if (iter != goodCandidates.end()) {
        continue;
      }

      goodCandidates.insert(candidate);
    }
  }

  int numberOfGoodNumbers = 0;
  for (int i = 0; i < n; ++i) {
    auto iter = goodCandidates.find(arr[i]);

    if (iter == goodCandidates.end()) {
      continue;
    }

    numberOfGoodNumbers += 1;
  }

  cout << numberOfGoodNumbers;

  return;
}
