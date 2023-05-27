#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> sumOfPrimeNumbers;
int n;

void input();
bool isPrime(int n);
void findPrimes();
void solve();

int main(void) {
  cin.sync_with_stdio(false);

  input();
  findPrimes();
  solve();
  return 0;
}

void input() { cin >> n; }

bool isPrime(int n) {
  int rootVal = sqrt(n);
  for (int i = 2; i <= rootVal; ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

void findPrimes() {
  sumOfPrimeNumbers.push_back(0);
  int prevSum = 0;
  for (int i = 2; i <= n; ++i) {
    if (isPrime(i)) {
      sumOfPrimeNumbers.push_back(prevSum + i);
      prevSum += i;
    }
  }
}

void solve() {
  int left = 0, right = 1;
  int curSum;
  int count = 0;
  while (left < right && right < sumOfPrimeNumbers.size()) {
    curSum = sumOfPrimeNumbers[right] - sumOfPrimeNumbers[left];
    if (curSum == n) {
      count += 1;
      left += 1;
      right += 1;
    } else if (curSum < n) {
      right += 1;
    } else {
      left += 1;
    }
  }

  cout << count;
}