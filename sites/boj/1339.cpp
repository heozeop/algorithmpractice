#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();
string arr[10];
int match[26];
int weight[26];
int n;
int maxLen = 0;
void fillUp();
void matching();
int sumAll();

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
  fillUp();
  matching();
  cout << sumAll();

  return;
}

void fillUp() {
  for (int i = 0; i < n; ++i) {
    int base = 1;
    reverse(arr[i].begin(), arr[i].end());

    for(int j = 0; j < arr[i].size(); ++j) {
      weight[arr[i][j] - 'A'] += base;
      base *= 10;
    }
  }
}

void matching() {
  int curMax = 9;
  priority_queue<pair<int,int>> q;
  for(int j = 0; j < 26; ++j) {
    if (match[j]) {
      continue;
    }

    if (weight[j]) {
      q.push({weight[j], j});
    }
  }

  while(!q.empty()) {
    int np = q.top().second;
    q.pop();
    match[np] = curMax--;
  }
}

int sumAll() {
  int sum = 0;
  for(int i = 0; i < n; ++i) {
    int base = 1;
    for(int j = 0; j < arr[i].length(); ++j) {
      sum += match[arr[i][j] - 'A'] * base;
      base *= 10;
    }
  }

  return sum;
}
