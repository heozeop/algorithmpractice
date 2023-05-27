#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

void input();
void solve();

pll p[4];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  for (int i = 0; i < 4; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  return;
}

int ccw(pll a, pll b, pll c) {
  ll pos = a.first * b.second + b.first * c.second + c.first * a.second;
  ll neg = c.first * b.second + b.first * a.second + a.first * c.second;

  ll result = pos - neg;

  if (result == 0) {
    return 0;
  }

  if (result > 0) {
    return 1;
  }

  return -1;
}

bool isCbetweenAB(pll a, pll b, pll c) {
  if (a.first == c.first && a.second == c.second) {
    return 1;
  }

  if (b.first == c.first && b.second == c.second) {
    return 1;
  }

  if (a.first <= c.first) {
    if (a.second <= c.second) {
      return c.first <= b.first && c.second <= b.second;
    } else {
      return c.first <= b.first && c.second >= b.second;
    }
  } else {
    if (a.second <= c.second) {
      return c.first >= b.first && c.second <= b.second;
    } else {
      return c.first >= b.first && c.second >= b.second;
    }
  }
}

void solve() {
  int a = ccw(p[0], p[1], p[2]), b = ccw(p[0], p[1], p[3]),
      c = ccw(p[2], p[3], p[0]), d = ccw(p[2], p[3], p[1]);

  if (a * b == 0 && c * d == 0) {
    cout << (isCbetweenAB(p[0], p[1], p[2]) || isCbetweenAB(p[0], p[1], p[3]) ||
             isCbetweenAB(p[2], p[3], p[0]) || isCbetweenAB(p[2], p[3], p[1]));
  } else if (a * b <= 0 && c * d <= 0) {
    cout << 1;
  } else {
    cout << 0;
  }

  return;
}
