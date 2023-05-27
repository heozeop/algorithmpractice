#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

ll absoluting(ll x) {
  if (x < 0) {
    return x * -1;
  }
  return x;
}

class Compare {
public:
  bool operator()(ll a, ll b) {
    ll aAbs = absoluting(a);
    ll bAbs = absoluting(b);

    if (aAbs == bAbs) {
      return a > b;
    }

    return aAbs > bAbs;
  }
};

int main() {
  priority_queue<ll, vector<ll>, Compare> queue;

  int n;
  cin >> n;
  while (n-- > 0) {
    ll temp;
    scanf("%lld", &temp);

    if (temp != 0) {
      queue.push(temp);
      continue;
    }

    if (queue.empty()) {
      printf("%d\n", 0);
      continue;
    }

    printf("%lld\n", queue.top());
    queue.pop();
  }

  return 0;
}
