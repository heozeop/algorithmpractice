#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 10000;

class Trie {

  bool isFinish;
  Trie *Node[10];

public:
  Trie() {
    isFinish = false;
    for (int i = 0; i < 10; i++) {
      Node[i] = NULL;
    }
  }

  void insert(string str, int idx) {
    if (idx == str.size()) {
      isFinish = true;
      return;
    }

    int cur = str[idx] - '0';
    if (Node[cur] == NULL) {
      Node[cur] = new Trie();
    }

    Node[cur]->insert(str, idx + 1);
  }

  bool isPrefixExist(string str, int idx) {
    if (str.size() == idx) {
      return false;
    }

    // 중간 종료 존재
    if (isFinish) {
      return true;
    }

    int cur = str[idx] - '0';
    if (Node[cur] == NULL) {
      return false;
    }

    return Node[cur]->isPrefixExist(str, idx + 1);
  }
};

int t, n;
string arr[MAX_N];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> t;
  return;
}

void solve() {
  while (t--) {
    Trie head;

    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      head.insert(arr[i], 0);
    }

    bool isPrefixExist = false;
    for (int i = 0; i < n; ++i) {
      if (head.isPrefixExist(arr[i], 0)) {
        isPrefixExist = true;
        break;
      }
    }

    if (isPrefixExist) {
      cout << "NO";
    } else {
      cout << "YES";
    }

    cout << '\n';
  }
  return;
}
