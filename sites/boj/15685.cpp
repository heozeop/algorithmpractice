#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <set>
#include <vector>

using namespace std;
const int MAX_SIZE = 101;
const int DIRECTION[4][2] = {
    {0, 1},  // R
    {-1, 0}, // T
    {0, -1}, // L
    {1, 0},  // B
};

set<pair<int, int>> s;
int n;

void input();
void solve();
void findAndSetDragonCurve(int, int, int, int);
void printDragonRectangle();
void turnVector(vector<pair<int, int>> &v);
bool isAllInSet(int, int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  int x, y, d, g;
  for (int i = 0; i < n; ++i) {
    cin >> y >> x >> d >> g;

    findAndSetDragonCurve(x, y, d, g);
  }
  return;
}

void solve() {
  printDragonRectangle();
  return;
}

void findAndSetDragonCurve(int x, int y, int d, int g) {
  vector<pair<int, int>> v;
  v.push_back({x, y});
  v.push_back({x + DIRECTION[d][0], y + DIRECTION[d][1]});

  for (int i = 1; i <= g; ++i) {
    turnVector(v);
  }

  for (auto i : v) {
    s.insert(i);
  }
}

void printDragonRectangle() {
  int count = 0;
  for (int i = 0; i < MAX_SIZE - 1; ++i) {
    for (int j = 0; j < MAX_SIZE - 1; ++j) {
      if (isAllInSet(i, j)) {
        count += 1;
      }
    }
  }

  cout << count;
}

bool isAllInSet(int x, int y) {
  if (s.find({x, y}) == s.end()) {
    return false;
  }
  if (s.find({x, y + 1}) == s.end()) {
    return false;
  }
  if (s.find({x + 1, y}) == s.end()) {
    return false;
  }
  if (s.find({x + 1, y + 1}) == s.end()) {
    return false;
  }

  return true;
}

void turnVector(vector<pair<int, int>> &v) {
  pair<int, int> center = v.back();

  for (int i = v.size() - 2; i >= 0; --i) {
    int ax = v[i].first - center.first;
    int ay = v[i].second - center.second;

    v.push_back({
        ay + center.first,
        -ax + center.second,
    });
  }
}
