#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<vector<ll> > Matrix;

const int MODE_NUM = 1000000007;
const int MATRIX_SIZE = 2;

ll n;
int base[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597};

void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
}

Matrix multipleMatrix(Matrix& A, Matrix& B) {
  Matrix C(MATRIX_SIZE, vector<ll>(MATRIX_SIZE));
  for (int i = 0; i < MATRIX_SIZE; i++) {
    for (int j = 0; j < MATRIX_SIZE; j++) {
      for (int k = 0; k < MATRIX_SIZE; k++) {
        C[i][j] += A[i][k] * B[k][j];
        C[i][j] %= MODE_NUM;
      }
    }
  }
  return C;
}

Matrix getP(Matrix n, ll k) {
  Matrix temp;
  if(k == 1) return n;
  if(k % 2 == 1) {
    temp = getP(n, k - 1);
    return multipleMatrix(n, temp);
  }
  temp = getP(n, k / 2);
  return multipleMatrix(temp, temp);
}

ll fibonacci() {
  if(n < 18) {
    return base[n];
  }

  Matrix target(MATRIX_SIZE, vector<ll>(MATRIX_SIZE));
  target[0][0] = 1;
  target[0][1] = 1;
  target[1][0] = 1;
  target[1][1] = 0;

  Matrix result = getP(target, n - 1);
  return result[0][0];
}

void solve() {
  ll answer = fibonacci();

  cout << answer << endl;
}