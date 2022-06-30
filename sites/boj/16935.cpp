#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

const int MAX_SIZE = 101;

int n, m, r;
int originMap[MAX_SIZE][MAX_SIZE];
int resultMap[MAX_SIZE][MAX_SIZE];

void beforeThreeFour() {
  int nextM = n;
  n = m;
  m = nextM;
}

int main(void) {
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void reMap() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      originMap[i][j] = resultMap[i][j];
    }
  }
}

void calcOne() {
  for (int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      resultMap[(n - i - 1) % n][j] = originMap[i][j];
    }
  }
}

void calcTwo() {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      resultMap[i][(m - j - 1) % m] = originMap[i][j];
    }
  }
}

void calcThree() {
  beforeThreeFour();

  for (int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      resultMap[j][(m - i - 1) % m] = originMap[i][j];
    }
  }
}

void calcFour() {
  beforeThreeFour();
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      resultMap[(n - j - 1) % n][i] = originMap[i][j];
    }
  }
}

void calcFive() {
  for(int i = 0; i < n/2; ++i) {
    for(int j = 0; j < m/2; ++j) {
      resultMap[i][m/2 + j] = originMap[i][j];
    }
  }
  for(int i = 0; i < n / 2; ++i) {
    for(int j = m/2; j < m; ++j) {
      resultMap[n/2 + i][j] = originMap[i][j];
    }
  }
  for(int i = n/2; i < n; ++i) {
    for(int j = m/2; j < m; ++j) {
      resultMap[i][j - m/2] = originMap[i][j];
    }
  }
  for(int i = n/2; i < n; ++i) {
    for(int j = 0; j < m/2; ++j) {
      resultMap[i-n/2][j] = originMap[i][j];
    }
  }
}

void calcSix() {
  for(int i = 0; i < n/2; ++i) {
    for(int j = 0; j < m/2; ++j) {
      resultMap[i + n/2][j] = originMap[i][j];
    }
  }
  for(int i = 0; i < n / 2; ++i) {
    for(int j = m/2; j < m; ++j) {
      resultMap[i][j - m/2] = originMap[i][j];
    }
  }
  for(int i = n/2; i < n; ++i) {
    for(int j = m/2; j < m; ++j) {
      resultMap[i - n/2][j] = originMap[i][j];
    }
  }
  for(int i = n/2; i < n; ++i) {
    for(int j = 0; j < m/2; ++j) {
      resultMap[i][j + m/2] = originMap[i][j];
    }
  }
}

void input() {
  cin >> n >> m >> r;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> originMap[i][j];
    }
  }
  return;
}

void solve() {
  int temp;
  for (int i = 0; i < r; ++i) {
    cin >> temp;
    switch(temp) {
    case 1:
      calcOne();
      break;
    case 2:
      calcTwo();
      break;
    case 3:
      calcThree();
      break;
    case 4:
      calcFour();
      break;
    case 5:
      calcFive();
      break;
    case 6:
      calcSix();
      break;
    }
    reMap();
  }

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cout << resultMap[i][j] << " ";
    }
    cout << '\n';
  }

  return;
}
