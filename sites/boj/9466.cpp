#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 100001;

int t, c;
int arr[MAX_N];
bool visited[MAX_N];
bool visited2[MAX_N];
bool isCycle[MAX_N];

void input();
void solve();
void init();
void findEnd(int currentIndex);
bool isThisCycle(int targetIndex, int currentIndex);
int countNoTeam();
void markSingleTeam();

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> t;
  return;
}

void solve() {
  while (t--) {
    init();

    cin >> c;
    for (int i = 1; i <= c; ++i) {
      cin >> arr[i];
    }

    markSingleTeam();
    for (int i = 1; i <= c; ++i) {
      if (visited[i]) {
        continue;
      }

      findEnd(i);
    }

    cout << countNoTeam() << '\n';
  }

  return;
}

void init() {
  fill(visited, visited + c + 1, false);
  fill(visited2, visited2 + c + 1, false);
  fill(isCycle, isCycle + c + 1, false);
}

void markSingleTeam() {
  for (int i = 1; i <= c; ++i) {
    if (i == arr[i]) {
      visited[i] = true;
      isCycle[i] = true;
    }
  }
}

void findEnd(int currentIndex) {
  if (visited[currentIndex]) {
    isThisCycle(currentIndex, currentIndex);
    return;
  }

  visited[currentIndex] = true;
  findEnd(arr[currentIndex]);
}

int countNoTeam() {
  int countOfNoTeamPerson = 0;
  for (int i = 1; i <= c; ++i) {
    if (!isCycle[i]) {
      countOfNoTeamPerson += 1;
    }
  }

  return countOfNoTeamPerson;
}

bool isThisCycle(int targetIndex, int currentIndex) {
  if (visited2[currentIndex]) {
    return targetIndex == currentIndex;
  }

  visited2[currentIndex] = true;
  int nextIndex = arr[currentIndex];
  return isCycle[currentIndex] = isThisCycle(targetIndex, nextIndex);
}
