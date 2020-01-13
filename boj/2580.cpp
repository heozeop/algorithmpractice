#include <iostream>
#include <vector>
using namespace std;
int map[9][9];
vector<pair<int, int>> zeroLocation;

bool checkMap(int row, int col) {
    int dimensionX = row / 3 * 3;
    int dimensionY = col / 3 * 3;

    int areaNum[10] = { 0, };
    int rowNum[10] = { 0, };
    int colNum[10] = { 0, };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int areaVal = map[dimensionX + i][dimensionY + j];
            int rowVal = map[row][i * 3 + j];
            int colVal = map[i * 3 + j][col];

            colNum[colVal]++;
            rowNum[rowVal]++;
            areaNum[areaVal]++;
        }
    }
    for (int i = 1; i < 10; i++) {
        if (areaNum[i] > 1 || colNum[i] > 1 || rowNum[i] > 1)
            return false;
    }
    return true;
}

bool solve(int m) {
    if (m == zeroLocation.size()) {
        return true;
    }

    int row = zeroLocation[m].first;
    int col = zeroLocation[m].second;

    for (int i = 1; i <= 9; i++) {

        map[row][col] = i;
        if (checkMap(row, col)) {
            if (solve(m + 1))
                return true;
        }
    }

    map[row][col] = 0;
    return false;
}

int main(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                zeroLocation.push_back(pair<int, int>(i, j));
            }
        }
    }

    if (solve(0)) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << map[i][j] << " ";
            }
            cout << '\n';
        }
    }
}