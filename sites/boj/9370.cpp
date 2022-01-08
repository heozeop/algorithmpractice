#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;
const int MAX_T = 101;
const int MAX_N = 2001;

int n, m, t;
int s, g, h;
int testcases;

vector<pair<int, int> > nodes[MAX_N];
vector<int> candidates;

void init(int numOfNode) {
  for(int i = 1; i <= numOfNode; ++i) {
    nodes[i].clear();
  }
  candidates.clear();
}

void input() {
  cin >> n >> m >> t;
  cin >> s >> g >> h;

  init(n);

  int a,b,c;
  for(int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    nodes[a].push_back(make_pair(b,c));
    nodes[b].push_back(make_pair(a,c));
  }

  int candidate;
  for(int i = 0; i < t; ++i) {
    cin >> candidate;
    candidates.push_back(candidate);
  }
}

vector<int> dijkstra(int start) {
  vector<int> minCost(n + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minHeap;
  minCost[start] = 0;
  minHeap.push(make_pair(start, 0));

  while(!minHeap.empty()) {
    int nextNode = minHeap.top().first;
    int nextCost = minHeap.top().second;
    minHeap.pop();

    if(minCost[nextNode] < nextCost) {
      continue;
    }

    for(int i = 0; i < nodes[nextNode].size(); ++i) {
      int possibleNextNode = nodes[nextNode][i].first;
      int possibleNextCost = nextCost + nodes[nextNode][i].second;

      if(minCost[possibleNextNode] > possibleNextCost) {
        minCost[possibleNextNode] = possibleNextCost;
        minHeap.push(make_pair(possibleNextNode, possibleNextCost));
      }
    }
  }

  return minCost;
}

void print(vector<int> costs) {
  for(int i = 0; i < costs.size(); ++i) {
    cout << costs[i] << " ";
  }
}

bool isNotReachable(int node, int goal) {
  for(int i = 0; i < nodes[node].size(); ++i) {
    if(nodes[node][i].first == goal) {
      return false;
    }
  }

  return true;
}

void solve() {
  vector<int> fromStart = dijkstra(s);
  vector<int> fromG = dijkstra(g);
  vector<int> fromH = dijkstra(h);

  sort(candidates.begin(), candidates.end());
  vector<int> costs;
  for(int i = 0; i < candidates.size(); ++i) {
    int goal = candidates[i];

    int startToGoal = fromStart[goal];
    int path1 = fromStart[g] + fromG[h] + fromH[goal];
    int path2 = fromStart[h] + fromH[g] + fromG[goal];

    if(startToGoal == path1 || startToGoal == path2) {
      costs.push_back(goal);
    }
  }
  print(costs);
}

int main(void) {
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  cin >> testcases;
  while(testcases--) {
    input();
    solve();
    cout << '\n';
  }
  return 0;
}

