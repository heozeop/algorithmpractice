#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <set>
#include <vector>

using namespace std;

const int MAX_N = 16;

int n, m, d;
int arr[MAX_N][MAX_N];
int temparr[MAX_N][MAX_N];
bool visited[MAX_N];
int maxShot = 0;
vector<pair<int, int>> archerList;
vector<pair<int, int>> enemyList;

void input();
void solve();

void simulation();
void move();
int shot();
bool checkLeft();
void backtrack(int, int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m >> d;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> arr[i][j];
    }
  }

  return;
}

void solve() {
  backtrack(0, 0);

  cout << maxShot;
  return;
}

void backtrack(int idx, int numOfArcher) {
  if (numOfArcher == 3) {
    simulation();
    return;
  }

  for (int i = idx; i < m; ++i) {
    if (visited[i]) {
      continue;
    }

    archerList.push_back({n, i});
    visited[i] = true;
    backtrack(i, numOfArcher + 1);
    visited[i] = false;
    archerList.pop_back();
  }
}

void simulation() {
  enemyList.clear();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      temparr[i][j] = arr[i][j];
      if (arr[i][j]) {
        enemyList.push_back({i, j});
      }
    }
  }

  int localMaxShot = 0;
  while (checkLeft()) {
    localMaxShot += shot();
    move();
  }

  maxShot = max(localMaxShot, maxShot);
}

bool checkLeft() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (temparr[i][j]) {
        return true;
      }
    }
  }

  return false;
}

int shot() {
  set<int> killed;
  for (int i = 0; i < archerList.size(); ++i) {
    vector<pair<int, pair<int, pair<int, int>>>> temp;
    for (int j = 0; j < enemyList.size(); ++j) {
      int distance = abs(archerList[i].first - enemyList[j].first) +
                     abs(archerList[i].second - enemyList[j].second);

      if (distance > d) {
        continue;
      }

      temp.push_back(
          {distance, {enemyList[j].second, {-enemyList[j].first, j}}});
    }

    if (temp.size() < 1) {
      continue;
    }

    sort(temp.begin(), temp.end());
    killed.insert(temp[0].second.second.second);
  }

  vector<pair<int, int>> temp;
  for (int i = 0; i < enemyList.size(); ++i) {
    if (killed.find(i) != killed.end()) {
      temparr[enemyList[i].first][enemyList[i].second] = 0;
      continue;
    }

    temp.push_back(enemyList[i]);
  }

  enemyList.clear();
  for (auto i : temp) {
    enemyList.push_back(i);
  }

  return killed.size();
}

void move() {
  vector<pair<int, int>> v;
  for (int i = 0; i < enemyList.size(); ++i) {
    temparr[enemyList[i].first][enemyList[i].second] = 0;

    if (enemyList[i].first + 1 >= n) {
      continue;
    }

    v.push_back({enemyList[i].first + 1, enemyList[i].second});
  }

  enemyList.clear();
  for (auto i : v) {
    temparr[i.first][i.second] = 1;
    enemyList.push_back(i);
  }
}
