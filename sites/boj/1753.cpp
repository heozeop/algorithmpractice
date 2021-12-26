#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_VERTEX_SIZE = 20001;
const int MAX_EDGE_SIZE = 300000;
const int INF = 11 * MAX_EDGE_SIZE;

map<pair<int,int>, int> values;
int minValues[MAX_VERTEX_SIZE];
int visitedVertexNumber[MAX_VERTEX_SIZE];
int v, e;
int startVertexNumber;

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

void init() {
  // 입력
  cin >> v >> e >> startVertexNumber;

  for (int i = 0; i < e; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    pair<int, int> location = make_pair(u,v);
    if(values.find(location) != values.end()) {
      if(values.at(location) < w) {
        continue;
      }
      values.erase(location);
    }
    values.insert(make_pair(location, w));
  }

  // min values
  for(int i = 1; i <= v; ++i) {
    minValues[i] = INF;
  }
  minValues[startVertexNumber] = 0;
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
  for (int i = 1; i <= v; ++i) {
    bool isVisited = visitedVertexNumber[i] == 1;
    try{
      int throughPathWeight = minValues[current] + values.at(make_pair(current, i));

      if (throughPathWeight > 0 && !isVisited && minValues[i] > throughPathWeight) {
        minValues[i] = throughPathWeight;
      }
    } catch(const out_of_range e) {

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


int main(void) {
  init();
  calcMinValues();
  printMinWeights();
  return 0;
}
