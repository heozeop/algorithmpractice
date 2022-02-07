#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int LIMIT_VAL = 100001;

void input();
void solve();

int n;
int inOrder[LIMIT_VAL];
int postOrder[LIMIT_VAL];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> inOrder[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> postOrder[i];
  }
  return;
}

int findIndex(int* arr, int target,int start, int end) {
  for(int i = start; i <= end; ++i) {
    if(arr[i] == target) {
      return i;
    }
  }

  return -1;
}

void printPreOrder(int iStart, int iEnd, int pStart, int pEnd) {
  if(iStart > iEnd || pStart > pEnd) {
    return;
  }

  int curRoot = postOrder[pEnd];
  printf("%d ", curRoot);

  int rootIndex = findIndex(inOrder, curRoot, iStart, iEnd);
  if(rootIndex == -1) {
    return;
  }

  int distance = (rootIndex - iStart);
  printPreOrder(iStart, rootIndex - 1, pStart, pStart + distance - 1);
  printPreOrder(rootIndex + 1, iEnd, pStart + distance, pEnd - 1);
}

void solve() {
  printPreOrder(1, n, 1, n);
  return;
}
