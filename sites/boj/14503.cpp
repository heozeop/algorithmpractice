#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
using namespace std;

const int DIRTY = 0;
const int CLEAN = 2;
const int WALL = 1;

pair<int, int> direction[4] = {
    {-1, 0}, // 북
    {0, 1},  // 동
    {1, 0},  // 남
    {0, -1}  // 서
};

int area[51][51];
pair<int, int> robotLocation;
int robotDirection;

int clean;

bool operation1() {
  int r = robotLocation.first;
  int c = robotLocation.second;

  if (area[r][c] == DIRTY) {
    area[r][c] = CLEAN;
    clean++;
    return true;
  }

  return false;
}

bool operation2(int direct, int count) {
  // 왼쪽 방향을 찾습니다.
  int left = direct == 0 ? 3 : direct - 1;

  // 네 방향 모두 청소가 이미 되어있거나 벽인 경우
  int back, brow, bcol;
  if (count == 4) {

    back = (robotDirection + 2) % 4;
    brow = robotLocation.first + direction[back].first;
    bcol = robotLocation.second + direction[back].second;
    // 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
    if (area[brow][bcol] == WALL) {
      return false;
    }
    //바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
    robotLocation.first = brow;
    robotLocation.second = bcol;
    return operation2(robotDirection, 0);
  }

  int lrow = robotLocation.first + direction[left].first;
  int lcol = robotLocation.second + direction[left].second;
  // 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음
  // 한 칸을 전진하고 1번부터 진행한다.
  if (area[lrow][lcol] == DIRTY) {
    robotDirection = left;
    robotLocation.first = lrow;
    robotLocation.second = lcol;
    return true;
  }
  //왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
  return operation2(left, count + 1);
}

// 영역 입력 받음
void setArea(int N, int M) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      scanf("%d", &area[i][j]);
    }
  }
}

int main(void) {
  int N, M;

  cin >> N >> M;
  cin >> robotLocation.first >> robotLocation.second >> robotDirection;
  setArea(N, M);
  robotLocation.first++;
  robotLocation.second++;

  do {
    operation1();
  } while (operation2(robotDirection, 0));

  cout << clean;
}