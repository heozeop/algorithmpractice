include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int QUEEN = 100;
const int EMPTY = 0;
const int NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3;
const int ROW = 0, COL = 1;

int map[20][20];
int n;
int numOfTrueCase = 0;
int direction[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

bool validate(int row, int col) {
    
    // À§ÂÊ
    for (int i = 0; i < row; i++) {
        if (map[i][col] != EMPTY)
            return false;
    }

    // ¿ÞÀ§
    for (int i = 1; i <= min(row, col); i++) {
        int nextRow = row + i * direction[NORTH][ROW];
        int nextCol = col + i * direction[WEST][COL];

        if (map[nextRow][nextCol] != EMPTY)
            return false;
    }

    // ¿ÀÀ§
    for (int i = 1; i <= min(n-col, row); i++) {
        int nextRow = row + i * direction[NORTH][ROW];
        int nextCol = col + i * direction[EAST][COL];

        if (map[nextRow][nextCol] != EMPTY)
            return false;
    }
    // ¿Þ
    for (int i = 1; i <= col; i++) {
        int nextRow = row + i * direction[WEST][ROW];
        int nextCol = col + i * direction[WEST][COL];

        if (map[nextRow][nextCol] != EMPTY)
            return false;
    }
    // ¿À
    for (int i = 1; i <= n - col; i++) {
        int nextRow = row + i * direction[EAST][ROW];
        int nextCol = col + i * direction[EAST][COL];

        if (map[nextRow][nextCol] != EMPTY)
            return false;
    }
    // ¾Æ·¡
    for (int i = 1; i <= n - row; i++) {
        int nextRow = row + i * direction[SOUTH][ROW];
        int nextCol = col + i * direction[SOUTH][COL];

        if (map[nextRow][nextCol] != EMPTY)
            return false;
    }
    // ¿Þ¾Æ 
    for (int i = 1; i <= min(col, n - row); i++) {
        int nextRow = row + i * direction[SOUTH][ROW];
        int nextCol = col + i * direction[WEST][COL];

        if (map[nextRow][nextCol] != EMPTY)
            return false;
    }
    // ¿ÀÀ§
    for (int i = 1; i <= min(n - col, n - row); i++) {
        int nextRow = row + i * direction[SOUTH][ROW];
        int nextCol = col + i * direction[EAST][COL];

        if (map[nextRow][nextCol] != EMPTY)
            return false;
    }
    return true;
}

void dfs(int hello, vector<pair<int, int>> location) {
    if (hello == n) {
        numOfTrueCase++;
        return;
    }

    int nextRow = location.size() == EMPTY ? 0 : location.back().first + 1;

    for (int j = 0; j < n; j++) {
        if (validate(nextRow, j)) {
            map[nextRow][j] = QUEEN;
            location.push_back(pair<int, int>(nextRow, j));
            dfs(hello + 1, location);
            location.pop_back();
            map[nextRow][j] = EMPTY;
        }
    }
}

int main(void) {
    cin >> n;
    vector<pair<int, int>> location;
    dfs(0, location);
    cout << numOfTrueCase;
    return 0;
}