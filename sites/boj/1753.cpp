#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_VERTEX_SIZE = 20001;
const int MAX_EDGE_SIZE = 300000;
const int INF = 11 * MAX_EDGE_SIZE;

// map<pair<int,int>, int> values;
map<int,int>values[MAX_VERTEX_SIZE];
int minValues[MAX_VERTEX_SIZE];
int visitedVertexNumber[MAX_VERTEX_SIZE];
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

  // 엣지 입력
  for (int i = 0; i < e; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    values[u].insert(make_pair(v,w));
  }
}

int getNextValues() {
  int min = INF;
  int index = -1;
  for (int i = 1; i < v; ++i) {
    if (!visitedVertexNumber[i] && minValues[i] < min) {
      min = minValues[i];
      index = i;
    }
  }

  return index;
}

void setVisitable(int current) {
  map<int,int> entryPoint = values[current];
  for(auto iter = entryPoint.begin(); iter != entryPoint.end(); ++iter) {
    int index = iter->first;
    int value = iter->second;
    bool isVisitedVertex = visitedVertexNumber[index] == 1;
    int throughPathWeight = minValues[current] + value;
    if(throughPathWeight > 0 && !isVisitedVertex && minValues[index] > throughPathWeight) {
      minValues[index] = throughPathWeight;
    }
  }
}

void calcMinValues() {
  int visitedVertex = -1;
  while (1) {
    visitedVertex = getNextValues();
    if (visitedVertex < 0) {
      return;
    }
    visitedVertexNumber[visitedVertex] = 1;
    setVisitable(visitedVertex);
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
