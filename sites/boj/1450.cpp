#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int n;
ll c;
ll costs[32];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0; 
}

void input() {
  cin >> n >> c;
  for(int i = 1; i <= n; ++i) {
    cin >> costs[i];
  }
}

void dfs(int start, int end, ll sum, vector<ll>& container) {
  if(sum > c) return;
  if(start > end) {
    container.push_back(sum);
    return;
  }

  dfs(start + 1, end, sum + costs[start], container);
  dfs(start + 1, end, sum, container);
}

void solve() {
  vector<ll> frontChunk;
  vector<ll> backChunk;
  dfs(1, n/2, 0, frontChunk);
  dfs(n/2 + 1, n, 0, backChunk);

  sort(frontChunk.begin(), frontChunk.end());
  sort(backChunk.begin(), backChunk.end());

  ll count = 0;
  int left = 0, right = backChunk.size() - 1;
  for(int i = 0; i < frontChunk.size(); ++i) {
    while(right >= 0 && frontChunk[i] + backChunk[right] > c) {
      right -= 1;
    }
    count += right + 1;
  }
  cout << count;
}