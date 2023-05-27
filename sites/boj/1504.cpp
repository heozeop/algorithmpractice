#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int NODE_SIZE_LIMIT = 801;
const int NODE_WEIGHT_LIMIT = 987654321;

int n, m;
int t1, t2;
vector<pair<int, int>> graph[NODE_SIZE_LIMIT];

void init() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }
  cin >> t1 >> t2;
}

vector<int> dijkstra(int startNode) {
  vector<int> minWeight(n + 1, NODE_WEIGHT_LIMIT);

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      minHeap;
  minWeight[startNode] = 0;
  minHeap.push(make_pair(0, startNode));

  while (!minHeap.empty()) {
    int weight = minHeap.top().first;
    int node = minHeap.top().second;
    minHeap.pop();

    if (minWeight[node] < weight)
      continue;

    for (int i = 0; i < graph[node].size(); ++i) {
      int nextNode = graph[node][i].first;
      int nextWeight = weight + graph[node][i].second;

      if (minWeight[nextNode] > nextWeight) {
        minWeight[nextNode] = nextWeight;
        minHeap.push(make_pair(nextWeight, nextNode));
      }
    }
  }

  return minWeight;
}

int solve() {
  vector<int> min1 = dijkstra(1);
  vector<int> minA = dijkstra(t1);
  vector<int> minB = dijkstra(t2);

  int path1 = min1[t1] + minA[t2] + minB[n];
  int path2 = min1[t2] + minB[t1] + minA[n];
  int answer = min(path1, path2);

  if (answer >= NODE_WEIGHT_LIMIT || answer < 0) {
    return -1;
  }

  return answer;
}

int main(void) {
  init();
  cout << solve() << endl;

  return 0;
}