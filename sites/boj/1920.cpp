#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_SIZE = 100001;

int n, m;
int numbers[MAX_SIZE];

void input();
void solve();
bool isExist(int);

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  cin >> m;
  return;
}

// numbers가 정렬되어 있다.
// 정렬된 numbers는 ASC다.
bool isExist(int a) {
  bool existance = false;

  int start = 0, end = n - 1;
  int middle;
  while (start <= end) {
    middle = (start + end) / 2;
    if (numbers[middle] < a) {
      start = middle + 1;
    } else if (numbers[middle] > a) {
      end = middle - 1;
    } else {
      existance = true;
      break;
    }
  }

  return existance;
}

void solve() {
  sort(&numbers[0], &numbers[n]);

  int temp;
  for (int i = 0; i < m; ++i) {
    cin >> temp;
    cout << isExist(temp) << '\n';
  }
  return;
}
