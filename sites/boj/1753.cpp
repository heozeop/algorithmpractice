// 정점 V개, 간선 E개
// 1 ~ V까지 가는 최단 경로 값 출력하기

/*
* 일단 기본적인 생각으로는 갈 수 있는 영역 리스트를 minHeap을 사용해 가지고 있으면 되지 않을까 싶다는 생각을 했습니다.
* 1번 노드에서 갈 수 있는 영역에 대한 minHeap을 통해, 다음 노드를 선택 합니다.
* 이 때, 이미 방문한 노드인지 확인합니다.
*/

#include <iostream>
#include <vector>
using namespace std;

