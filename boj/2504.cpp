#include <iostream>
#include <vector>
#include <string>
using namespace std;

string line;
vector<char> chars;
vector<pair<int, int>> stacks;

bool stackManage(char now) {
    int val = now == ')' ? 2 : 3;
    pair<int, int> nowVal = pair<int, int>(chars.size(), val);
    chars.pop_back();

    while(!stacks.empty() && stacks.back().first > nowVal.first) {
        nowVal.second *= stacks.back().second;
        stacks.pop_back();
    }
    if (stacks.empty()) {
        stacks.push_back(nowVal);
        return true;
    }

    if (stacks.back().first == nowVal.first) {
        stacks.back().second += nowVal.second;
    }
    else {
        stacks.push_back(nowVal);
    }
    return true;
}

int solve() {
    for (int now = 0; now < line.size(); now++) {
        char comp;
        switch (line.at(now)) {
        case '(':
        case '[':
            chars.push_back(line.at(now));
            break;
        case ')':
        case ']':
            comp = line.at(now) == ')' ? '(' : '[';
            if (chars.empty() || chars.back() != comp) {
                return 0;
            }
            if (!stackManage(line.at(now))) {
                return 0;
            }
            break;
        }
    }
    return stacks.empty() ? 0 : !chars.empty() ? 0 : stacks.back().second;
}

int main(void) {
    char temp;
    cin >> line;

    cout << solve();
}