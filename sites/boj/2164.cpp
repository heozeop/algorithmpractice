#include <deque>
#include <iostream>
using namespace std;

deque<int> value;

int main(void) {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    value.push_back(i);
  }

  while (value.size() > 1) {
    value.pop_front();
    value.push_back(value.front());
    value.pop_front();
  }
  cout << value.front();
  return 0;
}