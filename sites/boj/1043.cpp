#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <set>

using namespace std;
const int WHO_KNOWS_THE_TRUTH = 0;

int n, m, t;
int arr[51][51];
int countList[51];
int nf[51];



void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> n >> m >> t;
  for(int i = 1; i <= n; ++i) {
    nf[i] = i;
  }

  int temp;
  for(int i = 1; i <= t; ++i) {
    cin >> temp;
    nf[temp] = WHO_KNOWS_THE_TRUTH;
  }

  return; 
}

int findParent(int a) {
  if(a != nf[a]) {
    return nf[a] = findParent(nf[a]);
  }

  return nf[a];
}

void join(int a, int b) {
  int na = findParent(a);
  int nb = findParent(b);

  if(na < nb) {
    nf[nb] = nf[na];
  } else{
    nf[na] = nf[nb];
  }
}

void solve() { 
  for(int i = 1; i <= m; ++i) {
    cin >> countList[i];
    for(int j = 1; j <= countList[i]; ++j) {
      cin >> arr[i][j];

      if(j == 1) {
        continue;
      }

      join(arr[i][1], arr[i][j]);
    }
  }

  int cur = m;
  for(int i = 1; i <= m; ++i) {
    for(int j = 1; j <= countList[i]; ++j) {
      if (findParent(nf[arr[i][j]]) == WHO_KNOWS_THE_TRUTH) {
        cur -= 1;
        break;
      }
    }
  }

  cout << cur;

  return; 
}
