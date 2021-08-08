#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 101;
const int MAX_COBINATION = 10001;

int n, m, sumOfCost;
int memory[MAX];
int cost[MAX];
int dp[MAX_COBINATION];

int initiateVariables(int* container, int maximum){ 
  int sum = 0;
  for(int i = 0; i < maximum; ++i) {
    cin >> container[i];
    sum += container[i];
  }
  return sum;
}

void setDP() {
  for(int i = 0 ; i < n; ++i) {
    for(int j = sumOfCost; j >= cost[i]; --j) {
      dp[j] = max(dp[j - cost[i]] + memory[i], dp[j]);
    }
  }
}

void printMinCost() {
  int i = 0;
  while(dp[i] < m) {
    ++i;
  }
  cout << i << endl;
}

int main(void) {
  cin >> n >> m;

  initiateVariables(memory, n);
  sumOfCost = initiateVariables(cost, n);
  setDP();
  printMinCost();
}
