#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> types;
vector<int> nums;
int tc = 0;

int main(void) {
  cin >> tc;
  while (tc--) {
    int temp;
    cin >> temp;
    while (temp--) {
      string a, b;
      cin >> a >> b;

      bool inIt = true;
      for (int i = 0; i < types.size(); i++) {
        if (b == types[i]) {
          ++nums[i];
          inIt = false;
          break;
        }
      }
      if (inIt) {
        types.push_back(b);
        nums.push_back(1);
      }
    }

    int result = 1;
    for (int i = 0; i < nums.size(); i++) {
      result *= nums[i] + 1;
    }
    cout << result - 1 << endl;
    types.clear();
    nums.clear();
  }
  return 0;
}