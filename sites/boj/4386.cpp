#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<float, float> pdd;
typedef pair<float, pair<int,int> > pfii;

pdd stars[101];
int links[101];
int length[101];
int n;
priority_queue<pfii, vector<pfii>, greater<pfii> > q;

void input();
void solve();
float calcDistance(int, int);
int find(int);
int merge(int,int);

int main(void) {
  input();
  solve();
  return 0;
}

void input() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    scanf("%f %f", &stars[i].first, &stars[i].second);
    links[i] = i;
    length[i] = 1;
  }
  return;
}

void solve() {
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      q.push(make_pair(calcDistance(i,j), make_pair(i,j)));
    }
  }

  float minD = 0.0f;
  int curLength = 0;
  pfii temp;
  while(!q.empty() && curLength < n) {
    temp = q.top();
    q.pop();
    curLength = merge(temp.second.first, temp.second.second);
    if(curLength != -1) {
      minD += temp.first;
    }
  }

  printf("%.2f", minD);
  return;
}

float calcDistance(int a, int b) {
  float x = (stars[a].first - stars[b].first);
  float y = (stars[a].second - stars[b].second);

  return sqrt(x * x + y * y);
}

int find(int a) {
  if(links[a] == a) {
    return a;
  }

  return links[a] = find(links[a]);
}

int merge(int a, int b) {
  int ap = find(a);
  int bp = find(b);

  if(ap != bp) {
    links[ap] = bp;
    length[ap] += length[bp];
    return length[ap];
  }

  return -1;
}