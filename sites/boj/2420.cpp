#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

long long a, b;
void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { cin >> a >> b;return; }

void solve() { cout << abs(a - b);return; }
