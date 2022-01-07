#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int NODE_SIZE_LIMIT = 801;
const int NODE_WEIGHT_LIMIT = 1001;
const int VISITED_NODE = 1;
const int NOTVISITED_NODE = 0;
typedef long long ll;

int n, m;
int t1, t2;
vector<pair<int, int> >graph[NODE_SIZE_LIMIT];

void init() {
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    graph[a].push_back(make_pair(b,c));
    graph[b].push_back(make_pair(a,c));
  }
  cin >> t1 >> t2;
}

void setMST(int startNode, int endNode, ll* minWeight, ll* visited) {
  priority_queue<pair<int, int>, vector<pair<int, int> > > minHeap;
  minWeight[startNode] = 0;
  minHeap.push(make_pair(0, startNode));
  while(minHeap.size() > 0) {
    int weight = -minHeap.top().first;
    int node = minHeap.top().second;
    visited[node] = VISITED_NODE;
    minHeap.pop();

    for(int i = 0; i < graph[node].size(); ++i) {
      int nextNode = graph[node][i].first;
      int nextWeight = graph[node][i].second;

      if(visited[nextNode] == 1) {
        continue;
      }

      int calcedWeight = weight + nextWeight;
      if(minWeight[nextNode] > calcedWeight) {
        minWeight[nextNode] = calcedWeight;
        minHeap.push(make_pair(-calcedWeight, nextNode));
      }
    }
  }
}

ll solve() {
  size_t size = sizeof(ll) * (n + 1);

  ll minWeight[NODE_SIZE_LIMIT];
  ll visited[NODE_SIZE_LIMIT];
  ll minWeight2[NODE_SIZE_LIMIT];
  ll visited2[NODE_SIZE_LIMIT];

  for(int i = 1; i <= n; ++i) {
    minWeight[i] = NODE_WEIGHT_LIMIT;
    minWeight2[i] = NODE_WEIGHT_LIMIT;
    visited[i] = NOTVISITED_NODE;
    visited2[i] = NOTVISITED_NODE;
  }

  // 1. 2 정점을 연결한 값을 찾는다.
  setMST(t1,t2,minWeight,visited);
  setMST(t2,t1,minWeight2,visited2);

  // 2. 모든 정점이 연결 되었는지 확인한다.
  bool isFirstNodeVisited = visited[1] == VISITED_NODE;
  bool isNthNodeVisited = visited[n] == VISITED_NODE;
  bool isT1NodeVisited = visited[t1] == VISITED_NODE;
  bool isT2NodeVisited = visited[t2] == VISITED_NODE;

  // 2.1 연결이 안된 노드가 있다면 -1을 리턴한다.
  if(!isFirstNodeVisited || !isNthNodeVisited || !isT1NodeVisited || !isT2NodeVisited) {
    return -1;
  }

  // 2.2 t1 -> t2의 최솟값을 저장한다.
  int minVal = minWeight[t2];

  // 3.1 1번 노드에서 부터의 최솟값을 찾는다.
  ll fromT1To1 = minWeight[1];
  ll fromT2To1 = minWeight2[1];
  minVal += fromT1To1 < fromT2To1 ? fromT1To1 : fromT2To1;

  // 3.2 N번 노드에서부터의 최솟값을 찾는다.
  ll fromT1ToN = minWeight[n];
  ll fromT2ToN = minWeight2[n];
  minVal += fromT1ToN < fromT2ToN ? fromT1ToN : fromT2ToN;

  return minVal;
}

int main(void) {
  init();
  cout << solve();

  return 0;
}