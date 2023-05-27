#include <iostream>
using namespace std;

int n;
int rings[100];

int gcd(int a, int b) {
  int temp;
  if (a < b) {
    temp = a;
    a = b;
    b = temp;
  }

  while (a % b > 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return b;
}

int main(void) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> rings[i];
  }

  for (int i = 1; i < n; i++) {
    int tempGCD = gcd(rings[0], rings[i]);
    cout << rings[0] / tempGCD << "/" << rings[i] / tempGCD << '\n';
  }
}