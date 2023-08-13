#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int n;
int fibo1, fibo2;
int f[1001];

int fibogo1(int);
void fibogo2();
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
  fibogo1(n);
  f[1] = 1;
  f[2] = 1;
  fibogo2();
  cout << fibo1 << ' ' << fibo2;
  return; 
}

int fibogo1(int n) {
 if (n == 1 || n == 2){
 fibo1++;
    return 1;
 } else {
   return fibogo1(n - 1) + fibogo1(n - 2);
 }
}

void fibogo2() {
    for (int i = 3; i <= n; ++i ){
      fibo2++;
      f[i] = f[i - 1] + f[i - 2];
    }
}

