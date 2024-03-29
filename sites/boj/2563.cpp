#include <iostream>

using namespace std;

int points[110][110];

void setArea(int x, int y) {
    for (int i = x; i < x + 10 && i < 100; i++) {
        for (int j = y; j < y + 10 && j < 100; j++) {
            points[i][j]++;
        }
    }
}

// 각 상자의 왼쪽 모서리 좌표를 입력받음. 100개라서 cin사용
void getPoints(int N) {
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        setArea(a, b);
    }
}

int getBlackArea() {
    int answer = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (points[i][j] != 0)
                answer++;
        }
    }
    return answer;
}

int main()
{
    int N;
    cin >> N;
    
    getPoints(N);

    cout << getBlackArea();
}