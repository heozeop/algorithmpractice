#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int n;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n;
  return; 
}

void solve() { 
  int answer = INT_MAX;
  for(int i = 0; i <= n / 5; ++i) {
    int temp = n - i * 5;
    int cnt2 = (temp/2);

    temp -= (cnt2) * 2;

    if(temp > 0) {
      // 0 인 경우
      continue;
    }

    answer = min(answer, i + cnt2);
  }


  if(answer== INT_MAX) {
    cout << -1;
    return;
  }
  cout << answer;
  
  return; 
}
