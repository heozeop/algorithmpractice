#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 100;

int n;
int a[MAX_N];
int b[MAX_N];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n;

  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for(int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  return; 
}

void solve() { 
  sort(a, a + n);
  sort(b, b + n);

  int sum = 0;
  for(int i = 0; i < n; ++i) {
    sum += a[n - 1 - i] * b[i];
  }
  cout << sum;
  return; 
}
