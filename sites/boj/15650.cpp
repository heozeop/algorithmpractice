#include <iostream>
#include <vector>
using namespace std;

int n, m, visited[9];
vector<int> picked;
void findOne(int cnt, vector<int> picked) {
    if (cnt == m) {
        for (int i = 0; i < picked.size(); i++) {
            cout << picked[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int next = picked.size() == 0 ? 1 : picked.back() + 1;
    for (int i = next; i <= n; i++) {
        if (visited[i] == 0) {
            picked.push_back(i);
            visited[i] = 1;
            findOne(cnt + 1, picked);
            visited[i] = 0;
            picked.pop_back();
        }
    }
}

int main(void) {
    cin >> n >> m;
    findOne(0, picked);
    return 0;
}