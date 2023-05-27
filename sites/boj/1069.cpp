#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

int x, y, d, t;

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> x >> y >> d >> t;
  return;
}

void solve() {
  double distance = sqrt(x * x + y * y);
  double ans = distance;

  int jumpCount = distance / d;
  double left = distance - jumpCount * d;
  ans = min(ans, left + jumpCount * t);
  ans = min(ans, d - left + (jumpCount + 1) * t);
  if (distance < d) {
    ans = min(ans, 2.0 * t);
  } else {
    ans = min(ans, (double)(jumpCount + 1) * t);
  }

  printf("%.10lf", ans);
  return;
}
