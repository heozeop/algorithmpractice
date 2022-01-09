#include <iostream>
#include <algorithm>
using namespace std;

const int VALUE_LIMIT= 100000;

int n, x;
int nodeArray[VALUE_LIMIT];

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
    nodeArray[i] = temp;
  }
  cin >> x;
  return;
}

void solve() {
  sort(&nodeArray[0], &nodeArray[n]);
  int i = 0, j = n - 1, sum = 0;
  while(i < j) {
    int result = nodeArray[i] + nodeArray[j];
    if(result == x) {
      sum += 1;
      i += 1;
      j -= 1;
    } else if (result < x) {
      i += 1;
    } else {
      j -= 1;
    }
  }

  cout << sum;
  return;
}