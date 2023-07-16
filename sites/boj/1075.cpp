#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

long long n, f;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> f;
  return; 
}

void solve() { 
  int minI = 101;

  for(int i = 0; i < f; ++i) {
    long long temp = (n / 100) * 100;
    temp += i;

    if(temp % f != 0) {
      continue;
    }

    printf("%02d", i);
    break;
  }


  return; 
}
