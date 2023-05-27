#include <iostream>
using namespace std;

class Node {
public:
  Node *left;
  Node *right;
  int val;

  Node(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }

  void insert(int val) {
    if (this->val < val) {
      if (this->right == nullptr) {
        this->right = new Node(val);
      } else {
        this->right->insert(val);
      }
    } else {
      if (this->left == nullptr) {
        this->left = new Node(val);
      } else {
        this->left->insert(val);
      }
    }
  }
};

void printPostorder(Node *curNode) {
  if (curNode == nullptr) {
    return;
  }

  printPostorder(curNode->left);
  printPostorder(curNode->right);
  cout << curNode->val << endl;
  return;
}

int main(void) {
  int temp;

  cin >> temp;
  Node *head = new Node(temp);
  while (cin >> temp) {
    head->insert(temp);
  }

  printPostorder(head);

  return 0;
}
