#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

const int JUNGLE = 'J';
const int OCEAN = 'O';
const int ICE = 'I';

const int IDX_JUNGLE = 0;
const int IDX_OCEAN = 1;
const int IDX_ICE = 2;

int map[1001][1001][3];

void setMap(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      map[i][j][IDX_JUNGLE] = map[i][j - 1][IDX_JUNGLE] +
                              map[i - 1][j][IDX_JUNGLE] -
                              map[i - 1][j - 1][IDX_JUNGLE];
      map[i][j][IDX_OCEAN] = map[i][j - 1][IDX_OCEAN] +
                             map[i - 1][j][IDX_OCEAN] -
                             map[i - 1][j - 1][IDX_OCEAN];
      map[i][j][IDX_ICE] = map[i][j - 1][IDX_ICE] + map[i - 1][j][IDX_ICE] -
                           map[i - 1][j - 1][IDX_ICE];

      char n;
      scanf(" %c", &n);
      switch (n) {
      case JUNGLE:
        map[i][j][IDX_JUNGLE]++;
        break;
      case OCEAN:
        map[i][j][IDX_OCEAN]++;
        break;
      case ICE:
        map[i][j][IDX_ICE]++;
        break;
      }
    }
  }
}

void findGOI(int k) {
  for (int i = 0; i < k; i++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int jungle = 0, ocean = 0, ice = 0;
    jungle = map[c][d][IDX_JUNGLE] + map[a - 1][b - 1][IDX_JUNGLE] -
             map[a - 1][d][IDX_JUNGLE] - map[c][b - 1][IDX_JUNGLE];
    ocean = map[c][d][IDX_OCEAN] + map[a - 1][b - 1][IDX_OCEAN] -
            map[a - 1][d][IDX_OCEAN] - map[c][b - 1][IDX_OCEAN];
    ice = map[c][d][IDX_ICE] + map[a - 1][b - 1][IDX_ICE] -
          map[a - 1][d][IDX_ICE] - map[c][b - 1][IDX_ICE];
    printf("%d %d %d\n", jungle, ocean, ice);
  }
}

int main(void) {
  int k, n, m;
  cin >> n >> m >> k;
  setMap(n, m);

  findGOI(k);
}