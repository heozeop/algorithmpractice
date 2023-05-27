#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

queue<int> value;
const string ops[6] = {"push", "pop", "front", "size", "empty", "back"};

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
    for (i = 0; i < 6; i++) {
      if (op == ops[i]) {
        break;
      }
    }

    switch (i) {
    case 0:
      cin >> val;
      value.push(val);
      break;
    case 1:
      if (value.empty()) {
        cout << -1 << '\n';
        break;
      }

      cout << value.front() << '\n';
      value.pop();
      break;
    case 2:
      if (value.empty()) {
        cout << -1 << '\n';
        break;
      }
      cout << value.front() << '\n';
      break;
    case 3:
      cout << value.size() << '\n';
      break;
    case 4:
      cout << value.empty() << '\n';
      break;
    case 5:
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