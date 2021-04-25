#include <iostream>
#include <algorithm>
using namespace std;

long long getLastNum(int n, long long* dp, int* stairs){
    for (int i = 3; i < n; i++) {
        int val1 = dp[i - 3] + stairs[i] + stairs[i - 1];
        int val2 = dp[i - 2] + stairs[i];

        dp[i] = val2 < val1 ? val1 : val2;
    }
    return dp[n - 1];
}

int main(void) {
    int stairs[500];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stairs[i];
    }

    long long dp1[500] = { stairs[0], stairs[0] + stairs[1], stairs[0] + stairs[2]};
    long long dp2[500] = { stairs[0], stairs[1], stairs[1] + stairs[2] };

    cout << max(getLastNum(n, dp1, stairs), getLastNum(n, dp2, stairs));
}