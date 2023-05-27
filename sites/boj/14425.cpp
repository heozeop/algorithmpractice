#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Node {
private:
  map<char, Node *> children;
  bool isLastNode = false;

public:
  void insert(string &nodes, int index = 0) {
    if (index == nodes.size()) {
      isLastNode = true;
      return;
    }

    if (children.find(nodes[index]) == children.end()) {
      children[nodes[index]] = new Node();
    }
    children[nodes[index]]->insert(nodes, index + 1);
  }

  bool find(string &str, int index = 0) {
    if (index == str.size())
      return isLastNode;

    if (children.find(str[index]) != children.end()) {
      return children[str[index]]->find(str, index + 1);
    }
    return false;
  }
};

void input();
void solve();

int n, m;
Node *root;
vector<string> finds;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  root = new Node();
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    root->insert(a);
  }
  for (int i = 0; i < m; i++) {
    string a;
    cin >> a;
    finds.push_back(a);
  }
  return;
}

void solve() {
  int found = 0;
  for (int i = 0; i < m; i++) {
    if (root->find(finds[i]))
      found++;
  }
  cout << found;
  return;
}
