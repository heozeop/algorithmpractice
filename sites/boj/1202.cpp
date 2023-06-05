#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int MAX_NUM_OF_BAG = 300000;
const int MAX_NUM_OF_GEM = 300000;

int n, k;
pair<int, int> gemstones[MAX_NUM_OF_GEM];
int bagArr[MAX_NUM_OF_BAG];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> k;
  int m, v;

  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &m, &v);
    gemstones[i].first = m;
    gemstones[i].second = v;
  }

  int temp;
  for (int i = 0; i < k; ++i) {
    scanf("%d", &bagArr[i]);
  }

  return;
}

void solve() {
  sort(gemstones, gemstones + n);
  sort(bagArr, bagArr + k);

  ll valueSum = 0;
  priority_queue<int> q;

  for (int i = 0, j = 0; i < k; ++i) {
    // 현재 가방에 들어가는 모든 보석 넣기
    while (j < n && gemstones[j].first <= bagArr[i]) {
      q.push(gemstones[j].second);
      j++;
    }

    if (q.empty()) {
      continue;
    }

    // 제일 비싼거 더하기
    valueSum += q.top();
    q.pop();
  }

  cout << valueSum;
  return;
}
