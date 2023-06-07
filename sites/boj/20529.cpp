#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
const int MAX_N = 100000;

const char INFP[4] = {'I', 'N', 'F', 'P'};

int t, n;
int mbti[16];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> t;
  return;
}

int getDistance(int a, int b) {
  int c = a ^ b;
  int d = 0;
  for (int i = 0; i < 4; ++i) {
    if (1 << i & c) {
      d += 1;
    }
  }

  return d;
}

void solve() {

  while (t--) {
    cin >> n;
    string temp;
    memset(mbti, 0, sizeof(mbti));

    while (n--) {
      cin >> temp;
      int cur = 0;
      for (int i = 0; i < 4; ++i) {
        if (temp[i] == INFP[i]) {
          cur += 1 << i;
        }
      }

      mbti[cur] += 1;
    }

    if (n > 48) {
      cout << 0 << '\n';
      continue;
    }

    int minD = 9;
    for (int i = 0; i < 16; ++i) {
      if (!mbti[i]) {
        continue;
      }

      mbti[i] -= 1;
      for (int j = i; j < 16; ++j) {
        if (!mbti[j]) {
          continue;
        }

        mbti[j] -= 1;
        for (int k = j; k < 16; ++k) {
          if (!mbti[k]) {
            continue;
          }

          minD = min(minD,
                     getDistance(i, j) + getDistance(j, k) + getDistance(i, k));
        }
        mbti[j] += 1;
      }
      mbti[i] += 1;
    }

    cout << minD << '\n'; 
  }

  return;
}
