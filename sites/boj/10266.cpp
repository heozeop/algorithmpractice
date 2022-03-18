#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 200001;
const int MAX_RADIUS = 360000;

void input();
void solve();

int n;
int a[MAX], b[MAX];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  return;
}

vector<int> ff(vector<int> t) {
  int j = 0;
  vector<int> pi(t.size(), 0);
  for(int i = 1; i < t.size(); i++) {
    while(j > 0 && t[i] != t[j]) j = pi[j - 1];

    if(t[i] == t[j]) {
      pi[i] = ++j;
    }
  }

  return pi;
}

bool isPossible(vector<int> aa, vector<int>bb, vector<int> pi) {
  int j = 0;
  for(int i = 0 ; i < bb.size() ; i++) {
    aa.push_back(aa[i]);
  }
  for(int i = 0; i < aa.size(); ++i) {
    while(j > 0 && aa[i] != bb[j]) j = pi[j - 1];

    if(aa[i],bb[j]) {
      if(j == bb.size() - 1) {
        return true;
      }
      j++;
    }
  }

  return false;
}


void solve() {
  sort(&a[0], &a[n]);
  sort(&b[0], &b[n]);

  vector<int> ad;
  for(int i = 1; i < n; i++) {
    ad.push_back(a[i] - a[i-1]);
  }
  ad.push_back(a[0] - a[n - 1] + MAX_RADIUS);

  vector<int> bd;
  for(int i = 1; i < n; i++) {
    bd.push_back(b[i] - b[i-1]);
  }
  bd.push_back(b[0] - b[n - 1] + MAX_RADIUS);
  auto pi = ff(bd);

  if(isPossible(ad,bd,pi)) {
    cout << "possible";
  } else {
    cout << "impossible";
  }

  return;
}
