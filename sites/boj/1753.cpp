#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_VERTEX_SIZE = 20001;
const int MAX_EDGE_SIZE = 300000;
const int INF = 11 * MAX_EDGE_SIZE;

vector<pair<int,int> >values[MAX_VERTEX_SIZE];
int minValues[MAX_VERTEX_SIZE];
int visitedVertices[MAX_VERTEX_SIZE];
int v, e;
int startVertexNumber;


void init() {
  // 기준값 입력
  cin >> v >> e >> startVertexNumber;

  // 최솟값 초기화
  for(int i = 1; i <= v; ++i) {
    minValues[i] = INF;
  }
  minValues[startVertexNumber] = 0;
  visitedVertices[startVertexNumber] = 1;

  // 엣지 입력
  for (int i = 0; i < e; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    values[u].push_back(make_pair(v,w));
  }
}

void calcMinValues() {
  priority_queue<pair<int, int>, vector<pair<int, int> > >minHeap;
  minHeap.push(make_pair(0, startVertexNumber));

  while (minHeap.size() > 0) {
    int cost = -minHeap.top().first;
    int index = minHeap.top().second;
    visitedVertices[index] = 1;
    minHeap.pop();

    for(int i = 0; i < values[index].size(); ++i) {
      int nextIndex = values[index][i].first;
      int value = values[index][i].second;

      if(visitedVertices[nextIndex] == 1) {
        continue;
      }

      int throughPathWeight = cost + value;
      if(minValues[nextIndex] > throughPathWeight) {
        minValues[nextIndex] = throughPathWeight;
        minHeap.push(make_pair(-throughPathWeight, nextIndex));
      }
    }
  }
}

// 가장 적은 비용들을 출력합니다.
void printMinWeights() {
  for (int i = 1; i <= v; ++i) {
    if (minValues[i] < INF) {
      cout << minValues[i] << endl;
    } else {
      cout << "INF" << endl;
    }
  }
}

int main(void) {
  init();
  calcMinValues();
  printMinWeights();
  return 0;
}
