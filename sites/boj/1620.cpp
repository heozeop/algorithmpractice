#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <vector>

using namespace std;

const int MAX_NM = 100000;
int n, m;
map<string, int> stringMap;
string numMap[MAX_NM + 1];
string instructionList[MAX_NM];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> numMap[i];

    stringMap.insert({numMap[i], i});
  }

  for (int i = 0; i < m; ++i) {
    cin >> instructionList[i];
  }
  return;
}

bool isNumber(string c) {
  if (c[0] - '0' < 10 && c[0] - '0' > 0) {
    return true;
  }

  return false;
}

void solve() {
  map<string, int>::iterator iter;
  for (int i = 0; i < m; ++i) {
    if (isNumber(instructionList[i])) {
      cout << numMap[stoi(instructionList[i])];
    } else {
      iter = stringMap.find(instructionList[i]);
      cout << iter->second;
    }

    cout << '\n';
  }

  return;
}
