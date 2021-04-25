#include <iostream>
using namespace std;

int n, k;
int main(void) {
    cin >> n >> k;

    int above = 1, below = 1;
    for (int i = 0; i < k; i++) {
        above *= (n - i);
        below *= (k - i);
    }

    cout << above / below;

    return 0;
}