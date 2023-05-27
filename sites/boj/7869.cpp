#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<double, double> pdd;
typedef pair<pdd, double> circle;

void input();
void solve();

circle c[2];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  for (int i = 0; i < 2; ++i) {
    cin >> c[i].first.first >> c[i].first.second >> c[i].second;
  }
  return;
}

double getD(pdd a, pdd b) {
  double ax = a.first - b.first, ay = a.second - b.second;

  return sqrt(ax * ax + ay * ay);
}

void solve() {
  double d = getD(c[0].first, c[1].first);

  double a = c[0].second, b = c[1].second, temp;
  if (a > b) {
    temp = a;
    a = b;
    b = temp;
  }

  // 안만나는  경우
  if (a + b <= d) {
    cout << "0.000";
    return;
  }

  // 내부에 있는 경우
  if (d + a <= b) {
    printf("%.3lf", a * a * M_PI);
    return;
  }

  // 겹치는 경우
  double alpha = 2 * acos((d * d + a * a - b * b) / (2 * a * d)),
         beta = 2 * acos((d * d + b * b - a * a) / (2 * b * d));

  double ans = a * a * (alpha - sin(alpha)) + b * b * (beta - sin(beta));

  printf("%.3lf", ans / 2);
  return;
}
