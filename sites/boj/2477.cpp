#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;
typedef pair<int,int> pos;

const int NUMBER_OF_POINTS = 6;
const int DIRECTION[5][2] = {
  {0,0},
  {1,0},
  {-1,0},
  {0,-1},
  {0,1},
};

vector<pos> positionList(NUMBER_OF_POINTS);
int collapsePointIdx = 0;
int n;

int getAreaByPos(pos a, pos b);
pos getPosByIndex(int);

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  positionList[0].first = 0;
  positionList[0].second = 0;
  int prevXDirection = 0;
  int prevYDirection = 0;

  for(int i = 0; i < NUMBER_OF_POINTS; i++) {
    int curD, amount;
    cin >> curD >> amount;
    if(i < NUMBER_OF_POINTS - 1) {
      positionList[i+1].first = positionList[i].first + DIRECTION[curD][0] * amount;
      positionList[i+1].second = positionList[i].second + DIRECTION[curD][1] * amount;
    }

    if (curD < 3) {
      if(prevXDirection == 0 || prevXDirection != curD) {
        prevXDirection = curD;
      } else {
        collapsePointIdx = i - 1;
      }
    } else {
      if(prevYDirection == 0 || prevYDirection != curD) {
        prevYDirection = curD;
      } else {
        collapsePointIdx = i;
      }
    }
  }

  return;
}

void solve() {
  int smallArea = getAreaByPos(getPosByIndex(collapsePointIdx - 1), getPosByIndex(collapsePointIdx + 1));
  int bigArea = getAreaByPos(getPosByIndex(collapsePointIdx - 2), getPosByIndex(collapsePointIdx + 2));
  cout << (bigArea - smallArea) * n;
  return;
}

pos getPosByIndex(int idx) {
  int validIdx = idx % NUMBER_OF_POINTS; 
  if(validIdx < 0) {
    validIdx += NUMBER_OF_POINTS;
  }
  return positionList[validIdx];
}

int getAreaByPos(pos a, pos b) {
  return abs(a.first - b.first) * abs(a.second - b.second);
}
