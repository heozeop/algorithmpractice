#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void input();
void solve();
const char MOVE_LEFT = 'L';
const char MOVE_RIGHT = 'D';
const char BACKTRACK = 'B';
const char PUSH = 'P';
const int MAX_N = 500000;

int n;
string initialState;

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> initialState;
  cin >> n;

  return;
}

void solve() {
  vector<char> front, back;

  for (char i : initialState) {
    front.push_back(i);
  }

  char op, additional;
  while (n--) {
    scanf(" %c", &op);
    switch (op) {
    case MOVE_LEFT:
      if (front.size()) {
        back.push_back(front.back());
        front.pop_back();
      }
      break;
    case MOVE_RIGHT:
      if (back.size()) {
        front.push_back(back.back());
        back.pop_back();
      }
      break;
    case BACKTRACK:
      if (front.size()) {
        front.pop_back();
      }
      break;
    case PUSH:
      scanf(" %c", &additional);
      front.push_back(additional);

      break;
    }
  }

  for (int i = 0; i < front.size(); ++i) {
    printf("%c", front[i]);
  }

  for (int i = back.size() - 1; i >= 0; --i) {
    printf("%c", back[i]);
  }

  return;
}
