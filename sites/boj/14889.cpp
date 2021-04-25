#include <iostream>
#include <algorithm>
using namespace std;

const int MAXIMUM = 100000000;
const int STARTTEAMMEMBER = 1;
const int NOTSTARTTEAMMEMBER = 0;
int input[20][20];
int isUsed[20];
int n;

int getMinimun(int index, int times) {
    if (times == n / 2) {
        int sumOfStartTeam = 0;
        int sumOfLinkTeam = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if(isUsed[j] == STARTTEAMMEMBER && isUsed[i] == STARTTEAMMEMBER){
                    sumOfStartTeam += input[i][j];
                }
                else if(isUsed[j] == NOTSTARTTEAMMEMBER && isUsed[i] == NOTSTARTTEAMMEMBER){
                    sumOfLinkTeam += input[i][j];
                }
            }
        }
        
        return abs(sumOfLinkTeam - sumOfStartTeam);
    }

    int ans = MAXIMUM;
    for (int i = index+1; i < n; i++) {
        isUsed[i] = STARTTEAMMEMBER;
        ans = min(ans, getMinimun(i, times + 1));
        isUsed[i] = NOTSTARTTEAMMEMBER;
    }

    return ans;
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;

            if (i > j) {
                input[j][i] += tmp;
            }
            else {
                input[i][j] = tmp;
            }

        }
    }

    isUsed[0] = STARTTEAMMEMBER;
    cout << getMinimun(0, 1);
}