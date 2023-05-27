#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 1000000;

int n;
int arr[MAX_N];

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
  map<int, int> m;
  vector<int> a(arr, arr + n);

  sort(a.begin(), a.end());

  for (int i = 0, j = 0; i < n; ++i) {
    if (m.find(a[i]) == m.end()) {
      m[a[i]] = j++;
    }
  }

  map<int, int>::iterator iter;
  for (int i = 0; i < n; ++i) {
    iter = m.find(arr[i]);
    cout << iter->second << " ";
  }

  return;
}
