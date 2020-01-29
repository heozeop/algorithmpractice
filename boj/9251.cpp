#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXSIZE = 1010;
int analisys[MAXSIZE][MAXSIZE] = { 0, };
char firstLine[MAXSIZE];
char secondLine[MAXSIZE];

int main(void) {
    cin >> firstLine >> secondLine;
    int n = strlen(secondLine), m = strlen(firstLine);

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) {
            if (firstLine[j-1] == secondLine[i-1]) {
                analisys[i][j] = max(analisys[i][j - 1], analisys[i - 1][j - 1] + 1);
            }
            else {
                analisys[i][j] = max(analisys[i][j - 1], analisys[i - 1][j]);
            }
        }
    }

    cout << analisys[n][m];
}