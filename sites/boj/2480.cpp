#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
int a,b,c;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> a >> b >> c;
  return; 
}

void solve() { 
  bool isABEqual = a == b;
  bool isBCEqual = b == c;
  bool isCAEqual = c == a;

  if (isABEqual && isBCEqual) {
    cout << 10000 + a * 1000;
    return;
  }

  if (isABEqual) {
    cout << 1000 + a * 100;
    return;
  }

  if(isBCEqual) {
    cout << 1000 + b * 100;
    return;
  }

  if(isCAEqual) {
    cout << 1000 + c * 100;
    return;
  }

  int maxVal = a;
  maxVal = max(maxVal, b);
  maxVal = max(maxVal, c);

  cout << maxVal * 100;
  return; 
}
