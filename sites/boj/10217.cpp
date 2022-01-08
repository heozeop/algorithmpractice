#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// floyd를 사용해서 비용과 소요시간을 계산해 봅니다.
// dijkstra로 찾을 경우, 비용과 시간의 가중치가 있어 제대로된 탐색이 불가할 수 있을 것 같습니다.
// dijkstra로 짜고, 두 지점을 함께 고려하면 어떻게 될까요? 어떤 지점 선택에 대해서 갈 수 있는지 고려하는 거죠.
// 이 접근의 단점은 초기 선택을 되돌릴 수 없다는 거에요.
// 그러면 벨만 포드?로 해보죠? 100 * 10000 이니까 시간 복잡도도 괜찮은 것 같아요!

const int INF = 987654321;
const int MAX = 101;
const int TIME = 0;
const int COST = 1;

int testcases;
int n, m, k;
vector<pair<int,int> > flyTime[MAX];
vector<pair<int,int> > flyCost[MAX];

void init(int n) {
  for(int i = 1; i <= n; ++i) {
    flyTime[i].clear();
    flyCost[i].clear();
  }
}

void input() {
  cin >> n >> m >> k;

  init(n);

  int u,v,c,d;
  for(int i = 0; i < k; ++i) {
    cin >> u >> v >> c >> d;
    flyTime[u].push_back(make_pair(v,d));
    flyCost[u].push_back(make_pair(v,c));
  }
}

pair<int, int> bellmanFord() {
  vector<int> times(n + 1, INF);
  vector<int> costs(n + 1, INF);
  bool updated;
  times[1] = 0;
  costs[1] = 0;
  for(int i = 0; i < n; ++i) {
    updated = false;

    for(int cur = 1; cur <= n; ++cur) {
      if(times[cur] == INF || costs[cur] > m) continue;

      for(int j = 0; j < flyTime[cur].size(); ++j) {
        int nextNode = flyTime[cur][j].first;
        int curTime =  times[cur] + flyTime[cur][j].second;
        int curCost =  costs[cur] + flyCost[cur][j].second;

        if(times[nextNode] > curTime && curCost <= m) {
          times[nextNode] = curTime;
          costs[nextNode] = curCost;
          updated = true;
        }
      }
    }

    if(!updated) break;
  }

  return make_pair(times[n], costs[n]);
}

void print(int timeVal, int costVal) {
  if(costVal > m) {
    cout << "Poor KCM\n";
    return;
  }

  cout << timeVal << "\n";
}

int main(void) {
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  cin >> testcases;

  pair<int, int> result;

  while(testcases--) {
    input();
    result = bellmanFord();
    print(result.first, result.second);
  }

  return 0;
}
