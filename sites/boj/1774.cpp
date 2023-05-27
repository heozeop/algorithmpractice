#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int LIMIT_NODE_COUNT = 1001;
typedef pair<int, int> pii;
typedef pair<double, pair<int, int>> pdii;

pii stars[LIMIT_NODE_COUNT];
int links[LIMIT_NODE_COUNT];
int n, m;
priority_queue<pdii, vector<pdii>, greater<pdii>> q;

void input();
void solve();
double calcDistance(int, int);
int find(int);
bool merge(int, int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &stars[i].first, &stars[i].second);
    links[i] = i;
  }

  int a, b;
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &a, &b);
    merge(a, b);
  }
  return;
}

void solve() {
  if (n == 0) {
    printf("%.2f", 0.0f);
    return;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      q.push(make_pair(calcDistance(i, j), make_pair(i, j)));
    }
  }

  double minD = 0.0f;
  int curLength = 0;
  pdii temp;
  while (!q.empty() && curLength < n) {
    temp = q.top();
    q.pop();
    curLength = merge(temp.second.first, temp.second.second);
    if (curLength) {
      minD += temp.first;
      curLength += 1;
    }
  }

  printf("%.2f", minD);
  return;
}

double calcDistance(int a, int b) {
  double x = (stars[a].first - stars[b].first);
  double y = (stars[a].second - stars[b].second);

  return sqrt(x * x + y * y);
}

int find(int a) {
  if (links[a] == a) {
    return a;
  }

  return links[a] = find(links[a]);
}

bool merge(int a, int b) {
  int ap = find(a);
  int bp = find(b);

  if (ap != bp) {
    links[ap] = bp;
    return true;
  }

  return false;
}