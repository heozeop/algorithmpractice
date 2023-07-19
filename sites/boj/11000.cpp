#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;
void input();
void solve();

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;

  int s, e;
  for (int i = 0; i < n; ++i) {
    cin >> s >> e;
    v.push_back({s, e});
  }

  sort(v.begin(), v.end());

  return;
}

void solve() {
  priority_queue<int, vector<int>, greater<int>> lectureRoom;
  lectureRoom.push(0);
  int lectureRoomCount = 1;

  for (int i = 0; i < n; ++i) {
    lectureRoom.push(v[i].second);
    if (lectureRoom.top() <= v[i].first) {
      lectureRoom.pop();
    }
  }

  cout << lectureRoom.size();

  return;
}
