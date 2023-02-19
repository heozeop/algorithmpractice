#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

void input();
void solve();
int n, k;
bool isDeleted[1002];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> k;
  return;
}

void solve() {
  int curP = 2, nextP, localPower;

  while(1) {
    localPower = 2;
    nextP = curP;

    while(nextP <= n && k) {
      if(!isDeleted[nextP])  {
        isDeleted[nextP] = true;
        --k;
      }

      nextP = curP * localPower;
      localPower += 1;
    }

    if(k == 0) {
      cout << nextP - curP;
      return;
    }

    for(int j = curP+1; j <= n; ++j) {
      if(!isDeleted[j]) {
        curP = j;
        break;
      }
    }
  }
}

