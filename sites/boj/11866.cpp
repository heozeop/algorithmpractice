#include <iostream>
#include <vector>
using namespace std;

vector<int> value;

int main(void) {
  int n, k;
  cin >> n >> k;
  cout << "<";

  int i = 1;
  while (n--) {
    value.push_back(i++);
  }
  int now = k - 1;
  cout << value[now];
  value.erase(value.begin() + now);

  while (!value.empty()) {
    now = (now + k) % value.size() - 1;
    if (now < 0) {
      now = value.size() - 1;
    }
    cout << ", " << value[now];
    value.erase(value.begin() + now);
  }
  cout << ">";
}