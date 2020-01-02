#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int EMPTY = 0;

const pair<int,int> direction[4] = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};

int area[102][102];
pair<int, int> robots[101];
int robotDirections[101];
int a, b, n, m;

bool isCrash(int row, int col) {
    if (row > b || row < 1 || col < 1 || col > a)
        return true;
    return false;
}

int getDirection(char c) {
    switch (c) {
    case 'N':
        return 0;
    case 'E':
        return 1;
    case 'S':
        return 2;
    case 'W':
        return 3;
    }
}

void addRobot(int n) {
    for (int i = 1; i <= n; i++) {
        int x, y;
        char z;
        scanf(" %d %d %c", &x, &y, &z);
        robots[i] = pair<int, int>(y, x);
        area[y][x] = i;
        robotDirections[i] = getDirection(z);
    }
}

bool forwardOP(int idx) {
    int row = robots[idx].first + direction[robotDirections[idx]].first;
    int col = robots[idx].second + direction[robotDirections[idx]].second;

    if (isCrash(row, col)) {
        printf("Robot %d crashes into the wall\n", idx);
        return false;
    }
    else if (area[row][col] != EMPTY) {
        printf("Robot %d crashes into robot %d\n", idx, area[row][col]);
        return false;
    }

    area[robots[idx].first][robots[idx].second] = EMPTY;
    area[row][col] = idx;
    robots[idx].first = row;
    robots[idx].second = col;
    return true;
}

void trunLeftOP(int idx) {
    robotDirections[idx] = (robotDirections[idx] + 3) % 4;
}

void trunRightOP(int idx) {
    robotDirections[idx] = (robotDirections[idx] + 1) % 4;
}

bool execOP(int idx, char op, int repeat) {
    for (int j = 0; j < repeat; j++) {
        switch (op) {
        case 'L':
            trunLeftOP(idx);
            break;
        case 'R':
            trunRightOP(idx);
            break;
        case 'F':
            if (!forwardOP(idx)) // if false, fail on fowarding
                return false;
            break;
        }
    }
    return true;
}

int main(void) {
    cin >> a >> b >> n >> m;
    addRobot(n);
    for (int i = 0; i < m; i++) {
        int idx, repeat;
        char op;
        scanf(" %d %c %d", &idx, &op, &repeat);
        if (!execOP(idx, op, repeat)) { // if flase, the operation fail
            return 0;
        }
    }
    cout << "OK\n";
}