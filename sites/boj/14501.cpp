#include <iostream>
#include <algorithm>
using namespace std;

int cont[15][2];
int n;

int getBigest(int l, int value) {
    int comp = l + cont[l][0];
    if (comp > n)
        return 0;

    value += cont[l][1];
    int maxNum = value;

    for (int i = comp; i < n; i++) {
        maxNum = max(maxNum, getBigest(i, value));
    }

    return maxNum;
}

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cont[i][0] >> cont[i][1];
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer = max(getBigest(i, 0), answer);
    }
    cout << answer;
}