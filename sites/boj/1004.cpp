/** 
 * 문제: 어린 왕자
 * 입력: 입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 
 *       그 다음 줄부터 각각의 테스트케이스에 대해 
 *        첫째 줄에 출발점 (x1, y1)과 도착점 (x2, y2)이 주어진다. 
 *        두 번째 줄에는 행성계의 개수 n이 주어지며, 
 *        세 번째 줄부터 n줄에 걸쳐 행성계의 중점과 반지름 (cx, cy, r)이 주어진다.
 *  출력: 각 테스트 케이스에 대해 어린 왕자가 거쳐야 할 최소의 행성계 진입/이탈 횟수를 출력한다.
 * 
 * 
 *  생각:
 *    출발점이 포함된 원 + 도착점이 포함된 원 - 둘다 포함된 원 (행성계 교차, 접촉 없음)
 *    출발점과 도착점이 원에 포함되는지 판별해야함
 *    (점 - 원점) < 반지름 (경계에 걽치지 않는다고 가정)
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

int t, x1, yy1, x2, y2, c;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

bool isStartPointIncluded(int x, int y, int r) {
  int distance = sqrt(pow(x - x1, 2) + pow(y - yy1, 2));

  return distance < r;
}

bool isEndPointIncluded(int x, int y, int r) {
  int distance = sqrt(pow(x - x2, 2) + pow(y-y2, 2));

  return distance < r;
}

void input() {
  cin >> t;
  return;
}

void solve() {
  while(t--) {
    int count = 0;
    cin >> x1 >> yy1 >> x2 >> y2 >> c;

    while(c--) {
      int x, y, r;

      cin >> x >> y >> r;
      if(isStartPointIncluded(x,y,r) != isEndPointIncluded(x,y,r)) {
        count += 1;
      }
    }
    printf("%d\n", count);
  }

  return;
}
