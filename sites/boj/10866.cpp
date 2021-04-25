#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> value;
const string ops[8] = { "push_front", "push_back","pop_front", "pop_back", "front", "size", "empty", "back" };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    long long n = 0;
    cin >> n;
    while (n--) {
        int val;
        string op;
        cin >> op;

        int i;
        for (i = 0; i < 8; i++) {
            if (op == ops[i]) {
                break;
            }
        }

        switch (i) {
        case 0:
            cin >> val;
            value.push_front(val);
            break;
        case 1:
            cin >> val;
            value.push_back(val);
            break;
        case 2:
            if (value.empty()) {
                cout << -1 << '\n';
                break;
            }

            cout << value.front() << '\n';
            value.pop_front();
            break;
        case 3:
            if (value.empty()) {
                cout << -1 << '\n';
                break;
            }

            cout << value.back() << '\n';
            value.pop_back();
            break;
        case 4:
            if (value.empty()) {
                cout << -1 << '\n';
                break;
            }

            cout << value.front() << '\n';
            break;
        case 5:
            cout << value.size() << '\n';
            break;
        case 6:
            cout << value.empty() << '\n';
            break;
        case 7:
            if (value.empty()) {
                cout << -1 << '\n';
                break;
            }
            cout << value.back() << '\n';
            break;
        }
    }
    return 0;
}