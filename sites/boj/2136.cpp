#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> points;
int leftEnd, rightEnd, center;

void setPoints(int N, int L) {
  for (int i = 1; i <= N; i++) {
    int n;
    scanf("%d", &n);
    points.push_back(pair<int, int>(i, abs(n)));
    if (n < 0) {
      center++;
      rightEnd = -n > rightEnd ? -n : rightEnd;
    } else {
      leftEnd = (L - n) > leftEnd ? (L - n) : leftEnd;
    }
  }
}

pair<int, int> getLast() {
  if (leftEnd < rightEnd) {
    return pair<int, int>(points[center - 1].first, rightEnd);
  } else
    return pair<int, int>(points[center].first, leftEnd);
}

bool compare(pair<int, int> &a, pair<int, int> &b) {
  return abs(a.second) < abs(b.second);
}

int main(void) {
  long N, L;
  cin >> N >> L;

  setPoints(N, L);
  sort(points.begin(), points.end(), compare);

  pair<int, int> answer = getLast();
  cout << answer.first << " " << answer.second;
}