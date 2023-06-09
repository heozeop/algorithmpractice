#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 300000;

int arr[MAX_N];
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
  for(int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  return; 
}

void solve() { 
  int a = round(0.15 * n);

  sort(arr, arr + n);

  int sum = 0;
  for(int i = a; i < n - a; ++i) {
    sum += arr[i];
  }

  float b = n - 2 * a;
  

  if (b) {
    cout << round(sum / b);
  } else {
    cout << 0;
  }

  

  return; 
}
