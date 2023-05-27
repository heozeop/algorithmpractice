#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void input();
void solve();

class Node {
private:
  map<string, Node *> children;

public:
  void print(int index) {
    for (auto &child : children) {
      for (int i = 0; i < index; ++i)
        cout << "--";
      cout << child.first << '\n';
      child.second->print(index + 1);
    }
  }

  void insert(vector<string> &nodes, int index) {
    if (index == nodes.size())
      return;

    if (children.find(nodes[index]) == children.end())
      children[nodes[index]] = new Node();
    children[nodes[index]]->insert(nodes, index + 1);
  }
};

int n;
Node *parent;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  parent = new Node();
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector<string> t(k);
    for (int j = 0; j < k; j++) {
      cin >> t[j];
    }

    parent->insert(t, 0);
  }

  return;
}

void solve() {
  parent->print(0);
  return;
}
