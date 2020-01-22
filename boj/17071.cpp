#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

const int DEFAULTID = 1000000;
const int MAXSIZE = 500001;
const int MAXTIME = 500001;
const int NOTVISITED = 0;

int points[MAXSIZE][2] = { 0, }; // 0은 지난시간, 1은 시간에 따른 k의 위치
queue<int> q;

int minExpectedTime = MAXTIME;

int getReachTime(int k, int t, int position) {
    double testX = (-2.0 * t - 1 + sqrt((2 * t + 1)*(2 * t + 1) + 8 * (position - k))) / 2;
    int testY = testX;
    if (testX >= 0 &&testY == testX) {
        return testY;
    }
    return MAXTIME;
}

void setPoints(int lastPosition, int position) {
    int time = points[lastPosition][0] - DEFAULTID + 1;
    if (points[position][0] == NOTVISITED) {
        points[position][0] = points[lastPosition][0] + 1;
        points[position][1] = points[lastPosition][1] + time;

        if (position > points[position][1]) {
            minExpectedTime = min(minExpectedTime, getReachTime(points[position][1], points[position][0] - DEFAULTID, position) + time);
        }
        q.push(position);
    }
}


int solve(int s, int k) {

    points[s][0] = DEFAULTID;
    points[s][1] = k;
    q.push(s);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if (points[now][1] >= MAXSIZE) {
            return -1;
        }

        if (now == points[now][1]) {
            return min(minExpectedTime, points[now][0] - DEFAULTID);
        }

        if (points[now][0] - DEFAULTID > minExpectedTime) {
            return minExpectedTime;
        }

        if (now * 2 < MAXTIME) {
            setPoints(now, now * 2);
        }
        if (now + 1 < MAXTIME) {
            setPoints(now, now + 1);
        }
        if (now - 1 >= 0) {
            setPoints(now, now - 1);
        }
    }
    
}

int main(void) {
    int s = 0, k = 0;
    cin >> s >> k;

    if (k >= MAXSIZE - 1) {
        cout << -1;
        return 0;
    }

    cout << solve(s, k);
    return 0;
}