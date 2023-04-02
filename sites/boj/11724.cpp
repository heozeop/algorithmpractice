#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#include <set>

using namespace std;

class Node {
public:
  Node* parent;
  int index;

  Node(int val) {
    this->index = val;
    this->parent = nullptr;
  }

  Node* getOldestParent() {
    if(this->parent == nullptr) {
      return this;
    }

    return this->parent = this->parent->getOldestParent();
  }
};

int n, m;

void input();
void solve();
void merge(Node*, Node*);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  return;
}

void solve() {
  int v1,v2;
  Node* p1;
  Node* p2;
  Node* nodeList[n + 1];
  for(int i = 1; i <= n; ++i) {
    nodeList[i] = new Node(i);
  }

  while(m--) {
    cin >> v1 >> v2;

    p1 = nodeList[v1]->getOldestParent();
    p2 = nodeList[v2]->getOldestParent();

    merge(p1,p2);
  }

  set<int> clusters;

  for (int i = 1; i <= n; ++i) {
    clusters.insert(nodeList[i]->getOldestParent()->index);
  }

  cout << clusters.size() << endl;

  return;
}

void merge(Node* p1, Node* p2) {
  if(p1->index != p2->index) {
    p1->parent = p2;
  }
}
