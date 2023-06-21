#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_L = 15;

int l, c;
char characters[MAX_L];
char secret[MAX_L];

void input();
void solve();
void dfs(int currentLength, int currentIndex);
bool atLeastOneVowel();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> l >> c;
  for (int i = 0; i < c; ++i) {
    cin >> characters[i];
  }
  return;
}

void solve() {
  sort(characters, characters + c);
  dfs(0, 0);
  return;
}

void dfs(int currentLength, int currentIndex) {
  if (currentLength == l) {
    if (!atLeastOneVowel()) {
      return;
    }

    for (int i = 0; i < l; ++i) {
      cout << secret[i];
    }
    cout << '\n';
    return;
  }

  for (int i = currentIndex; i < c; ++i) {
    secret[currentLength] = characters[i];
    dfs(currentLength + 1, i + 1);
    secret[currentLength] = 0;
  }
}

bool atLeastOneVowel() {
  int numOfVowel = 0;
  int numOfConsonant = 0;
  for (int i = 0; i < l; ++i) {
    if (secret[i] == 'a' || secret[i] == 'e' || secret[i] == 'i' ||
        secret[i] == 'o' || secret[i] == 'u') {
      numOfVowel += 1;
    } else {
      numOfConsonant += 1;
    }
  }

  return numOfVowel > 0 && numOfConsonant > 1;
}
