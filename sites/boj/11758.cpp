#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

pair<int, int> points[3];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  for (int i = 0; i < 3; i++) {
    cin >> points[i].first >> points[i].second;
  }

  return;
}

void solve() {
  int ccw =
      points[0].first * points[1].second + points[1].first * points[2].second +
      points[2].first * points[0].second - points[2].first * points[1].second -
      points[1].first * points[0].second - points[0].first * points[2].second;
  if (ccw == 0) {
    cout << 0;
  } else if (ccw > 0) {
    cout << 1;
  } else {
    cout << -1;
  }

  return;
}
