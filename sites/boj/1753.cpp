// 정점 V개, 간선 E개
// 1 ~ V까지 가는 최단 경로 값 출력하기

/*
* 저기 있는 4번을 이해 하면 다익스트라 알고리즘 문제인 1753 번을 쉽게 풀듯 합니다.
* 이 문제는 메모리 제한에 안걸릴 거 같으니 그냥 일단 o^2로 풀겠습니다.
* 이게 n^2라고? 쩌네
* 
* 탭이 4칸인거 불편하더라도 조금만 참아주세요 ㅜㅜ
* 
* 첫줄 부터 V줄에 걸쳐 => 1~V까지 돌면서
* i번째 줄에 i번 정점으로의 최단 경로의 경로값 => [시작][i]의 최솟값
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_VERTEX_SIZE = 20001;
const int MAX_EDGE_SIZE = 300000;
const int INF = 11;

int values[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE];
int minValues[MAX_VERTEX_SIZE];
int visitedVertexNumber[MAX_VERTEX_SIZE];
int v, e;
int startVertexNumber;

void init() {
    memset(values, INF, sizeof values);
    memset(minValues, INF, sizeof minValues);

    cin >> v >> e >> startVertexNumber;
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        values[u][v] = w;
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
    int throughPathWeight = minValues[current] + values[current][i];

    if (!isVisited && minValues[i] > throughPathWeight) {
      minValues[i] = throughPathWeight;
    }
  }
}

void calcMinValues() {
  int visitedVertex = -1;
  while (1) {
    /*
        정리가 안되서 쓰면서 할게여
        1. 방문한 노드 선택
        2. 방문한 노드에서 갈 수 있는 모든 위치 한번 싹 설정
    */
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
