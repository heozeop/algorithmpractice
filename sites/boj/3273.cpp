#include <iostream>
#include <algorithm>
using namespace std;

const int VALUE_LIMIT= 1000001;

int n, x;
int valueArray[VALUE_LIMIT];

void input();
void solve();

int main(void) {
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  input();
  solve();
  return 0;
}

void input(){
  cin >> n;
  int temp;
  for(int i = 0; i < n; ++i) {
    cin >> temp;
    valueArray[temp] += 1;
  }
  cin >> x;
  return;
}

void solve() {
  int sum = 0;
  for(int i = 1; i < x / 2; ++i) {
    sum += min(valueArray[i], valueArray[x - i]);
  }
  cout << sum;
  return;
}