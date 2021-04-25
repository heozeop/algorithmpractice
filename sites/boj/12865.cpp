#include <iostream>
#include <algorithm>
using namespace std;

const int MAXCOUNT = 101;
const int MAXWEIGHT = 1000001;

int v[MAXCOUNT] = { 0, };
int w[MAXCOUNT] = { 0, };
int n = 0, k = 0;

int dp[MAXWEIGHT][MAXCOUNT] = { 0, };

int main(void) {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (i < w[j]) {
                dp[i][j] = dp[i][j - 1];
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - w[j]][j - 1] + v[j]);
            }
        }
    }
    cout << dp[k][n];
}