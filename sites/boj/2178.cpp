#include <iostream>
#include <queue>
using namespace std;

const int MAXSIZE = 101;  
const int DEFAULTID = 10;
int map[MAXSIZE][MAXSIZE] = { 0, };
int row = 0, col = 0, ans = 0;
int drow[4] = { 0,1,0,-1 }, dcol[4] = {1,0,-1,0};
queue<pair<int, int>> line;

int main(void) {
    cin >> row >> col;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            char temp = 0;
            cin >> temp;
            map[i][j] = temp - '0';
        }
    }

    line.push(pair<int, int>(1, 1));
    map[1][1] = DEFAULTID;

    while (!line.empty()) {
        pair<int,int> now = line.front();
        line.pop();

        for (int i = 0; i < 4; i++) {
            int nextRow = now.first + drow[i];
            int nextCol = now.second + dcol[i];
            if (map[nextRow][nextCol] == 1) {
                map[nextRow][nextCol] = map[now.first][now.second] + 1;
                line.push(pair<int, int>(nextRow, nextCol));
            }
        }
    }
    cout << map[row][col] - DEFAULTID + 1;
}