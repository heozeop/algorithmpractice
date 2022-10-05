/*
  문제: M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
  입력: 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.
  출력: 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
*/
/*
  소수 출력하기 -> 소수 판단하기 -> 
    루트n: 주어인 수 a를 판별하기 위해 필요한 연산은 루트 a, 이걸 1~100만까지 -> O(n루트n)
    아리스토테네스의 체: m ~ n까지 늘어놓고, 소수와 그 배수를 전부 삭제 <- root n은 써야 할 듯 하다.
    밀러-라빈 소수판별법: 페르마의 소정리 이용해 소수 판별, 이건 블로그로 써야할 듯
  소수의 정의 -> 자기자신과 자기 자신의 반수(modulo연산의 덧셈)로만 나누어 떨어지는 셈
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

void input();
void solve();

int n, m;
bool isPrime[1000001];
const int millarRabinInt[] = {2, 7, 61};

int main(void) {
  input();
  solve();
  return 0;
}

bool isPrimeByRootN(int n) {
  if(n == 1) {
    return false;
  }
  int rootedValue = floor(sqrt(n));

  for(int i = 2; i <= rootedValue; ++i) {
    if(n % i == 0) return false;
  }

  return true;
}

int fastPow(int a, int k, int mod) {
  int result = 1; // k가 0
  a %= mod;

  while(k) {
    if(k % 2) {
      result = (result * a) % mod;
    }
    k /= 2;
    a = (a * a) % mod;
  }

  return result;
}

bool millarRabin(int n, int a) {
  if(a % n == 0) return true;

  int k = n - 1;
  while(1) {
    int modulatedA = fastPow(a, k, n);
    if(modulatedA == n - 1) {
      return true;
    }
    if (k % 2) {
      return (modulatedA == 1 || modulatedA == n-1);
    }

    k /= 2;
  }
}

bool isPrimeWithMillerRabin(int n) {
  n = n * 2 + 1;
  for(auto i : millarRabinInt) {
    if(!millarRabin(n, i)) {
      return false;
    }
  }

  return true;
}

void markAsPrime(int primeNum) {
  for(int i = 2; i * primeNum <= n; ++i) {
    isPrime[i * primeNum] = false;
  }
}

void printPrimeWithSieve() {
  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;

  for(int i = m; i <= n; ++i) {
    if(!isPrime[i]) continue;
    if(isPrimeByRootN(i)) {
      markAsPrime(i);
      printf("%d\n", i);
    }
  }
}

void printPrimeWithRootN() {
  for(int i = m; i <= n; ++i) {
    if(isPrimeByRootN(i)) {
      printf("\n%d", i);
    }
  }
}

void printPrimeWithMillerRabin() {
  for(int i = m; i <= n; ++i) {
    if(isPrimeWithMillerRabin(i)) {
      printf("\n%d", i);
    }
  }
}

void input() {
  cin >> m >> n;
  return;
}

void solve() {
  // printPrimeWithRootN();
  // printPrimeWithSieve();
  printPrimeWithMillerRabin();
  return;
}
