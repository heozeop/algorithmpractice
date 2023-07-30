#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 1001;

int n;
int arr[MAX_N];
int minDp[MAX_N];
int maxDp[MAX_N];

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

void solve() { return; }
