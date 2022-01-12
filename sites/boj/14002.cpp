#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int VALUE_LIMIT = 1000 + 1;
const int INDEX_LIMIT = 1000 + 1;

int n;
int numArray[VALUE_LIMIT];
int dpVal[VALUE_LIMIT];
string dpPath[VALUE_LIMIT];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0; 
}

void input() {
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> numArray[i];
  }
}

void solve() {
  for(int i = 1; i <= n; ++i) {
    dpVal[i] = 1;
    dpPath[i] = to_string(numArray[i]);
    for(int j = 1; j < i; ++j) {
      if(numArray[i] > numArray[j] && dpVal[i] < dpVal[j] + 1) {
        dpVal[i] = dpVal[j] + 1;
        dpPath[i] = dpPath[j] + " " + to_string(numArray[i]);
      }
    }
  }

  int maxLen = 0;
  string maxPath;
  for(int i = 1; i <= n; ++i) {
    if(maxLen < dpVal[i]) {
      maxLen = dpVal[i];
      maxPath = dpPath[i];
    }
  }

  cout << maxLen << endl << maxPath;
}