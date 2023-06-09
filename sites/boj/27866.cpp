#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
#include <vector>

using namespace std;

string inputString;
int l;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> inputString >> l;
  return;
}

void solve() {
  cout << inputString[l - 1];
  return;
}
