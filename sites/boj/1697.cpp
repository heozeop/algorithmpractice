#include <iostream>
#include <queue>
using namespace std;

const int MAXSIZE = 100001;
const int DEFAULTID = 10;
int visited[MAXSIZE] = {
    0,
};
queue<int> q;
int start = 0, ending = 0;

int main(void) {
  cin >> start >> ending;

  q.push(start);
  visited[start] = DEFAULTID;
  while (!q.empty()) {
    int now = q.front();
    q.pop();

    if (now == ending)
      break;

    if (now * 2 < MAXSIZE && visited[now * 2] == 0) {
      visited[now * 2] = visited[now] + 1;
      q.push(now * 2);
    }
    if (now + 1 < MAXSIZE && visited[now + 1] == 0) {
      visited[now + 1] = visited[now] + 1;
      q.push(now + 1);
    }
    if (now - 1 >= 0 && visited[now - 1] == 0) {
      visited[now - 1] = visited[now] + 1;
      q.push(now - 1);
    }
  }

  cout << visited[ending] - DEFAULTID;
}