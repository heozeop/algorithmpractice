#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int n;
int t;
int arr[100];

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
  cin >> t;
  return;
}

void solve() {
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == t) {
      count += 1;
    }
  }

  cout << count;

  return;
}
