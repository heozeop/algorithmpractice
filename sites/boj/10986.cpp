#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 1000000;
const int MAX_M = 1000;

int n, m;
int arr[MAX_N + 1];
int cnt[MAX_M + 1];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
  }

  return;
}

void solve() {

  // init sum
  int csum = 0;
  for (int i = 1; i <= n; ++i) {
    csum += arr[i];

    cnt[csum % m] += 1;
  }

  // travel with two pointer
  int mcount = 0;
  for (int i = 0; i <= MAX_M; ++i) {
    mcount += cnt[i] * (cnt[i] - 1) / 2;
  }

  cout << mcount + cnt[0]; // 조합 + 일반

  return;
}
