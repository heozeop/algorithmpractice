#include <iostream>
#include <algorithm>
using namespace std;

const int NODE_LIMIT = 100000 + 1;
int n, s;
int numArray[NODE_LIMIT];

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
  for(int i = 0; i < n; ++i) {
    cin >> numArray[i];
  }
  return;
}

void solve() {
  sort(&numArray[0], &numArray[n]);
  int left = 0, right = 1;
  int minLength = NODE_LIMIT;
  long long curSum = 0;
  while(left < right && right < n) {
    curSum += numArray[left] + numArray[right];

    if(curSum >= s) {
      if(minLength > right - left + 1) {
        minLength = right - left + 1;
      }
      left += 1;
    } else {
      right += 1;
    }
  }

  if(minLength == NODE_LIMIT) {
    minLength = 0;
  } 

  cout << minLength;
  return;
}