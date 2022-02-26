#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int LIMIT_NODE_COUNT = 10001;
int n;
vector<int> tree[LIMIT_NODE_COUNT];
int weights[LIMIT_NODE_COUNT];
int dp[LIMIT_NODE_COUNT][2];
string dpPath[LIMIT_NODE_COUNT][2];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> weights[i];
  }
  int a,b;
  while(1) {
    cin >> a >> b;
    if(cin.fail()) break;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  return;
}

int findDp(int prev, int curr, bool selected) {
  if(dp[curr][selected] > 0) {
    return dp[curr][selected];
  }

  int sum = selected ? weights[curr] : 0;
  string s = selected ? to_string(curr) + " ": "";

  for(int i = 0; i < tree[curr].size(); i++) {
    if(tree[curr][i] == prev) continue;
    if(selected) {
      sum += findDp(curr, tree[curr][i], !selected);
      s += dpPath[tree[curr][i]][!selected];
    } else {
      int a = findDp(curr, tree[curr][i], !selected);
      int b = findDp(curr, tree[curr][i], selected);

      if(a > b) {
        sum += a;
        s += dpPath[tree[curr][i]][!selected];
      } else {
        sum += b;
        s += dpPath[tree[curr][i]][selected];
      }
    }
  }

  dpPath[curr][selected] = s;
  dp[curr][selected] = sum;
  return sum;
}

void printPathASC(string path) {
  vector<int> arr;
  stringstream ss(path);
  string temp;
  int tempI;

  while (getline(ss, temp, ' ')) {
    stringstream tempss(temp);
    tempss >> tempI;
    arr.push_back(tempI);
  }
  sort(arr.begin(), arr.end());
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
}

void solve() {
  int a = findDp(0, 1, true);
  int b = findDp(0, 1, false);

  if(a > b) {
    cout << a << '\n';
    printPathASC(dpPath[1][true]);
  } else {
    cout << b << '\n';
    printPathASC(dpPath[1][false]);
  }

  return;
}
