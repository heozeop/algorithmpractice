#include <iostream>
using namespace std;

const int NODE_LIMIT = 100000 + 1;

int n;
long long s;
int minLength = NODE_LIMIT;
int numArray[NODE_LIMIT];
int sumArray[NODE_LIMIT];

void input();
void solve();

int main(void) {
  cin.sync_with_stdio(false);
  cin.tie(NULL);

  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> s;
  for(int i = 1; i <= n; ++i) {
    cin >> numArray[i];
    sumArray[i] = numArray[i] + sumArray[i - 1];

    if(sumArray[i] >= s && minLength > i) {
      minLength = i;
    }
  }
  return;
}

void solve() {
  int leftNode = 1, rightNode = minLength;
  long long curSum = 0;
  while(leftNode < rightNode && rightNode <= n) {
    curSum = sumArray[rightNode] - sumArray[leftNode];

    if(curSum >= s) {
      if(minLength > rightNode - leftNode) {
        minLength = rightNode - leftNode;
      }
      leftNode += 1;
    } else {
      rightNode += 1;
    }
  }

  if(minLength == NODE_LIMIT) {
    minLength = 0;
  } 

  cout << minLength;
  return;
}