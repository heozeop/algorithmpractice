#include <iostream>

using namespace std;

int area[1025][1025];

void setDP(int i, int j, int tmp) {
  area[i][j] = tmp + area[i][j - 1] + area[i - 1][j] - area[i - 1][j - 1];
}

int getNofP(int a, int b, int c, int d) {
  return area[c][d] - area[c][b - 1] - area[a - 1][d] + area[a - 1][b - 1];
}

int main(void) {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int tmp;
      scanf("%d", &tmp);
      setDP(i, j, tmp);
    }
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d\n", getNofP(a, b, c, d));
  }
}