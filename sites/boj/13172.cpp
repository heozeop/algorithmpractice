#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

const ll PRIME = 1000000007;

ll pow(ll a, ll b) {
  ll ans = 1;

  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= PRIME;
    }

    b /= 2;
    a = a * a % PRIME;
  }

  return ans;
}

ll m;
pair<ll, ll> arr[10001];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> m;

  int a, b;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    arr[i] = {a, b};
  }
  return;
}

void solve() {
  ll sum = 0;

  ll s, n, l;
  for (int i = 0; i < m; ++i) {
    n = arr[i].first;
    s = arr[i].second;

    l = pow(n, PRIME - 2);

    sum += l * s;

    sum %= PRIME;
  }

  if (sum < 0) {
    sum += PRIME;
  }

  cout << sum;

  return;
}
