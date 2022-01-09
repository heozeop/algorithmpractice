#include <iostream>
using namespace std;

const int VALUE_LIMIT= 1000000 + 1;

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
  int iter = 0;
  if(x % 2 == 0) {
    iter = x/2 - 1;
    sum += (valueArray[x / 2] * (valueArray[x / 2] - 2))/2;
  } else {
    iter = x/2;
  }

  for(int i = 1; i <= iter; ++i) {
    if(i < VALUE_LIMIT && x - i < VALUE_LIMIT) {
      sum += valueArray[i] * valueArray[x - i];
    }
  }

  cout << sum;
  return;
}