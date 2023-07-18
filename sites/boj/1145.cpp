#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int arr[5];
void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  for(int i = 0 ; i < 5;++i){ 
    cin >> arr[i];
  }
  return; 
}

void solve() { 
  int a = INT_MAX;

  for(int i = 0; i < 1000000; ++i) {
    int remain0 = 0;
    for(int j = 0; j < 5; ++j) {
      if(i / arr[j] > 0 && i % arr[j] == 0) {
        ++remain0;
      }
    }

    if(remain0 >= 3) {
      a = i;
      break;
    }
  
  }

  cout << a;

  return; 
}
