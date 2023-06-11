#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int a,b;

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> a >>  b;
  return;
}

void solve() { 
  queue<pair<int, ll>> q;
  q.push({0, a});

  while(!q.empty()) {
    auto temp = q.front();
    q.pop();

    if(temp.second == b) {
      cout << temp.first + 1;
      return;
    } 

    if (temp.second * 2 <= b) {
      q.push({temp.first + 1, temp.second * 2});
    }

    if (temp.second * 10 + 1 <= b) {
      q.push({temp.first + 1, temp.second * 10 + 1});
    }
  }

  cout << -1;

  return; 
}
