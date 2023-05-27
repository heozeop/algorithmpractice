#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<long long, long long> pll;

void input();
void solve();

pll p[4];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  for (int i = 0; i < 4; i++) {
    cin >> p[i].first >> p[i].second;
  }
  return;
}

int ccw(pll a, pll b, pll c) {
  long long temp = (a.first * b.second) + (b.first * c.second) +
                   (c.first * a.second) - (c.first * b.second) -
                   (b.first * a.second) - (a.first * c.second);
  if (temp < 0) {
    return 1;
  } else if (temp > 0) {
    return -1;
  } else {
    return 0;
  }
}

void solve() {
  int a = ccw(p[0], p[1], p[2]), b = ccw(p[0], p[1], p[3]),
      c = ccw(p[2], p[3], p[0]), d = ccw(p[2], p[3], p[1]);

  if (a * b <= 0 && c * d <= 0) {
    cout << 1;
  } else {
    cout << 0;
  }

  return;
}
