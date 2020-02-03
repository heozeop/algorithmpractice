#include <iostream>
#include <algorithm>
using namespace std;

long long countFive(int n) {
    long long five = 0;
    for (long long i = 1; i <= n; i *= 5) {
        five += n / i;
    }
    return five;
}

long long countTwo(int n) {
    long long two = 0;
    for (long long i = 1; i <= n; i *= 2) {
        two += n / i;
    }
    return two;
}

int main(void) {
    long long n, m, k;
    cin >> n >> m;
    k = n - m;

    long long fiveResult = countFive(n) - countFive(m) - countFive(k);
    long long twoResult = countTwo(n) - countTwo(m) - countTwo(k);

    cout << min(fiveResult, twoResult);
    return 0;
}