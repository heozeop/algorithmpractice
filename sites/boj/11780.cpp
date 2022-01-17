#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int CITY_NUM_LIMIT = 100 + 1;

int cityMap[CITY_NUM_LIMIT][CITY_NUM_LIMIT];
int middlePath[CITY_NUM_LIMIT][CITY_NUM_LIMIT];
int n, m;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input(){
  cin >> n >> m;
  fill(&cityMap[0][0], &cityMap[n][n] + 1, INF);
  int x, y, z;
  for(int i = 0; i < m; ++i) {
    scanf("%d %d %d", &x, &y, &z);
    cityMap[x][y] = z;
    cityMap[y][x] = z;
  }
}

void floydWarshall() {
  for(int i = 1; i <= n; ++i) {
    cityMap[i][i] = 0;
    for(int from = 1; from <= n; ++from) {
      for(int to = 1; to <= n; ++to) {
        if(cityMap[from][to] > cityMap[from][i] + cityMap[i][to]) {
          cityMap[from][to] = cityMap[from][i] + cityMap[i][to];
          middlePath[from][to] = i;
        }
      }
    }
  }
}

void solve() {
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      printf("%d ", cityMap[i][j]);
    }
    cout << '\n';
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      if(middlePath[i][j] == 0 || i == j) {
        printf("0\n");
        continue;
      }

      
    }
  }
}