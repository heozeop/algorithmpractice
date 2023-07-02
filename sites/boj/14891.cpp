#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
const int CLOCK_WISE = 1;
const int COUNTER_CLOCK_WISE = -1;
const int MAX_NEE = 8;
const char SOUTH = '1';

char wheel[5][MAX_NEE];
int k;

void input();
void solve();
void role(int target, int direction);
void spreadLeft(int from, int to, int direction);
void spreadRight(int from, int to, int direction);
void printCnt();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  for(int i = 1; i <= 4; ++i) {
    for(int j = 0; j < 8; ++j) {
      cin >> wheel[i][j];
    }
  }
  cin >> k;
  return;
}

void solve() { 
  while(k--) {
    int target, direction;

    cin >> target >> direction;

    spreadLeft(target, target - 1, direction);
    spreadRight(target, target + 1, direction);
    role(target, direction);
  }
  printCnt();

  return;
}

void role(int target, int direction) {
  int temp;
  if(direction == CLOCK_WISE) {
    temp = wheel[target][MAX_NEE - 1];
    for(int i = MAX_NEE - 1; i > 0; --i) {
      wheel[target][i] = wheel[target][i - 1];
    }
    wheel[target][0] = temp;
  } else {
    temp = wheel[target][0];
    for(int i = 0; i < MAX_NEE - 1; ++i) {
      wheel[target][i] = wheel[target][i + 1];
    }
    wheel[target][MAX_NEE - 1] = temp;
  }
}

bool condition(int left, int right) {
  return wheel[left][2] != wheel[right][6];
}

void spreadLeft(int from, int to, int direction) {
  if (from  == 1) {
    return;
  }

  if (condition(to, from)) {
    spreadLeft(to, to - 1, direction * -1);
    role(to, direction * -1);
  }
}

void spreadRight(int from, int to, int direction) {
  if (from  == 4) {
    return;
  }

  if (condition(from, to)) {
    spreadRight(to, to + 1, direction * -1);
    role(to, direction * -1);
  }
}

void printCnt() {
  int sum = 0;
  for(int i = 1; i <= 4; ++i) {
    if (wheel[i][0] == SOUTH) {
      sum += pow(2, i - 1);
    }
  }
  cout << sum;

  return;
}
