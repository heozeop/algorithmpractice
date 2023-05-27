#include <deque>
#include <iostream>
using namespace std;

deque<int> priority;
deque<int> id;
int tc, n, m;

int main(void) {
  cin >> tc;

  while (tc--) {
    priority.clear();
    id.clear();
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      priority.push_back(temp);
      id.push_back(i);
    }

    int printedNum = 1;
    while (!priority.empty()) {
      int nowPriority = priority.front();
      int nowId = id.front();

      bool needPrint = true;
      for (int i = 1; i < priority.size(); i++) {
        if (nowPriority < priority[i]) {
          priority.pop_front();
          priority.push_back(nowPriority);

          id.pop_front();
          id.push_back(nowId);

          needPrint = false;
          break;
        }
      }
      if (needPrint) {
        if (nowId == m) {
          cout << printedNum << endl;
          break;
        }
        printedNum++;
        priority.pop_front();
        id.pop_front();
      }
    }
  }
  return 0;
}