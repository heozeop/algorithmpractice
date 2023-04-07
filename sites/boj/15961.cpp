#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

void input();
void solve();

int n, c, k, d;
int dishes[3000001];
int count;
int dishCount[3001];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> d >> k >> c;
  for(int i = 0; i < n; i++) {
    cin >> dishes[i];
  }

  return;
}

void solve() {
  int s = 0, e;
  int count = 0;
  int maxCount = 0;
  for(int i = 0; i < n + k ; i++) {
    e = i % n;
    if(abs(e - s) >= k) {
      dishCount[dishes[s]] -= 1;
      if(dishCount[dishes[s]] == 0) {
        count -= 1;
      }
      s += 1;
      if(dishCount[dishes[e]] == 0)  {
        count += 1;
      }
      dishCount[dishes[e]] += 1;
    } else {
      if(dishCount[dishes[e]] == 0)  {
        count += 1;
      }
      dishCount[dishes[e]] += 1;
    }

    if (dishCount[c] == 0) {
      maxCount = min(max(maxCount, count + 1), d);
    } else {
      maxCount = min(max(maxCount, count), d);
    }
    
    s %= n;
  }

  cout << maxCount;

  return;
}
