#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

const int MAX_WEIGHT_SIZE = 31;
const int MAX_SIZE = 501;
const int UNCHECKABLE = 0;
const int CHECKABLE = 1;
const int UNKNOWN = -1;

int weights[MAX_WEIGHT_SIZE];
int dp[MAX_WEIGHT_SIZE][MAX_SIZE * MAX_WEIGHT_SIZE];
int sum;
int n;

bool isCheckable(int index, int weight) {
  const bool isConditionUnCheckable = index > n || weight > sum;
  if(isConditionUnCheckable) {
    return UNCHECKABLE;
  }

  if(dp[index][weight] != UNKNOWN) {
    return dp[index][weight];
  }

  const int conditions[] = { 
      abs(weight - weights[index]),
      weight + weights[index],
      weight
  };

  for(const int condition : conditions) {
    if(isCheckable(index + 1, condition)) {
      dp[index][weight] = CHECKABLE;
      return CHECKABLE;
    }
  }

  dp[index][weight] = UNCHECKABLE;
  return UNCHECKABLE;
}

int main(void) {
  memset(dp, UNKNOWN, sizeof(dp));

  cin >> n;
  for(int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    weights[i] = temp;
    dp[i][temp] = CHECKABLE;
    sum += temp;
  }

  int t;
  cin >> t;
  while(t--) {
    int temp;
    cin >> temp;

    if(isCheckable(0, temp)) {
      cout << "Y ";
    } else {
      cout << "N ";
    }
  }

  return 0;
}
