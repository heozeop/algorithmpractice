#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 50;

int n;
bool binded[MAX_N];
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
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  return;
}

void solve() {
  sort(arr, arr + n);

  int maxVal = 0;
  int left = 0, right = n - 1;
  for (; left < right; left += 2) {
    if (arr[left] >= 1 || arr[left + 1] >= 1) {
      break;
    }

    maxVal += arr[left] * arr[left + 1];
  }

  for (; right > 0; right -= 2) {
    if (arr[right] <= 1 || arr[right - 1] <= 1) {
      break;
    }

    maxVal += arr[right] * arr[right - 1];
  }

  for (; right >= left; --right) {
    maxVal += arr[right];
  }

  cout << maxVal;
  return;
}
