#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  priority_queue<long long, vector<long long>, greater<long long>> minHeap;

  int n;
  cin >> n;
  for (int i = 0; i < n; i += 1) {
    long long temp;
    scanf("%ld", &temp);
    if (temp > 0) {
      minHeap.push(temp);
      continue;
    }
    if (minHeap.empty()) {
      printf("%ld\n", 0);
      continue;
    }

    printf("%ld\n", minHeap.top());
    minHeap.pop();
  }

  return 0;
}