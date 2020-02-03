#include <iostream>
#include <vector>
using namespace std;

vector<int> vals;
int k;

int main(void) {
    cin >> k;
    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        if (temp == 0) {
            vals.pop_back();
        }
        else {
            vals.push_back(temp);
        }
    }

    int ans = 0;
    for (int i = 0; i < vals.size(); i++) {
        ans += vals[i];
    }

    cout << ans;
    return 0;
}