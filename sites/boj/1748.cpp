#include <iostream>
using namespace std;
unsigned long long thresh_hold[20] = {1, 10,100,1000,10000,100000,1000000,10000000,100000000, 1000000000};

long long getValue(long long N){
    long long answer = 0;
    for (int i = 1; ; i++) {
        if (thresh_hold[i] <= N) {
            answer += (thresh_hold[i] - thresh_hold[i - 1])*i;
        }
        else {
            answer += ((N - thresh_hold[i - 1] + 1) * i);
            break;
        }
    }
    return answer;
}

int main()
{
    long long N;
    cin >> N;
    long long answer = getValue(N);

    cout << answer;
}