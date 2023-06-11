#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

string formular;

void input();
void solve();
bool isAlphabet(char);
bool isPlusMinus(char);
bool isMultipleDivider(char);
bool isOpenParenthesis(char);
bool isCloseParenthesis(char);
int checkSingleCharacter(int i, int currentLayer, vector<char> &v,
                         vector<char> &op);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> formular;
  return;
}

void solve() {
  vector<char> op;
  int layer = 0;

  for (int i = 0; i < formular.size(); ++i) {
    char curCharacter = formular[i];

    if (isAlphabet(curCharacter)) {
      cout << curCharacter;
    } else if (isPlusMinus(curCharacter)) {
      while(!op.empty() && !isOpenParenthesis(op.back())) {
        cout << op.back();
        op.pop_back();
      }
      op.push_back(curCharacter);
    } else if (isMultipleDivider(curCharacter)) {
      while(!op.empty() && isMultipleDivider(op.back())) {
        cout << op.back();
        op.pop_back();
      }
      op.push_back(curCharacter);
    } else if (isOpenParenthesis(curCharacter)) {
      op.push_back(curCharacter);
    } else if (isCloseParenthesis(curCharacter)) {
      while(!op.empty() && !isOpenParenthesis(op.back())) {
        cout << op.back();
        op.pop_back();
      }
      op.pop_back();
    }
  }

  while (!op.empty()) {
    cout << op.back();
    op.pop_back();
  }

  return;
}

bool isAlphabet(char i) {
  int temp = i - 'A';

  return temp < 26 && temp >= 0;
}

bool isPlusMinus(char i) { return i == '+' || i == '-'; }

bool isMultipleDivider(char i) { return i == '*' || i == '/'; }
bool isOpenParenthesis(char i) { return i == '('; }
bool isCloseParenthesis(char i) { return i == ')'; }
