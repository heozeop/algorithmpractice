#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

void input();
void solve();

ll n, k, possible = 1;
string numbers[16];
vector<pair<int, int>> remains;
int remainOnTens[101];
ll dp[1 << 15][101];

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  cin >> k;
  return;
}

int modString(string number) {
  int remain = 0;
  for (int i = 0; i < number.length(); i++) {
    remain *= 10;
    remain += (number[i] - '0');
    remain %= k;
  }

  return remain;
}

ll dfs(int path, int remain) {
  if (path == (1 << n) - 1)
    return remain % k == 0;
  if (dp[path][remain] != -1)
    return dp[path][remain];

  ll cur = 0;
  for (int i = 0; i < n; i++) {
    if (path & (1 << i))
      continue;
    int curRemain = remains[i].first;
    int length = remains[i].second;
    int nextRemain = (remain * remainOnTens[length] + curRemain) % k;
    cur += dfs(path | (1 << i), nextRemain);
  }

  dp[path][remain] = cur;
  return dp[path][remain];
}

ll getGCD(long long sum, long long total) {
  long long r1 = total, r2 = sum, r;

  while (r2) {
    r = r1 % r2;
    r1 = r2;
    r2 = r;
  }

  return r1;
}

void solve() {
  for (int i = 0; i < n; i++) {
    int remain = modString(numbers[i]);
    remains.push_back({remain, numbers[i].length()});
    possible *= (i + 1);
  }

  remainOnTens[0] = 1 % k;
  for (int i = 1; i <= 50; i++) {
    remainOnTens[i] = (remainOnTens[i - 1] * 10) % k;
  }
  memset(dp, -1, sizeof(dp));
  long long sum = dfs(0, 0);
  long long gcd = getGCD(sum, possible);

  cout << sum / gcd << "/" << possible / gcd;
  return;
}
