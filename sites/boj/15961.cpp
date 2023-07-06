#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N =3000001;
const int MAX_D = 3001;

void input();
void solve();

int n, c, k, d;
int dishes[MAX_N];
int dishCount[MAX_D];
bool isCouponInSet();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> d >> k >> c;
  for (int i = 0; i < n; i++) {
    cin >> dishes[i];
  }

  return;
}

void solve() {
  int count = 0;
  deque<int> dishTypes;

  for(int i = 0; i < k; ++i) {
    dishTypes.push_back(dishes[i]);

    if(dishCount[dishes[i]] == 0) {
      count += 1;
    }
    dishCount[dishes[i]] += 1;
  }

  if (k == n) {
    cout << dishTypes.size() + !isCouponInSet();
    return;
  }

  int maxCount = 0;
  int startIdx = 0, endIdx = k - 1;
  for(startIdx = 0; startIdx < n; ++startIdx) {

    maxCount = max(maxCount, count + !isCouponInSet());

    endIdx += 1;
    endIdx %= n;


    dishCount[dishes[startIdx]] -= 1;
    dishTypes.pop_front();
    if (dishCount[dishes[startIdx]] == 0) {
      count -= 1;
    }

    if (dishCount[dishes[endIdx]] == 0) {
      count += 1;
    }
    dishTypes.push_back(dishes[endIdx]);
    dishCount[dishes[endIdx]] += 1;
  }

  cout << maxCount;

  return;
}

bool isCouponInSet() {
  return dishCount[c] >= 1;
}
