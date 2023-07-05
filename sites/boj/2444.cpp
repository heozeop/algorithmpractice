#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int n;
void input();
void solve();
void printSpace(int);
void printStar(int);

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
  for(int i = 1; i <= n; ++i) {
    printSpace(n - i);
    printStar(i);
    cout << '\n';
  }

  for(int i = 1; i <= n; ++i) {
    printSpace(i);
    printStar(n - i);
    cout << '\n';
  }

  return; 
}


void printSpace(int amount) {
  for(int i = 0; i < amount; ++i) {
    cout << " ";
  }
}

void printStar(int amount) {
  for(int i = 0; i < 2 * amount - 1; ++i) {
    cout << "*";
  }
}
