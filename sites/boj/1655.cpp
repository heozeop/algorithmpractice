#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  priority_queue<int, vector<int>, less<int>> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  int n;
  cin >> n;

  while (n-- > 0) {
    int temp;
    scanf("%d", &temp);

    if (maxHeap.size() == 0) {
      maxHeap.push(temp);
    } else {
      bool isMinTurn = maxHeap.size() > minHeap.size();
      if (isMinTurn) {
        minHeap.push(temp);
      } else {
        maxHeap.push(temp);
      }

      bool isMaxBiggerThanMin = maxHeap.top() > minHeap.top();
      if (isMaxBiggerThanMin) {
        temp = maxHeap.top();
        maxHeap.pop();
        maxHeap.push(minHeap.top());
        minHeap.pop();
        minHeap.push(temp);
      }
    }

    printf("%d\n", maxHeap.top());
  }
  return 0;
}
