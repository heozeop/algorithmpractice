#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int five = 0, two = 0;
    for (int i = 2; i <= n; i++) {
        int temp = i;
        while (!(temp % 5)) {
            five++;
            temp /= 5;
        }
        while (!(temp % 2)) {
            two++;
            temp /= 2;
        }
    }

    printf("%d\n", (two < five) ? two : five);
}