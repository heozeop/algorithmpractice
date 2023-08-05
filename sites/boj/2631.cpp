#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int n;
int arr[200];
int dp[200];

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
  int maxVal = 0;
  vector<int> v;

  v.push_back(arr[0]);

  for(int i = 1; i < n; ++i) {
    if(v.back() < arr[i]) {
      v.push_back(arr[i]);
    } else {
      auto temp = lower_bound(v.begin(), v.end(), arr[i]);
      *temp = arr[i];
    }
  }

  cout << n - v.size();
  return;
}
