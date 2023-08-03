#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int w,h;
int arr[500];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> h >> w;
  for(int i = 0; i < w; ++i) {
    cin >> arr[i];
  }
  return; 
}

void solve() { 
  int sum = 0;
  for(int i = 1; i < w - 1; ++i) {
    int leftMax = 0;
    for(int j = 0; j < i; ++j) {
      leftMax = max(leftMax, arr[j]);
    }

    int rightMax = 0;
    for(int j = i + 1; j < w; ++j) {
      rightMax = max(rightMax, arr[j]);
    }

    int lowerMax = min(leftMax, rightMax);
    if(arr[i] < lowerMax) {
      sum += lowerMax - arr[i];
    }
  }

  cout << sum;

  return; 
}
