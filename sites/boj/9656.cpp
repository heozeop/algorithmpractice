#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int n;
void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  return;
}

void solve() {
  if (n % 2) {
    cout << "CY";
  } else {
    cout << "SK";
  }
  return;
}
