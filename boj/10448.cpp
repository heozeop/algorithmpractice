#include <iostream>

using namespace std;

int a[1000];
int index;

void initialize(void) {
    int i = 1;
    do {
        a[index] = i * (i + 1) / 2;
        i++;
    } while (a[index++] < 1000);
}

bool isPossible(int m) {
    int iter = index - 1;
    int compare = a[iter];
    
    // compare가 m보다 작거나 같을때 까지 후퇴
    while (m < compare) {
        iter--;
        compare = a[iter];
    }

    for (int i = 0; i <= iter; i++) {
        for (int j = 0; j <= iter; j++) {
            for (int k = 0; k <= iter; k++) {
                int value = a[i] + a[j] + a[k];
                if (value == m)
                    return true;
            }
        }
    }
    return false;
}

int main(void) {
    initialize();
    int t, m;

    cin >> t;

    while (t-- != 0) {
        cin >> m;
        if (isPossible(m)) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
}