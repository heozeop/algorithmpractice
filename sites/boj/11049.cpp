// 행렬의 개수
// row,column 주어짐
// 최소 크기를 구하는 문제
// dnc할 것임

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX = 501;
const unsigned int LIMIT = 0xffffffff;

typedef unsigned int ll;
typedef struct _maxtrics {
  int row;
  int col;
} matrics;

ll map[MAX][MAX];
matrics matricsList[MAX];

int calcMatric(matrics a, matrics b) {
  return a.row * b.row * b.col;
}

ll findMin(int s, int e) {
  if(map[s][e] != LIMIT) {
    return map[s][e];
  }

  if(s == e) {
    return 0;
  }

  if(s + 1 == e) {
    map[s][e] = calcMatric(matricsList[s], matricsList[e]);
  }

  int val = matricsList[s].row * matricsList[e].col;
  for(int i = s; i < e; i += 1) {
    ll left = findMin(s, i);
    ll right = findMin(i + 1, e);
    ll curSum = val * matricsList[i].col;
    map[s][e] = min(map[s][e], left + right + curSum);
  }

  return map[s][e];
}

int main(void) {
  memset(map, LIMIT, sizeof(map));

  int n;
  cin >> n; 
  for(int i = 1; i <= n; i += 1) {
    int r,c;
    cin >> r >> c;
    matricsList[i].row = r;
    matricsList[i].col = c;
  }

  cout << findMin(1, n) << endl;
  return 0;
}

