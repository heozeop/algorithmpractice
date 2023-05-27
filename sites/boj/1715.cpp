#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int n;
int arr[100000];

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
  priority_queue<ll, vector<ll>, greater<ll>> q;
  for(int i = 0; i < n; ++i) {
    q.push(arr[i]);
  }

  ll sum = 0, temp;
  while(q.size() > 1) {
    temp = q.top();
    q.pop();
    temp += q.top();
    q.pop();

    sum += temp;
    q.push(temp);
  }

  cout << sum;
  

  return; 
}
