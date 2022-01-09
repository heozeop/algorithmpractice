#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int NODE_LIMIT = 100001;
long long solutions[NODE_LIMIT];
int n;

void input();
void solve();

int main(void) {
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> solutions[i];
  }
}

void solve() {
  sort(&solutions[1], &solutions[n] + 1);
  int left = 1, right = n; 
  int min1 = left, min2 = right;
  long long curmin = solutions[min1] + solutions[min2], result;
  while(left < right) {
    result = solutions[left] + solutions[right];
    if(result == 0) {
      min1 = left;
      min2 = right;
      break;
    }

    if(abs(result) < abs(curmin)) {
      curmin = result;
      min1 = left;
      min2 = right;
    }

    if(result < 0) {
      left += 1;
    } else {
      right -= 1;
    }
  }

  cout << solutions[min1] << " " << solutions[min2];
}