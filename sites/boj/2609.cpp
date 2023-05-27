#include <iostream>
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;

  int small = n > m ? m : n;
  int big = n > m ? n : m;
  int remain = 0;

  do {
    remain = big % small;
    big = small;
    small = remain;
  } while (remain != 0);

  cout << big << '\n';

  cout << n * m / big;
}