#include <iostream>
using namespace std;

int main(void) {
    int n = 0, m = 0;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        if (m%n == 0) {
            cout << "factor\n";
        }
        else if (n%m == 0) {
            cout << "multiple\n";
        }
        else {
            cout << "neither\n";
        }
    }
    return 0;
}