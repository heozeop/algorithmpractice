#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> lineSegment;
const int LIMIT_LINE_SEGMENT_COUNT = 3001;

void input();
void solve();

int n;
lineSegment lineSegments[LIMIT_LINE_SEGMENT_COUNT];
int lineSegmentGroup[LIMIT_LINE_SEGMENT_COUNT];
int lineSegmentGroupSize[LIMIT_LINE_SEGMENT_COUNT];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> lineSegments[i].first.first >> lineSegments[i].first.second >> lineSegments[i].second.first >> lineSegments[i].second.second;
    lineSegmentGroup[i] = i;
  }
  return;
}

int ccw(pll a, pll b, pll c) {
  ll result = (b.first - a.first) * (c.second - b.second) - (c.first - b.first) * (b.second - a.second);
  
  if(result > 0) {
    return 1;
  }

  if(result < 0) {
    return -1;
  }

  return 0;
}

bool isSameGroup(lineSegment a, lineSegment b) {
  int one = ccw(a.first, a.second, b.first), two = ccw(a.first, a.second, b.second),
    three = ccw(b.first, b.second, a.first), four = ccw(b.first, b.second, a.second);

  if (one * two == 0 && three * four == 0) {
    pll at,bt,ct,dt;
    at = min(a.first, a.second);
    bt = max(a.first, a.second);
    ct = min(b.first, b.second);
    dt = max(b.first, b.second);
    return ct <= bt && at <= dt;
  }
  
  return (one * two <= 0) && (three * four <= 0);
}

int find(int a) {
  if(lineSegmentGroup[a] == a) {
    return a;
  }

  return lineSegmentGroup[a] = find(lineSegmentGroup[a]);
}

void merge(int a, int b) {
  int ap = find(a);
  int bp = find(b);
  lineSegmentGroup[bp] = ap;
}

void gatherGroup() {
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if(isSameGroup(lineSegments[i], lineSegments[j])) {
        merge(i, j);
      }
    }
  }
}

void printSizes() {
  int maxSize = 0, count = 0;
  for(int i = 0; i < n; i++) { 
    if(lineSegmentGroupSize[find(i)]++ == 0) {
      count++;
    }
  }

  for(int i = 0; i < n; i++) {
    maxSize = max(maxSize, lineSegmentGroupSize[i]);
  }

  cout << count << '\n' << maxSize;
}

void solve() {
  gatherGroup();
  printSizes();
  return;
}
