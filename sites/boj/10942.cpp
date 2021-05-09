#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

const int PALINDROME = 1;
const int NOT_PALINDROME = 0;
const int MAX_SIZE = 100001;

unordered_map<string, bool> dp;
int sequence[MAX_SIZE];

string genKey(int s, int e) {
  return "row" + to_string(s) + " col" + to_string(e);
}

bool isPalindrome(int s, int e) {
  if(s == e) {
    return true;
  }
  const string key = genKey(s, e);

  if(dp.count(key) != 0) {
    return dp[key];
  }

  if(e - s == 1 || isPalindrome(s + 1, e - 1)) {
    bool result = sequence[s] == sequence[e];
    dp.insert(make_pair(key, result));
    return result;
  }

  dp.insert(make_pair(key, false));
  return false;
}

int main(void) {
  int n, m;

  cin >> n;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &sequence[i]);
  }

  cin >> m;
  while(m--) {
    int s,e;
    scanf("%d %d", &s, &e);
    printf("%d\n", isPalindrome(s,e));
  }

  return 0;
}
