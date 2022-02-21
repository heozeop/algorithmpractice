#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef priority_queue<piii, vector<piii>, greater<piii>> pqPiii;

const int directions[4][2] = {
  {-1,0}, // top
  {0, 1}, // right
  {1, 0}, // bottom
  {0, -1} // left
};
const int islandNames[6] = {3,4,5,6,7,8};

void input();
void solve();

int n, m;
int countryMap[101][101];
int link[10];
bool visited[101][101];


int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> countryMap[i][j];
    }
  }
  return;
}

bool isOutOfBoundary(int x, int y) {
  return x < 0 || y < 0 || x >= n || y >= m;
}

void findIsland(int x, int y, int key) {
  if(isOutOfBoundary(x,y) || countryMap[x][y] != 1) {
    return;
  }

  countryMap[x][y] = key;
  for(int i = 0 ; i < 4; ++i) {
    findIsland(x + directions[i][0], y + directions[i][1], key);
  }
  return;
}

pii tryBridging(int x, int y, int direction) {
  int key = countryMap[x][y], length = 0;

  while(true) {
    x += directions[direction][0];
    y += directions[direction][1];
    if(isOutOfBoundary(x,y) || countryMap[x][y] != 0) break;
    length += 1;
  }

  if(isOutOfBoundary(x,y) || length < 2) {
    return {0,0};
  } 

  return {length, countryMap[x][y]};
}

pqPiii findBridges(int count, pii startPoints[]) {
  pqPiii q;
  pii tempPos;
  pii temp;
  for(int i = 0; i < count; i++) {
    queue<pii> nextPoint;

    nextPoint.push(startPoints[i]);
    while(!nextPoint.empty()) {
      tempPos = nextPoint.front();
      nextPoint.pop();
      visited[tempPos.first][tempPos.second] = true;
      
      for(int j = 0 ; j < 4; j++) {
        int nextX = tempPos.first + directions[j][0];
        int nextY = tempPos.second + directions[j][1];
        if(isOutOfBoundary(nextX, nextY) || visited[nextX][nextY]) {
          continue;
        }

        if(countryMap[nextX][nextY] == islandNames[i]) {
          nextPoint.push({ nextX, nextY });
          continue;
        }

        temp = tryBridging(tempPos.first, tempPos.second, j);
        if(temp.first) {
          q.push({temp.first, {islandNames[i], temp.second}});
        }
      }
    }
  }

  return q;
}

int find(int a) {
  if(link[a] == a) {
    return a;
  }
  return link[a] = find(link[a]);
}

bool merge(int a, int b) {
  a = find(a);
  b = find(b);

  if(a != b) {
    link[a] = b;
    return true;
  }

  return false;
}


void solve() {
  int islandCount = 0;
  pii islandStartPoint[6];
  for(int i = 0 ; i < n; i++) {
    for(int j = 0 ; j < m; j++) {
      if(countryMap[i][j] == 1) {
        islandStartPoint[islandCount] = {i,j};
        findIsland(i, j, islandNames[islandCount++]);
      }
    }
  }

  for(int i = 0 ; i < 10; i++) {
    link[i] = i;
  }

  pqPiii q = findBridges(islandCount, islandStartPoint);
  int count = 0, sum = 0;
  piii temp;
  while(!q.empty() && count < islandCount - 1) {
    temp = q.top();
    q.pop();
    if(merge(temp.second.first, temp.second.second)) {
      sum += temp.first;
      count += 1;
    }
  }

  if(count < islandCount - 1) {
    cout << - 1;
  } else {
    cout << sum;
  }

  return;
}
