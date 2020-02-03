#include <iostream>
#include <algorithm>
using namespace std;

const int MAXSIZE = 101;

pair<int, int> pairs[MAXSIZE];
int dp[MAXSIZE] = { 0, };
int n = 0;

int getLIS() {
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (pairs[j].second < pairs[i].second && dp[i] < dp[j]+1) {
                dp[i] = dp[j] + 1;
            }
        }

        if (maxVal < dp[i]) {
            maxVal = dp[i];
        }
    }
    return maxVal;
}

int getLeastNeedOfDeletion() {
    return n - getLIS();
}

bool compare(pair<int, int> a, pair<int, int>b) {
    return a.first < b.first;
}

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    sort(pairs, pairs + n, compare);
    cout << getLeastNeedOfDeletion();
}