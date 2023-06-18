#include <iostream>
#include <vector>
using namespace std;
int mapData[10][10];

bool checkMap(int row, int col) {
  int dimensionX = row / 3 * 3;
  int dimensionY = col / 3 * 3;

  int areaNum[10] = {
      0,
  };
  int rowNum[10] = {
      0,
  };
  int colNum[10] = {
      0,
  };

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int areaVal = mapData[dimensionX + i][dimensionY + j];
      int rowVal = mapData[row][i * 3 + j];
      int colVal = mapData[i * 3 + j][col];

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

bool solve(int m, vector<pair<int, int>> &zeroLocation) {
  if (m == zeroLocation.size()) {
    return true;
  }

  for (int i = 1; i <= 9; i++) {
    int row = zeroLocation[m].first;
    int col = zeroLocation[m].second;

    mapData[row][col] = i;
    if (checkMap(row, col)) {
      if (solve(m + 1, zeroLocation)) {
        return true;
      }
    }
    mapData[row][col] = 0;
  }

  return false;
}

void printMap() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << mapData[i][j];
    }
    cout << '\n';
  }
}

int main(void) {
  vector<pair<int, int>> zeroLocation;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      char temp;
      cin >> temp;
      mapData[i][j] = temp - '0';

      if (mapData[i][j] == 0) {
        zeroLocation.push_back({i, j});
      }
    }
  }

  solve(0, zeroLocation);
  printMap();
}
