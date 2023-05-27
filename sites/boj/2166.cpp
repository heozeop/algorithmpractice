#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int LIMIT_NODE_COUNT = 10001;
typedef pair<long long, long long> pll;

void input();
void solve();

int n;
pll polygon[LIMIT_NODE_COUNT];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> polygon[i].first >> polygon[i].second;
  }
  return;
}

long long ccw(pll a, pll b, pll c) {
  return 1LL * (a.first * b.second) + (b.first * c.second) +
         (c.first * a.second) - (b.first * a.second) - (c.first * b.second) -
         (a.first * c.second);
}

double getArea() {
  long long sum = 0;
  for (int i = 1; i < n - 1; ++i) {
    sum += ccw(polygon[0], polygon[i], polygon[i + 1]);
  }

  return sum / (double)2;
}

void solve() {
  double result = abs(getArea());
  printf("%.1lf", result);
  return;
}
