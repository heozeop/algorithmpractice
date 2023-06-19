#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 5001;

int n;
ll arr[MAX_N];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  return;
}

void solve() {
  sort(arr, arr + n);

  ll minABS = 3000000000;
  int idxList[3];
  for (int i = 0; i < n; ++i) {
    int maxIdx = n - 1;
    int minIdx = 0;

    if (i == 0) {
      minIdx = 1;
    }

    if (i == n - 1) {
      maxIdx = n - 2;
    }

    ll sumVal;
    while (minIdx < maxIdx) {
      sumVal = arr[i] + arr[minIdx] + arr[maxIdx];

      if (minABS > abs(sumVal)) {
        idxList[0] = arr[i];
        idxList[1] = arr[minIdx];
        idxList[2] = arr[maxIdx];
        minABS = abs(sumVal);
      }

      if (!sumVal) {
        break;
      }

      if (sumVal < 0) {
        minIdx += 1;
        if (minIdx == i) {
          minIdx += 1;
        }
      } else {
        maxIdx -= 1;
        if (maxIdx == i) {
          maxIdx -= 1;
        }
      }
    }

    if (!sumVal) {
      break;
    }
  }

  sort(idxList, idxList + 3);
  for (int i = 0; i < 3; ++i) {
    cout << idxList[i] << " ";
  }

  return;
}
