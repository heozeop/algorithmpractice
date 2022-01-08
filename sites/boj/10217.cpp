#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// floyd를 사용해서 비용과 소요시간을 계산해 봅니다.
// dijkstra로 찾을 경우, 비용과 시간의 가중치가 있어 제대로된 탐색이 불가할 수 있을 것 같습니다.

const int INF = 987654321;
const int MAX = 101;
const int TIME = 0;
const int COST = 1;

int testcases;
int n, m, k;
int ports[2][MAX][MAX];

void init(int n) {
  fill(&ports[TIME][0][0], &ports[COST][n][n] + 1, INF);
}

void input() {
  cin >> n >> m >> k;

  init(n);

  int u,v,c,d;
  for(int i = 0; i < k; ++i) {
    cin >> u >> v >> c >> d;
    ports[COST][u][v] = c;
    ports[TIME][u][v] = d;
  }
}

bool isChangableTime(int from, int to, int iter) {
  return ports[TIME][from][to] > ports[TIME][from][iter] + ports[TIME][iter][to];
}

bool isTryableCost(int from, int to, int iter) {
  return ports[COST][from][iter] + ports[COST][iter][to] <= m;
}

void floydWarshall() {
  for(int iter = 1; iter <= n; ++iter) {
    for(int from = 1; from <= n; ++from) {
      for(int to = 1; to <= n; ++to) {
        if(isTryableCost(from, to, iter) && isChangableTime(from, to, iter)) {
          ports[TIME][from][to] = ports[TIME][from][iter] + ports[TIME][iter][to];
          ports[COST][from][to] = ports[COST][from][iter] + ports[COST][iter][to];
        }
      }
    }
  }
}

void print() {
  if(ports[COST][1][n] > m) {
    cout << "Poor KCM\n";
    return;
  }

  cout << ports[TIME][1][n] << "\n";
}

int main(void) {
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  cin >> testcases;

  while(testcases--) {
    input();
    floydWarshall();
    print();
  }

  return 0;
}
