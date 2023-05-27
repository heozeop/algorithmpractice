#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

const int NUMBER_OF_POINTS = 6;
int directionCounts[4];
int arr[NUMBER_OF_POINTS][2];
int n;

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 0; i < NUMBER_OF_POINTS; i++) {
    cin >> arr[i][0] >> arr[i][1];
    directionCounts[arr[i][0] - 1]++;
  }
  return;
}

void solve() {
  int smallArea, bigArea;
  smallArea = bigArea = 1;

  for (int i = 0; i < NUMBER_OF_POINTS; ++i) {
    if (directionCounts[arr[i][0] - 1] == 1) {
      bigArea *= arr[i][1];
    } else if (arr[i][0] == arr[(i + 2) % 6][0]) {
      smallArea *= arr[(i + 1) % 6][1];
    }
  }

  cout << (bigArea - smallArea) * n;
  return;
}
