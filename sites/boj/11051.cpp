#include <iostream>
using namespace std;

int n, k;
int dp[1000][1000];

int combination(int a, int b) {
    if (a == b || b == 0) {
        return 1;
    }

    if (dp[a][b] != 0)
        return dp[a][b];
        
    dp[a][b] = (combination(a - 1, b - 1)%10007 + combination(a - 1, b)%10007)%10007;
    return dp[a][b];
}

int main(void) {
    cin >> n >> k;

    cout << combination(n, k);

    return 0;
}