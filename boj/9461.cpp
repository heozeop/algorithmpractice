#include <iostream>
#include <vector>
using namespace std;

vector<long long> blue, white;

void setBandW() {
    blue.push_back(1);
    blue.push_back(1);
    blue.push_back(2);
    white.push_back(1);
    white.push_back(2);
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) 
            white.push_back(blue.back() + blue[blue.size() - 3]);
        else 
            blue.push_back(white.back() + white[white.size() - 3]);
    }
}

long long getNum(int n) {
    n--;
    if (n % 2 == 0)
        return blue[n / 2];
    else
        return white[n / 2];
}

int main(void) {
    int n;

    setBandW();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        cout << getNum(tmp) << '\n';
    }
    return 0;
}