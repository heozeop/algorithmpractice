#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#include <set>

using namespace std;

const int POP_SMALL = -1;
const int POP_BIG = 1;
const char INSERT = 'I';
const char DELETE = 'D';
const int MODE_DESC = 1;
const int MODE_ASC = -1;

int t,q;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  scanf("%d", &t);
  return;
}

class DualPriorityQueue {
  public:
  multiset<int> q;

  DualPriorityQueue() {
  }

  int top(int mode) {
    if(mode == MODE_ASC) {
      return *q.begin();
    }

    multiset<int>::iterator iter = this->q.end();
    iter--;
    return *iter;
  }

  void insert(int val) {
    this->q.insert(val);
  }

  void deleteOn(int mode) {
    if(this->isEmpty()) {
      return;
    }

    if(mode == MODE_ASC) {
      this->q.erase(this->q.begin());
      return;
    }

    multiset<int>::iterator iter = this->q.end();
    iter--;
    this->q.erase(iter);
  }

  bool isEmpty() {
    return this->q.empty();
  }
};

void handleTest(int t) {
  char op;
  int val;
  DualPriorityQueue q;

  for(int i = 0; i < t; ++i) {
    scanf("%c %d%*c", &op, &val);
    
    switch(op) {
      case INSERT:
        q.insert(val);
        break;
      case DELETE:
        q.deleteOn(val);
        break;
    }
  }
  
  if (q.isEmpty()) {
    printf("EMPTY\n");
  } else {
    printf("%d %d\n", q.top(MODE_DESC), q.top(MODE_ASC));
  }
}

void solve() {

  while(t--) {
    scanf("%d\n", &q);
    handleTest(q);
  }

  return;
}
