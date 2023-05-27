#include <iostream>
#include <vector>
using namespace std;

int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int usingNumber[10];

void print(vector<int> result) {
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << ' ';
  }
  cout << '\n';
}

void dfs(int n, int m, vector<int> path) {
  if (m == 0) {
    print(path);
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (usingNumber[i - 1] == 1)
      continue;
    path.push_back(i);
    usingNumber[i - 1] = 1;
    dfs(n, m - 1, path);
    usingNumber[i - 1] = 0;
    path.pop_back();
  }
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> path;
  dfs(n, m, path);
}