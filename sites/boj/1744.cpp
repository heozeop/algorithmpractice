#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
const int MAX_N = 50;
const ll LOWER_BOUND = -50000000;

int n;
bool binded[MAX_N];
int arr[MAX_N];
ll maxVal;

void input();
void solve();
void backTrack(int curIdx, ll curSum);

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
  maxVal = LOWER_BOUND;
  backTrack(0, 0);
  cout << maxVal;
  return;
}

void backTrack(int curIdx, ll curSum){
  if (curIdx == n) {
    maxVal = max(maxVal, (ll)curSum);
    return;
  }

  if (binded[curIdx]) {
    return backTrack(curIdx + 1, curSum);
  }

  backTrack(curIdx + 1, curSum + arr[curIdx]);

  for(int i = curIdx + 1; i < n; ++i) {
    if (binded[i]) {
      continue;
    }

    binded[i] = true;
    backTrack(curIdx + 1, curSum + arr[curIdx] * arr[i]);
    binded[i] = false;
  }
}
