#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
using namespace std;

const int DIRTY = 0;
const int CLEAN = 2;
const int WALL = 1;

pair<int, int> direction[4] = {
    {-1, 0}, // ��
    {0, 1},  // ��
    {1, 0},  // ��
    {0, -1}  // ��
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
  // ���� ������ ã���ϴ�.
  int left = direct == 0 ? 3 : direct - 1;

  // �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ���
  int back, brow, bcol;
  if (count == 4) {

    back = (robotDirection + 2) % 4;
    brow = robotLocation.first + direction[back].first;
    bcol = robotLocation.second + direction[back].second;
    // ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
    if (area[brow][bcol] == WALL) {
      return false;
    }
    //�ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
    robotLocation.first = brow;
    robotLocation.second = bcol;
    return operation2(robotDirection, 0);
  }

  int lrow = robotLocation.first + direction[left].first;
  int lcol = robotLocation.second + direction[left].second;
  // ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ����
  // �� ĭ�� �����ϰ� 1������ �����Ѵ�.
  if (area[lrow][lcol] == DIRTY) {
    robotDirection = left;
    robotLocation.first = lrow;
    robotLocation.second = lcol;
    return true;
  }
  //���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
  return operation2(left, count + 1);
}

// ���� �Է� ����
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