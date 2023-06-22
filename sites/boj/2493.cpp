#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 500001;

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
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  return;
}

void solve() {
  vector<int> temp;
  for (int i = 0; i < n; ++i) {
    int returnIndex = 0;

    while (!temp.empty()) {
      if (arr[temp.back()] < arr[i]) {
        temp.pop_back();
      } else {
        returnIndex = temp.back() + 1;
        break;
      }
    }

    cout << returnIndex << " ";
    temp.push_back(i);
  }
  return;
}
