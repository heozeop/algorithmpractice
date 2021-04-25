#include <iostream>
#include <cstring>
using namespace std;

const int MAXSIZE = 51;
const int DEFAULTID = 10;

int map[MAXSIZE][MAXSIZE] = { 0, };
int neededGilungYee = 0;
int col = 0, row = 0, k = 0;
int direction[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

bool setone(int x, int y, int id) {
    if (x < 0 || y < 0 || x >= row || y >= col || map[x][y] != 1) {
        return false;
    }

    if (map[x][y] == 1) {
        map[x][y] = id;
    }
    for (int i = 0; i < 4; i++) {
        int nextRow = x + direction[i][0];
        int nextCol = y + direction[i][1];

        setone(nextRow, nextCol, id);
    }
    return true;
}

void solve() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (setone(i, j, neededGilungYee + DEFAULTID)) {
                neededGilungYee++;
            }
        }
    }
}

int main(void) {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(map, 0, sizeof(int)*MAXSIZE*MAXSIZE);
        neededGilungYee = 0;

        cin >> col >> row >> k;

        for (int j = 0; j < k; j++) {
            int tempRow = 0, tempCol = 0;
            cin >> tempCol >> tempRow;
            map[tempRow][tempCol] = 1;
        }
        solve();
        cout << neededGilungYee << '\n';
    }
}