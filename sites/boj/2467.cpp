#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 100000;

int n;
int arr[MAX_N];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  return;
}

void solve() { 
  int minValIdx = 0, maxValIdx = n - 1;
  int lowestVal = INT_MAX;
  int globalMin, globalMax;

  int sumVal;

  while(minValIdx < maxValIdx) {
    sumVal = arr[minValIdx] + arr[maxValIdx];

    if (lowestVal > abs(sumVal)) {
      lowestVal = abs(sumVal);
      globalMin = arr[minValIdx];
      globalMax = arr[maxValIdx];
    }

    if (sumVal == 0) {
      break;
    }

    if (sumVal < 0) {
      minValIdx += 1;
    } else {
      maxValIdx -= 1;
    }
  }

  cout << globalMin << " " << globalMax;

  return;
}
