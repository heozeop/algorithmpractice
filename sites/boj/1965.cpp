#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 1000;

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
  for(int i = 0; i < n ; ++i) {
    cin >> arr[i];
  }
  return; 
}

void solve() { 
  vector<int> temp;
  temp.push_back(arr[0]);
  for(int i = 1; i < n; ++i) {
    if(temp.back() <= arr[i]) {
      temp.push_back(arr[i]);
      continue;
    }

    auto tt = lower_bound(temp.begin(), temp.end(), arr[i]);
    *tt = arr[i];
  }

  cout << temp.size();

  return; 
}
