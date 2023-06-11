#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAX_SIZE = 8;
const int MAX_VALUE = 10001;

int n, m;
int arr[MAX_SIZE];

void input();
void solve();
void dfs(vector<int> &numberArray, int i, set<int> &s);
void printNumberArray(vector<int> &numberArray);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  return;
}

void solve() {
  sort(arr, arr + n);

  vector<int> numberArray;
  set<int> s(arr, arr + n);

  dfs(numberArray, 0, s);
  return;
}

void dfs(vector<int> &numberArray, int prevVal, set<int> &s) {
  if (numberArray.size() == m) {
    printNumberArray(numberArray);
    return;
  }

  for (int iter : s) {
    if (prevVal > iter) {
      continue;
    }

    numberArray.push_back(iter);
    dfs(numberArray, iter, s);
    numberArray.pop_back();
  }
}

void printNumberArray(vector<int> &numberArray) {
  for (int i = 0; i < numberArray.size(); ++i) {
    cout << numberArray[i] << " ";
  }
  cout << "\n";
}
