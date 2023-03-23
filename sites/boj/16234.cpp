#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;
typedef pair<int, int> pii;
const int DIRECTION[3][2] = {
  {0, 1},
  {1, 0},
  {0, -1},
};

void input();
void solve();

int contries[51][51];
int n, l, r;
int findPopulation(pii,int, vector<vector<int>>&);
void refreshContries(vector<vector<int>>&, vector<int>&);
void init(vector<vector<int>>&, vector<int>&);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  scanf("%d %d %d", &n, &l, &r);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> contries[i][j];
    }
  }
  return;
}

void solve() {
  int count = 0;
  vector<vector<int>> unionMap(n + 1, vector<int>(n + 1, 0));
  vector<int> sumIdx(n * n + 1, 0);

  bool isUnionCreated = false;
  while(1) {
    int idx = 1;
    isUnionCreated = false;
    init(unionMap, sumIdx);
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if (unionMap[i][j] != 0) {
          continue;
        }

        sumIdx[idx] = findPopulation({i,j}, idx, unionMap);

        if (!isUnionCreated && sumIdx[idx] != contries[i][j]) {
          isUnionCreated = true;
        }

        idx+=1;
      }
    }

    if(!isUnionCreated) {
      break;
    }

    refreshContries(unionMap, sumIdx);
    count += 1;
  }

  cout << count;
  return;
}

bool canBeUnion(pii a, pii b) {
  int diff = abs(contries[a.first][a.second] - contries[b.first][b.second]);
  return diff <= r && diff >= l;
}

bool isMovable(int x, int y) {
  return x > 0 && x <= n && y > 0 && y <= n;
}

pii dfs(int x, int y, int idx, vector<vector<int>>& unionMap) {
  unionMap[x][y] = idx;
  int sum = contries[x][y];
  int count = 1;
  pii temp;
  int nx,ny;
  for(int i = 0; i < 3; ++i) {
    nx = x + DIRECTION[i][0];
    ny = y + DIRECTION[i][1];

    if(!isMovable(nx,ny) || unionMap[nx][ny] != 0 || !canBeUnion({x,y}, {nx,ny})) {
      continue;
    }

    temp = dfs(nx, ny, idx, unionMap);
    sum += temp.first;
    count += temp.second;
  }

  return {sum, count};
}

int findPopulation(pii p, int idx, vector<vector<int>>& unionMap) {
  pii val = dfs(p.first, p.second, idx, unionMap);

  return (int)(val.first / val.second);
}

void init(vector<vector<int>>& visit, vector<int>& sumIdx) {
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      visit[i][j] = 0;
    }
  }
}

void refreshContries(vector<vector<int>>& unionMap ,vector<int>& sumIdx) {
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      contries[i][j] = sumIdx[unionMap[i][j]];
    }
  }
}
