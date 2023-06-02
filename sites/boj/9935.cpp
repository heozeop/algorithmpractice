#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void input();
void solve();

string inputValue;
string explosive;

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> inputValue >> explosive;
  return;
}

string exploadAll(string inputString) {
  if (inputString.length() < explosive.length()) {
    return inputString;
  }

  string temp = "";
  for (int i = 0; i < inputString.length(); ++i) {
    temp += inputString[i];
    if (temp.length() < explosive.length()) {
      continue;
    }

    bool isExplosiveExist = true;
    for (int j = 0; j < explosive.length(); ++j) {
      if (temp[temp.length() - explosive.length() + j] != explosive[j]) {
        isExplosiveExist = false;
        break;
      }
    }

    if (isExplosiveExist) {
      temp.erase(temp.end() - explosive.length(), temp.end());
    }
  }

  return temp;
}

void solve() {
  string targetString = exploadAll(inputValue);

  if (targetString.length() > 0) {
    cout << targetString;
    return;
  }

  cout << "FRULA";

  return;
}
