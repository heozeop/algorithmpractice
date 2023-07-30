#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 50;

int n, k;
int learnedWord;

int arr[MAX_N];
int maxVal;

void input();
void solve();
void dfs(int, int);
void countMax();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> k;
  string a;
  for (int i = 0; i < n; ++i) {
    cin >> a;

    for(char b: a) {
      arr[i] |= 1 << (b - 'a');
    }
  }
  return;
}

void solve() {
  if (k < 5) {
    cout << 0;
    return;
  }

  learnedWord |= 1 << ('a' - 'a');
  learnedWord |= 1 << ('n' - 'a');
  learnedWord |= 1 << ('t' - 'a');
  learnedWord |= 1 << ('i' - 'a');
  learnedWord |= 1 << ('c' - 'a');

  dfs(0, 0);
  cout << maxVal;

  return;
}

void dfs(int curNode, int leftCount) {
  if (leftCount == k-5) {
    countMax();
    return;
  }

  for (int i = curNode; i < 26; ++i) {
    if (learnedWord & (1 << i)) {
      continue;
    }

    learnedWord |= (1 << i);
    dfs(i, leftCount + 1);
    learnedWord &= ~(1 << i);
  }
}

void countMax() {
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    if((arr[i] & learnedWord) == arr[i]) {
      sum += 1;
    }
  }

  maxVal = max(sum, maxVal);
}
