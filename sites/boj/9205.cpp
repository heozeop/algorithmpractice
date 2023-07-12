#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int,int> pii;
const string HAPPY = "happy";
const string SAD = "sad";

int t;

void input();
void solve();
int distance(pii,pii);
bool backtrack(int cur, pii end, vector<bool>& visited, vector<pii>& convinient);

int main(void) {
  input();
  solve();
  return 0;
}

void input() { 
  cin >> t;
  return;
}

void solve() { 
  int n;
  vector<pii> convinient;
  pii home;
  pii festival;
  while(t--) {
    cin >> n;
    int a,b;
    cin >> a >> b;
    home = {a,b};
    for(int i = 0; i < n; ++i) {
      cin >> a >> b;
      convinient.push_back({a,b});
    }
    cin >> a >> b;
    festival = {a,b};

    if(distance(home, festival) <= 1000) {
      cout << HAPPY << '\n';
      convinient.clear();
      continue;
    }

    bool isMet = false;
    vector<bool> visited(n, false);
    queue<pii> q;
    q.push(home);
    while(!q.empty()) {
      pii temp = q.front();
      q.pop();

      if (distance(temp, festival) <= 1000) {
        isMet = true;
        break;
      }

      for(int i = 0; i < n;++i) {
        if(distance(temp, convinient[i]) > 1000) {
          continue;
            }

        if(visited[i]) {
          continue;
        }
        visited[i] = true;
        q.push(convinient[i]);
      }
    }

    if(isMet) {
      cout << HAPPY << '\n';
    } else {
      cout << SAD << '\n';
    }

    convinient.clear();
  }

  return;
}

int distance(pii first, pii last) {
  return abs(first.first - last.first) + abs(first.second - last.second);
}

