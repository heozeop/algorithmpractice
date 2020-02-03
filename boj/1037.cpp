#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    vector<int> v;
    cin >> n;
    while (n--) {
        int temp = 0;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    cout << v[0] * v[v.size() - 1];

    return 0;
}