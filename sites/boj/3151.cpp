#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

void input();
void solve();
int n;
int positive[10001];
int negative[10001];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp < 0) {
      negative[abs(temp)]++;
    } else {
      positive[temp]++;
    }
  }
  return;
}

ll pickTwo(int cur, int *container) {
  ll localTotal = 0;
  for (int i = 0, j = cur; i < j; i++, j--) {
    localTotal += container[i] * container[j];
  }

  int middleCouple = container[cur / 2];
  if (cur % 2 == 0 && middleCouple >= 2) {
    localTotal += middleCouple * (middleCouple - 1) / 2;
  }

  return localTotal;
}

void solve() {
  ll total = 0;
  for (int i = 1; i < 10001; i++) {
    if (positive[i]) {
      total += pickTwo(i, negative) * positive[i];
    }
    if (negative[i]) {
      total += pickTwo(i, positive) * negative[i];
    }
  }
  if (positive[0] >= 3) {
    ll zeroVal = positive[0];
    total += zeroVal * (zeroVal - 1) * (zeroVal - 2) / 6;
  }

  cout << total;
  return;
}
