#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <string>

using namespace std;
const int FAIL_FIND_NEXT_I = -1;
const char I = 'I';
const char O = 'O';

int n, m;
string ioi;

void input();
void solve();

int findNextIIndex(int from);
bool checkOI(int from);

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m >> ioi;
  return; 
}

void solve() { 
  int follower = findNextIIndex(0);
  int numberOfPn = 0;

  while(follower != FAIL_FIND_NEXT_I) {
    int pioneer = follower + 1;

    if (pioneer >= m) {
      break;
    }

    int numberOfIO = 0;
    for(; pioneer < m; pioneer += 2) {
      if(!checkOI(pioneer)) {
        break;    
      }

      numberOfIO += 1;

      if(numberOfIO == n) {
        numberOfPn += 1;
        numberOfIO -= 1;
        follower += 2;
      }
    }

    follower = findNextIIndex(pioneer);
  }

  cout << numberOfPn;

  return;
}

int findNextIIndex(int from) {
  int localFrom = from;
  while(localFrom < m) {
    if (ioi[localFrom] == I) {
      return localFrom;
    }

    localFrom += 1;
  }

  return FAIL_FIND_NEXT_I;
}

bool checkOI(int from) {
  if (from >= m) {
    return false;
  }

  if (ioi[from] != O) {
    return false;
  }

  if(ioi[from + 1] != I) {
    return false;
  }

  return true;
}

