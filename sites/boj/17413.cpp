#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#include <string>

using namespace std;

void input();
void solve();

const int NOT_STARTED = -1;

string inputString;
bool isTagStart;
int wordStartIndex = NOT_STARTED;
void printInverseAndReset(int currentIndex);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  getline(cin, inputString);
  return;
}

void solve() {
  for(int i = 0; i < inputString.length(); ++i) {
    if(isTagStart) {
      if(inputString[i] == '>') {
        isTagStart = false;
      }

      cout << inputString[i];
      continue;
    }

    if(inputString[i] == '<') {
      if(wordStartIndex != NOT_STARTED) {
        printInverseAndReset(i); 
      }

      isTagStart = true;
      cout << inputString[i];
      continue;
    }

    if(inputString[i] == ' ') {
      printInverseAndReset(i);
      cout << ' ';
      continue;
    }

    if(wordStartIndex == NOT_STARTED) {
      wordStartIndex = i;
    }
  }

  if(wordStartIndex != NOT_STARTED) {
    printInverseAndReset(inputString.length());
  }

  return;
}

void printInverseAndReset(int currentIndex) {
  string strToReverse = inputString.substr(wordStartIndex, currentIndex - wordStartIndex);
  reverse(strToReverse.begin(), strToReverse.end());
  cout << strToReverse;
  wordStartIndex = NOT_STARTED;
  return;
}
