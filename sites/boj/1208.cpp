#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 40;
typedef long long ll;

int n, s;
int arr[MAX_N];
map<ll, ll> sumVal;
ll countOfS;

void input();
void solve();
void leftStore(int curIdx, ll sum);
void rightStore(int curIdx, ll sum);

int main(void) {
  input();
  solve();

  return 0;
}

void input() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  return;
}

void solve() {
  leftStore(0, 0);
  rightStore(n / 2, 0);

  if (s == 0) {
    countOfS -= 1;
  }

  cout << countOfS;

  return;
}

void leftStore(int curIdx, ll sum) {
  if (curIdx == n / 2) {
    sumVal[sum]++;
    return;
  }

  leftStore(curIdx + 1, sum);
  leftStore(curIdx + 1, sum + arr[curIdx]);
}

void rightStore(int curIdx, ll sum) {
  if (curIdx == n) {
    countOfS += sumVal[s - sum];
    return;
  }

  rightStore(curIdx + 1, sum);
  rightStore(curIdx + 1, sum + arr[curIdx]);
}
