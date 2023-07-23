#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int n;
int arr[] = {
  500, 100, 50, 10, 5, 1
};
void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n;
  n = 1000 - n;
  return; 
}

void solve() { 
  int cnt = 0;
  for(int i : arr) {
    if (n < i) {
      continue;
    }

    cnt += n / i;
    n %= i;
  }

  cout << cnt;
  return; 
}
