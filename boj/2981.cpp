#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long ns[100] = { 0, };
int n = 0;
vector<int> result;

long long gcd(long long big, long long small) {
    if (small == 0) {
        return big;
    }

    long long remain = 1;
    while (remain > 0) {
        remain = big % small;
        big = small;
        small = remain;
    }
    return big;
}

long long getMaxCommon() {
    long long maxCommon = gcd(ns[2] - ns[1], ns[1] - ns[0]);
    for (int i = 3; i < n; i++) {
        maxCommon = min(maxCommon, gcd(ns[i]- ns[i-1], maxCommon));
    }
    return maxCommon;
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ns[i];
    }

    sort(ns, ns + n);
    long long maxCommon = getMaxCommon();

    for (int i = 2; i * i <= maxCommon; i++) {
        if (maxCommon % i == 0) {
            result.push_back(i);
            result.push_back(maxCommon / i);
        }
    }
    result.push_back(maxCommon);

    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
}