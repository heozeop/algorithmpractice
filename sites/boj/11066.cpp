#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 501;
const int LIMIT = 0x3f3f3f3f;

int map[MAX][MAX];
int container[MAX];
// 합의 값을 사용하기 위해 sum을 기록한다.
int sum[MAX];

int findMin(int s, int e) {
  if (map[s][e] != LIMIT) {
    return map[s][e];
  }

  if (s == e) {
    return 0;
  }

  if (s + 1 == e) {
    map[s][e] = container[s] + container[e];
    return map[s][e];
  }

  for (int i = s; i < e; ++i) {
    int left = findMin(s, i);
    int right = findMin(i + 1, e);
    map[s][e] = min(map[s][e], left + right);
  }
  map[s][e] += sum[e] - sum[s - 1];

  return map[s][e];
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    memset(map, LIMIT, sizeof(map));

    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
      cin >> container[i];
      sum[i] = sum[i - 1] + container[i];
    }

    cout << findMin(1, k) << '\n';
  }

  return 0;
}