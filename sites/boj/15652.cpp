#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> picked;
void findOne(int cnt, vector<int> picked) {
  if (cnt == m) {
    for (int i = 0; i < picked.size(); i++) {
      cout << picked[i] << ' ';
    }
    cout << '\n';
    return;
  }

  int small = picked.size() == 0 ? 1 : picked.back();
  for (int i = small; i <= n; i++) {
    picked.push_back(i);
    findOne(cnt + 1, picked);
    picked.pop_back();
  }
}

int main(void) {
  cin >> n >> m;
  findOne(0, picked);
  return 0;
}