#include <algorithm>
#include <climits>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 101;

int n, m;
int arr[MAX_N][MAX_N];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m;

  int a,b;
  for(int i = 0; i < m; ++i) {
    cin >> a >> b;

    arr[a][b] = 1;
    arr[b][a] = 1;
  }
  return; 
}

void solve() { 
  const int START_INDEX = 1;
  const int END_INDEX = n + 1;

  for(int i = START_INDEX ; i < END_INDEX; ++i) {
    for(int j = START_INDEX ; j < END_INDEX; ++j) {
      if(!arr[i][j]) {
        arr[i][j] = INT_MAX;
      }
    }
  }

  for(int i = START_INDEX ; i < END_INDEX; ++i) {
    for(int j = START_INDEX ; j < END_INDEX ; ++j) {
      for(int k = START_INDEX ; k < END_INDEX; ++k) {
        if (j == k) {
          continue;
        }

        if (arr[j][i] == INT_MAX) {
          continue;
        }

        if (arr[i][k] == INT_MAX) {
          continue;
        }

        arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
        arr[j][k] = arr[j][k];
      }
    }
  }

  int minIndex = 0, minValue = INT_MAX;
  for(int i = START_INDEX ; i < END_INDEX; ++i) {
    int localSum = 0;
    for(int j = START_INDEX ; j < END_INDEX; ++j) {
      if (i == j) {
        continue;
      }

      localSum = min(arr[i][j] + localSum , INT_MAX);
    }

    // assume that everyone connected
    if (localSum < minValue) {
      minValue = localSum;
      minIndex = i;
    }
  }

  cout << minIndex;

  return; 
}
