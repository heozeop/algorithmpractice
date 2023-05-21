#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

const int MAX_N = 1000000;
int n;
int arr[MAX_N];
int ans[MAX_N];

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
    scanf("%d", &arr[i]);
  }
  return;
}

void find() {
  priority_queue<int, vector<int>, greater<int>> q;

  q.push(arr[n-1]);
  ans[n-1] = -1;
  for(int i = n - 2; i >= 0; --i) {
    while(!q.empty() && q.top() <= arr[i]) {
      q.pop();
    }


    if(q.empty()) {
      ans[i] = -1;
    } else {
      ans[i] = q.top();
    }

    q.push(arr[i]);
  }
}

void solve() {
  find();
  for(int i = 0; i < n; ++i) {
    printf("%d ", ans[i]);
  }
  return;
}
