#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int INDEX_LIMIT = 1000 + 1;

string first, second;
int dp[INDEX_LIMIT][INDEX_LIMIT];

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0; 
}

void input() {
  cin >> first >> second;
}

void solve() {
  for(int i = 1; i <= first.size(); ++i) {
    for(int j = 1; j <= second.size(); ++j) {
      if(first[i - 1] == second[j - 1]) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + 1);
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  int maxVal = dp[first.size()][second.size()];
  cout << maxVal << endl;
  if(maxVal == 0) {
    return;
  }

  vector<char> path;
  int n = first.size(), m = second.size();
  
  for(int i = n; i > 0; i--) {
    for(int j = m; j > 0; j--) {
      if(first[i - 1] == second[j - 1] && dp[i][j] == maxVal) {
        maxVal -= 1;
        path.push_back(first[i - 1]);
        m = j - 1;
        break;
      }
    }
  }

  for(int i = path.size() - 1; i >= 0; i--) {
    printf("%c", path[i]);
  }
  return;
}