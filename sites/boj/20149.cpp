#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

void input();
void solve();

pll p[4];
bool meetInOnePoint = false;
double x, y;

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

bool isSame(pll a, pll b) { return a.first == b.first && a.second == b.second; }

bool isCSameWithAB(pll a, pll b, pll c) {
  bool isSameWithA = isSame(a, c), isCbetweenB = isSame(b, c);
  if (isSameWithA || isCbetweenB) {
    return true;
  }

  return false;
}

bool isCbetweenAB(pll a, pll b, pll c) {
  // y = contant
  if (a.first == b.first) {
    if (c.first == a.first) {
      return (a.second < c.second && c.second < b.second) ||
             (b.second < c.second && c.second < a.second);
    }
    return false;
  }

  // x = contant
  if (a.second == b.second) {
    if (c.second == a.second) {
      return (a.first < c.first && c.first < b.first) ||
             (b.first < c.first && c.first < a.first);
    }
    return false;
  }

  if (a.first < c.first) {
    if (a.second < c.second) {
      return c.first < b.first && c.second < b.second;
    } else if (a.second > c.second) {
      return c.first < b.first && c.second > b.second;
    }
  } else if (a.first > c.first) {
    if (a.second < c.second) {
      return c.first > b.first && c.second < b.second;
    } else if (a.second > c.second) {
      return c.first > b.first && c.second > b.second;
    }
  }

  return false;
}

double getInclination(pll a, pll b) {
  ll ax = a.first - b.first, ay = a.second - b.second;
  if (ax && ay) {
    return (double)ay / ax;
  }

  return 0;
}

double calcOnPlatInclination(pll a, double alpha, bool forX) {
  if (forX) {
    return (y - a.second) / alpha + a.first;
  } else {
    return alpha * (x - a.first) + a.second;
  }
}

double getX(double alpha, double beta, pll a, pll b) {
  return (alpha * a.first - beta * b.first + b.second - a.second) /
         (alpha - beta);
}

double getY(double x, double alpha, pll a) {
  return alpha * (x - a.first) + a.second;
}

void findCrossPoint() {
  // 한 점이 같은 경우
  if (isCSameWithAB(p[0], p[1], p[2])) {
    x = p[2].first, y = p[2].second;
    return;
  }

  if (isCSameWithAB(p[0], p[1], p[3])) {
    x = p[3].first, y = p[3].second;
    return;
  }

  double alpha = getInclination(p[0], p[1]), beta = getInclination(p[2], p[3]);

  // 둘 중 하나라도 기울기가 0/무한 인 경우
  if (!alpha) {
    if (!beta) {
      // 둘 다 그럴 경우
      if (p[0].first == p[1].first) {
        x = p[0].first;
        y = p[2].second;
      } else {
        x = p[2].first;
        y = p[0].second;
      }
      return;
    }
    if (p[0].first == p[1].first) {
      x = p[0].first;
      y = calcOnPlatInclination(p[2], beta, false);
    } else if (p[0].second == p[1].second) {
      y = p[0].second;
      x = calcOnPlatInclination(p[2], beta, true);
    }

    return;
  } else if (!beta) {
    if (p[2].first == p[3].first) {
      x = p[2].first;
      y = calcOnPlatInclination(p[0], alpha, false);
    } else if (p[2].second == p[3].second) {
      y = p[2].second;
      x = calcOnPlatInclination(p[0], alpha, true);
    }

    return;
  }

  // 세점이 평행할 경우
  for (int i = 0; i < 4; ++i) {
    if (getY(p[i].first, alpha, p[0]) == getY(p[i].first, beta, p[2])) {
      x = p[i].first;
      y = p[i].second;
      return;
    }
  }

  // 평행하지  않는  그래프일 경우
  x = getX(alpha, beta, p[0], p[2]);
  y = getY(x, beta, p[2]);
}

void solve() {
  int a = ccw(p[0], p[1], p[2]), b = ccw(p[0], p[1], p[3]),
      c = ccw(p[2], p[3], p[0]), d = ccw(p[2], p[3], p[1]);

  if (a * b == 0 && c * d == 0) {
    bool one = isCSameWithAB(p[0], p[1], p[2]),
         two = isCSameWithAB(p[0], p[1], p[3]),
         three = isCbetweenAB(p[0], p[1], p[2]),
         four = isCbetweenAB(p[0], p[1], p[3]),
         five = isCbetweenAB(p[2], p[3], p[0]),
         six = isCbetweenAB(p[2], p[3], p[1]);
    bool isCross = one || two || three || four || five || six;
    cout << isCross;
    if (isCross) {
      double alpha = getInclination(p[0], p[1]),
             beta = getInclination(p[2], p[3]);
      if (alpha == beta) {
        if (!three && !four && !five && !six) {
          if (one && !two) {
            meetInOnePoint = true;
            x = p[2].first, y = p[2].second;
          } else if (!one && two) {
            meetInOnePoint = true;
            x = p[3].first, y = p[3].second;
          }
        }
      } else {
        if (one && !two) {
          meetInOnePoint = true;
          x = p[2].first, y = p[2].second;
        } else if (!one && two) {
          meetInOnePoint = true;
          x = p[3].first, y = p[3].second;
        }
      }
    };

  } else if (a * b <= 0 && c * d <= 0) {
    cout << 1;
    meetInOnePoint = true;
    findCrossPoint();
  } else {
    cout << 0;
  }

  if (meetInOnePoint) {
    if (x > floor(x) || y > floor(y)) {
      printf("\n%.10lf %.10lf\n", x, y);
    } else {
      cout << '\n' << x << ' ' << y;
    }
  }

  return;
}
