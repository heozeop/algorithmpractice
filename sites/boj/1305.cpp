#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

void input();
void solve();
int n;
string s;

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n >> s;
  return;
}

vector<int> ff(string str) {
  vector<int> pi(str.length(), 0);
  int j = 0;
  for(int i = 1; i < str.length(); i++) {
    while(j > 0 && str[i] != str[j]) j = pi[j - 1];
    if(str[i] == str[j]) {
      pi[i] = ++j;
    }
  }
  return pi;
}
bool isCorrect(string str, int length, int size) {
  int nextLength = length - size;
  for(int i = size, j = length; i < nextLength && j < str.length(); i++, j++) {
    if(str[i] != str[j]) {
      return false;
    }
  }

  return true;
}

int getLength(string str) {
  auto pi = ff(str);
  int length = str.length();
  int last = pi[length - 1];
  

  while(last) {
    if(!isCorrect(str, length, last)) {
      break;
    }
    length = length - last;
    last = pi[length - 1];
  }

  return length;
}

void solve() {
  int oriD = getLength(s);
  reverse(s.begin(), s.end());
  int reverseD = getLength(s);
  cout << min(oriD, reverseD);

  return;
}
